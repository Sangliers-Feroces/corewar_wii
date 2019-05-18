/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** various loaders : valid within a gl context
*/

#include "headers.h"

#define DEFAULT_FIFO_SIZE (256 * 1024)

u32 texture[1];   // Storage for one texture
void *boxList[5]; // Storage for the display lists
u32 boxSize[5];   // Real display list sizes
u32 xloop;        // Loop for x axis
u32 yloop;        // Loop for y axis

f32 xrot = 0.0f; // Rotates cube on the x axis
f32 yrot = 0.0f; // Rotates cube on the y axis

static GXColor lightColor[] = {
	{0xFF, 0xFF, 0x00,0xFF}, // Light color
	{0x10, 0x30, 0x40,0xFF}, // Ambient color
	{0xFF, 0xFF, 0xFF,0xFF}  // Mat color
};

void SetLight(GXColor color)
{
	//dvec3 dir = {1.0, -1.0, -2.0};
	GXLightObj lobj;

    /*dmat4 inv;
    dmat4_inv(_demo->world.camera->trans.world_rot, inv);
    dir = dvec3_normalize(dmat4_mul_dvec3(_demo->world.player->trans.world_rot, dir));*/

    //dvec3 p = dmat4_trans(_demo->world.camera->trans.world);
	//GX_InitLightPos(&lobj, -p.x, -p.y, -p.z);
	GX_InitLightColor(&lobj, color);
    //GX_InitLightDir(&lobj, dir.x, dir.y, dir.z);
    //GX_InitLightSpot(&lobj, 10.0, GX_SP_COS);
	GX_LoadLightObj(&lobj, GX_LIGHT0);

	// set number of rasterized color channels
	GX_SetNumChans(1);
	GX_SetChanCtrl(GX_COLOR0A0, GX_ENABLE, GX_SRC_REG, GX_SRC_REG, GX_LIGHT0, GX_DF_NONE, GX_AF_NONE);
	GX_SetChanAmbColor(GX_COLOR0A0, lightColor[1]);
	GX_SetChanMatColor(GX_COLOR0A0, color);
}

int BuildLists(GXTexObj texture) {
	// Make the new display list
	// For display lists, each command has an associated "cost" in bytes.
	// Add all these up to calculate the size of your display list before rounding up.
	// eke-eke says GX_Begin() costs 3 bytes (u8 + u16)
	// According to my research:
	// GX_Position3f32() is 12 bytes (f32*3)
	// GX_Normal3f32() is 12 bytes (f32*3)
	// GX_Color3f32() is actually 3 bytes ((f32 -> u8) * 3)
	// GX_TexCoord2f32() is 8 bytes (f32*2)
	// GX_End() seems to cost zero (there's no actual code in it)
	// Size -must- be multiple of 32, so (12*24) + (12*24) + (3*24) + (8*24) + 3 = 843
	// Rounded up to the nearest 32 is 864.
	// NOTE: Actual size may be up to 63 bytes -larger- than you calculate it to be due to padding and cache alignment.
	for (int i=0; i<5;i++) {
		boxList[i] = memalign(32,896);
		memset(boxList[i],0,896);
		DCInvalidateRange(boxList[i],896);
		GX_BeginDispList(boxList[i],896);
		GX_Begin(GX_QUADS,GX_VTXFMT0,24); // Start drawing
			// Bottom face
			GX_Position3f32(-1.0f,-1.0f,-1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
            GX_TexCoord2f32(1.0f,1.0f); // Top right
			GX_Position3f32( 1.0f,-1.0f,-1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
            GX_TexCoord2f32(0.0f,1.0f); // Top left
			GX_Position3f32( 1.0f,-1.0f, 1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
            GX_TexCoord2f32(0.0f,0.0f); // Bottom left
			GX_Position3f32(-1.0f,-1.0f, 1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
            GX_TexCoord2f32(1.0f,0.0f); // Bottom right
			// Front face
			GX_Position3f32(-1.0f,-1.0f, 1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			 GX_TexCoord2f32(0.0f,0.0f); // Bottom left
			GX_Position3f32( 1.0f,-1.0f, 1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			 GX_TexCoord2f32(1.0f,0.0f); // Bottom right
			GX_Position3f32( 1.0f, 1.0f, 1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			 GX_TexCoord2f32(1.0f,1.0f); // Top right
			GX_Position3f32(-1.0f, 1.0f, 1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			 GX_TexCoord2f32(0.0f,1.0f); // Top left
			// Back face
			GX_Position3f32(-1.0f,-1.0f,-1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			 GX_TexCoord2f32(1.0f,0.0f); // Bottom right
			GX_Position3f32(-1.0f, 1.0f,-1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			 GX_TexCoord2f32(1.0f,1.0f); // Top right
			GX_Position3f32( 1.0f, 1.0f,-1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			 GX_TexCoord2f32(0.0f,1.0f); // Top left
			GX_Position3f32( 1.0f,-1.0f,-1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			 GX_TexCoord2f32(0.0f,0.0f); // Bottom left
			// Right face
			GX_Position3f32( 1.0f,-1.0f,-1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			 GX_TexCoord2f32(1.0f,0.0f); // Bottom right
			GX_Position3f32( 1.0f, 1.0f,-1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			 GX_TexCoord2f32(1.0f,1.0f); // Top right
			GX_Position3f32( 1.0f, 1.0f, 1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			 GX_TexCoord2f32(0.0f,1.0f); // Top left
			GX_Position3f32( 1.0f,-1.0f, 1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			 GX_TexCoord2f32(0.0f,0.0f); // Bottom left
			// Left face
			GX_Position3f32(-1.0f,-1.0f,-1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			 GX_TexCoord2f32(0.0f,0.0f); // Bottom right
			GX_Position3f32(-1.0f,-1.0f, 1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			 GX_TexCoord2f32(1.0f,0.0f); // Top right
			GX_Position3f32(-1.0f, 1.0f, 1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			 GX_TexCoord2f32(1.0f,1.0f); // Top left
			GX_Position3f32(-1.0f, 1.0f,-1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			 GX_TexCoord2f32(0.0f,1.0f); // Bottom left
			// Top face
			GX_Position3f32(-1.0f, 1.0f,-1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			GX_TexCoord2f32(0.0f,1.0f); // Top left
			GX_Position3f32(-1.0f, 1.0f, 1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			GX_TexCoord2f32(0.0f,0.0f); // Bottom left
			GX_Position3f32( 1.0f, 1.0f, 1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			GX_TexCoord2f32(1.0f,0.0f); // Bottom rught
			GX_Position3f32( 1.0f, 1.0f,-1.0f); GX_Normal3f32((f32)0,(f32)0,(f32)1);
			GX_TexCoord2f32(1.0f,1.0f); // Top right
		GX_End();         // Done drawing quads
		// GX_EndDispList() returns the size of the display list, so store that value and use it with GX_CallDispList().
		boxSize[i] = GX_EndDispList(); // Done building the box list
		if (boxSize[i] == 0) return 1;
	}

	// setup texture coordinate generation
	// args: texcoord slot 0-7, matrix type, source to generate texture coordinates from, matrix to use

	// Set up TEV to paint the textures properly.
	GX_SetTevOp(GX_TEVSTAGE0,GX_MODULATE);
	GX_SetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);

	// Load up the textures (just one this time).
	GX_LoadTexObj(&texture, GX_TEXMAP0);

	return 0;
}

/*void DrawScene(void) {
	Mtx model,modelview; // Various matrices
	//guVector axis;                       // Axis to rotate on

	for (yloop = 0; yloop < 6; yloop++) { // Loop through the y plane
		for (xloop = 0; xloop < yloop; xloop++) { // Loop through the x plane
			// Position the cubes on the screen
			guMtxIdentity(model);

			axis.x = 1.0f;
			axis.y = 0;
			axis.z = 0;
			//guMtxRotAxisDeg(model,&axis,(45.0f-(2.0f*(float)yloop)+xrot)); // Tilt the cubes up and down

			axis.x = 0;
			axis.y = 1.0f;
			//guMtxRotAxisDeg(model,&axis,(45.0f+yrot)); // Spin cubes left and right

			guMtxTransApply(model,model, (float)yloop * 2.0f, xloop * 2.0, (float)xloop * 2.0f);

            GX_LoadNrmMtxImm(model, GX_PNMTX0);
			guMtxConcat(view,model,modelview);
			GX_LoadPosMtxImm(modelview, GX_PNMTX0);

			GX_CallDispList(boxList[yloop-1],boxSize[yloop-1]); // Draw the box
		}
	}
}*/

void init(void)
{
    srand(time(NULL));
    _demo->buf.msgs = vec_msg_entry_create();
	f32 yscale;
	u32 xfbHeight;
	GXTexObj texture;
	void *gpfifo = NULL;
	GXColor background = {0x00, 0x00, 0x00, 0xFF};
    _demo->buf.fb = 0;

	TPLFile cubeTPL;

	VIDEO_Init();
	WPAD_Init();
    PAD_Init();

	_demo->buf.rmode = VIDEO_GetPreferredMode(NULL);

	// allocate the fifo buffer
	gpfifo = memalign(32,DEFAULT_FIFO_SIZE);
	memset(gpfifo,0,DEFAULT_FIFO_SIZE);

	// allocate 2 framebuffers for double buffering
	_demo->buf.frameBuffer[0] = SYS_AllocateFramebuffer(_demo->buf.rmode);
	_demo->buf.frameBuffer[1] = SYS_AllocateFramebuffer(_demo->buf.rmode);

	// configure video
	VIDEO_Configure(_demo->buf.rmode);
	VIDEO_SetNextFramebuffer(_demo->buf.frameBuffer[_demo->buf.fb]);
	VIDEO_Flush();
	VIDEO_WaitVSync();
	if(_demo->buf.rmode->viTVMode & VI_NON_INTERLACE)
        VIDEO_WaitVSync();

	_demo->buf.fb ^= 1;

	// init the flipper
	GX_Init(gpfifo, DEFAULT_FIFO_SIZE);

	// clears the bg to color and clears the z buffer
	GX_SetCopyClear(background, 0x00FFFFFF);

	// other gx setup
	GX_SetViewport(0,0, _demo->buf.rmode->fbWidth, _demo->buf.rmode->efbHeight,0,1);
	yscale = GX_GetYScaleFactor(_demo->buf.rmode->efbHeight, _demo->buf.rmode->xfbHeight);
	xfbHeight = GX_SetDispCopyYScale(yscale);
	GX_SetScissor(0,0, _demo->buf.rmode->fbWidth, _demo->buf.rmode->efbHeight);
	GX_SetDispCopySrc(0,0, _demo->buf.rmode->fbWidth, _demo->buf.rmode->efbHeight);
	GX_SetDispCopyDst(_demo->buf.rmode->fbWidth, xfbHeight);
	GX_SetCopyFilter(_demo->buf.rmode->aa, _demo->buf.rmode->sample_pattern, GX_TRUE, _demo->buf.rmode->vfilter);
	GX_SetFieldMode(_demo->buf.rmode->field_rendering,((_demo->buf.rmode->viHeight==2*_demo->buf.rmode->xfbHeight )? GX_ENABLE : GX_DISABLE));

	if (_demo->buf.rmode->aa) {
		GX_SetPixelFmt(GX_PF_RGB565_Z16, GX_ZC_LINEAR);
	} else {
		GX_SetPixelFmt(GX_PF_RGB8_Z24, GX_ZC_LINEAR);
	}

	GX_SetCullMode(GX_CULL_BACK);
	GX_CopyDisp(_demo->buf.frameBuffer[_demo->buf.fb],GX_TRUE);
	GX_SetDispCopyGamma(GX_GM_1_0);

	// setup the vertex attribute table
	// describes the data
	// args: vat location 0-7, type of data, data format, size, scale
	// so for ex. in the first call we are sending position data with
	// 3 values X,Y,Z of size F32. scale sets the number of fractional
	// bits for non float data.
	GX_ClearVtxDesc();
	GX_SetVtxDesc(GX_VA_POS, GX_DIRECT);
	GX_SetVtxDesc(GX_VA_NRM, GX_DIRECT);
	GX_SetVtxDesc(GX_VA_TEX0, GX_DIRECT);

	GX_SetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	GX_SetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
	GX_SetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);

	// set number of rasterized color channels
	GX_SetNumChans(1);

	//set number of textures to generate
	GX_SetNumTexGens(1);

	GX_InvVtxCache();
	GX_InvalidateTexAll();

	TPL_OpenTPLFromMemory(&cubeTPL, (void *)textures_tpl, textures_tpl_size);
	TPL_GetTexture(&cubeTPL, yoshi, &texture);
	// setup our camera at the origin
	// looking down the -z axis with y up

	// setup our projection matrix
	// this creates a perspective matrix with a view angle of 90,
	// and aspect ratio based on the display resolution

	if (BuildLists(texture)) { // Build the display lists
		exit(1);        // Exit if failed.
	}
    VIDEO_SetBlack(FALSE);
    GX_SetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GX_SetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    GX_SetAlphaUpdate(GX_TRUE);
    GX_SetColorUpdate(GX_TRUE);


	_demo->buf.xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(_demo->buf.rmode));

	// Initialise the console, required for printf
	console_init(_demo->buf.xfb, 20, 20, _demo->buf.rmode->fbWidth, _demo->buf.rmode->xfbHeight, _demo->buf.rmode->fbWidth * VI_DISPLAY_PIX_SZ);

	// Set up the video registers with the chosen mode
	VIDEO_Configure(_demo->buf.rmode);

	// Tell the video hardware where our display memory is
	VIDEO_SetNextFramebuffer(_demo->buf.xfb);

	// Make the display visible
	VIDEO_SetBlack(FALSE);

	// Flush the video register changes to the hardware
	VIDEO_Flush();

	// Wait for Video setup to complete
	VIDEO_WaitVSync();
	if(_demo->buf.rmode->viTVMode&VI_NON_INTERLACE)
        VIDEO_WaitVSync();
	
    _demo->win.w = _demo->buf.rmode->viWidth;
    _demo->win.h = _demo->buf.rmode->viHeight;
}

void quit(void)
{
    thread_quit();
}

static void gl_gen_ext(void)
{
    /*glGenRenderbuffers(1, &_demo->buf.hdr_depthbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, _demo->buf.hdr_depthbuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT,
    _demo->win.w, _demo->win.h);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
    GL_RENDERBUFFER, _demo->buf.hdr_depthbuffer);
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
    _demo->buf.hdr_render_texture, 0);
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1,
    _demo->buf.dist_texture, 0);
    glDrawBuffers(2, (glenum[]){GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1});
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    _demo->buf.msgs = vec_msg_entry_create();*/
}

void gl_gen(demo_t *demo)
{
    demo->buf.to_draw = vec_render_call_init();
    /*glGenFramebuffers(1, &_demo->buf.hdr_framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, _demo->buf.hdr_framebuffer);
    glGenTextures(1, &_demo->buf.hdr_render_texture);
    glBindTexture(GL_TEXTURE_2D, _demo->buf.hdr_render_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, _demo->win.w, _demo->win.h, 0,
    GL_RGBA, GL_FLOAT, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glGenTextures(1, &_demo->buf.dist_texture);
    glBindTexture(GL_TEXTURE_2D, _demo->buf.dist_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, _demo->win.w, _demo->win.h, 0,
    GL_RGBA, GL_FLOAT, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);*/
    gl_gen_ext();
}

void gl_delete(demo_t *demo)
{
    vec_render_call_destroy(demo->buf.to_draw);
    vec_msg_entry_destroy(&_demo->buf.msgs);
}
