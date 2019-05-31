/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

extern GXRModeObj *rmode;

extern u32 texture[1];   // Storage for one texture
extern void *boxList[5]; // Storage for the display lists
extern u32 boxSize[5];   // Real display list sizes
extern u32 xloop;        // Loop for x axis
extern u32 yloop;        // Loop for y axis

extern f32 xrot; // Rotates cube on the x axis
extern f32 yrot; // Rotates cube on the y axis

void DrawScene  ();
int  BuildLists (GXTexObj texture);
void SetLight(GXColor color);

static void move(int chan)
{
    u16 directions = PAD_ButtonsHeld(chan);
    (void)directions;
    s8 x = PAD_StickX(chan), y = PAD_StickY(chan);
    dvec3 cam_x = dvec3_muls(dmat4_mul_dvec3(_demo->world.camera->trans.world_rot,
    dvec3_init(1.0, 0.0, 0.0)), _demo->win.framelen);
    dvec3 cam_z = dvec3_muls(dmat4_mul_dvec3(_demo->world.camera->trans.world_rot,
    dvec3_init(0.0, 0.0, 1.0)), _demo->win.framelen);
    double x_ratio = (abs(x) > 16) ? ((double)x / 128.0) : 0.0;
    double y_ratio = (abs(y) > 16) ? ((double)y / 128.0) : 0.0;
    x_ratio *= 100.0;
    y_ratio *= 100.0;

    _demo->world.player->trans.pos = dvec3_add(_demo->world.player->trans.pos, dvec3_muls(cam_x, x_ratio));
    _demo->world.player->trans.pos = dvec3_add(_demo->world.player->trans.pos, dvec3_muls(cam_z, y_ratio));
    x = PAD_SubStickX(chan);
    y = PAD_SubStickY(chan);
    x_ratio = (abs(x) > 8) ? ((double)x / 128.0) : 0.0;
    y_ratio = (abs(y) > 8) ? ((double)y / 128.0) : 0.0;
    x_ratio *= 6.0;
    y_ratio *= 6.0;

    _demo->world.camera->trans.rot.x += y_ratio * _demo->win.framelen;
    _demo->world.player->trans.rot.y -= x_ratio * _demo->win.framelen;
    _demo->world.camera->trans.rot.x = CLAMP(_demo->world.camera->trans.rot.x, -M_PI / 2.0, M_PI / 2.0);
    //printf("%x: %d, %d\n", directions, PAD_StickX(0), PAD_StickY(0));
//_demo->world.player->trans.pos.z += 0.01;
}

void demo_poll_pad(void)
{
    WPAD_ScanPads();
    PAD_ScanPads();
    if(WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)
        exit(0);
    _demo->input.pad_prev = _demo->input.pad;
    _demo->input.pad = PAD_ButtonsHeld(0);
    _demo->input.pad_press = (~_demo->input.pad_prev) & _demo->input.pad;
}

void demo_switch_con(void)
{
	VIDEO_SetNextFramebuffer(_demo->buf.xfb);
	VIDEO_SetBlack(FALSE);
	VIDEO_Flush();
	VIDEO_WaitVSync();
	if(_demo->buf.rmode->viTVMode & VI_NON_INTERLACE)
        VIDEO_WaitVSync();
}

void demo_swap_buffers(void)
{
    GX_CopyDisp(_demo->buf.frameBuffer[_demo->buf.fb],GX_TRUE);

    GX_DrawDone();

    VIDEO_SetNextFramebuffer(_demo->buf.frameBuffer[_demo->buf.fb]);
    VIDEO_Flush();
    _demo->buf.fb ^= 1;
}

static void set_con_rev(int status)
{
    if (status) {
        printf("\x1b[30m");
        printf("\x1b[47m");
    } else {
        printf("\x1b[40m");
        printf("\x1b[37m");
    }
}

static void set_con_cur(int x, int y)
{
    printf("\x1b[%d;%dH", y, x);
}

static char* get_champ_path(const char *name)
{
    char *res = malloc_safe(strlen(name) + 64);
    const char *dir = "/apps/corewar/champions/";
    size_t ndx = 0;

    for (size_t i = 0; dir[i] != '\0'; i++)
        res[ndx++] = dir[i];
    for (size_t i = 0; name[i] != '\0'; i++)
        res[ndx++] = name[i];
    res[ndx++] = '\0';
    return res;
}

static int try_set_prog(prog_t *prog)
{
    for (size_t i = 0; i < 64; i++) {
        prog->pc = rand() % VM_SIZE;
        if (vm_set_prog(prog))
            return 1;
    }
    return 0;
}

static void add_champ(const char *name)
{
    char *path = get_champ_path(name);
    prog_t *to_add = prog_init();

    prog_read(to_add, path);
    free(path);
    if (_vm.progs.count == 0)
        to_add->id = 1;
    else
        to_add->id = _vm.progs.prog[_vm.progs.count - 1]->id + 1;
    if (!try_set_prog(to_add))
        return prog_destroy(to_add);
    vec_prog_add(&_vm.progs, to_add);
}

static void loop_champ(void)
{
    ssize_t cur = 0;
    size_t used = vm_get_used();

    demo_switch_con();
    while (1) {
        demo_poll_pad();
        if (_demo->input.pad_press & PAD_BUTTON_X)
            break;
        if (_demo->input.pad_press & PAD_BUTTON_UP)
            cur--;
        if (_demo->input.pad_press & PAD_BUTTON_DOWN)
            cur++;
        if (_demo->input.pad_press & PAD_BUTTON_B) {
            vm_clean();
            used = 0;
        }
        if (_demo->input.pad_press & PAD_BUTTON_A) {
            add_champ(_demo->champ_names.str[cur]);
            used = vm_get_used();
        }
        cur = CLAMP(cur, 0, (ssize_t)(_demo->champ_names.count - 1));
        set_con_cur(2, 2);
        set_con_rev(1);
        printf("CHAMPIONS:\n");
        for (size_t i = 0; i < _demo->champ_names.count; i++) {
            set_con_cur(2, 4 + i);
            set_con_rev(cur == (ssize_t)i);
            printf("%s", _demo->champ_names.str[i]);
        }
        set_con_cur(48, 2);
        set_con_rev(0);
        printf("A to unleash champion");
        set_con_cur(48, 3);
        printf("B to clean arena");
        set_con_cur(48, 5);
        printf("%u / %u bytes used", used, VM_SIZE);
		VIDEO_WaitVSync();
    }
}

static GXColor GXColor_add(GXColor color, u8 value)
{
    u8 *buf = (u8*)&color;

    for (size_t i = 0; i < 4; i++)
        buf[i] = MIN(buf[i] + value, 255);
    return color;
}

static void refresh_hl(void)
{
    for (size_t i = 0; i < VM_SIZE; i++)
        _vm.hl[i] = 0;
    for (size_t i = 0; i < _vm.progs.count; i++)
        if (_vm.progs.prog[i]->is_alive)
            _vm.hl[_vm.progs.prog[i]->op.pc % VM_SIZE] = 1;
}

static void render_vm(void)
{
    int32_t cur = 0;
    int cur_hl = 0;
    GXColor palette[9] = {
        {0xFF, 0x00, 0x00, 0xFF},
        {0x00, 0xFF, 0x00, 0xFF},
        {0xFF, 0xFF, 0x00, 0xFF},
        {0x00, 0x00, 0xFF, 0xFF},
        {0xFF, 0x00, 0xFF, 0xFF},
        {0x00, 0xFF, 0xFF, 0xFF},
        {0xFF, 0xFF, 0xFF, 0xFF},
        {0xD0, 0xD0, 0xD0, 0xFF},

        {0x80, 0x80, 0x80, 0xFF},
    };

    refresh_hl();
    SetLight(palette[8]);
    for (size_t i = 0; i < VM_SIZE; i++) {
        if ((_vm.owner[i] != cur) || (_vm.hl[i] != cur_hl) || _vm.hl[i]) {
            cur = _vm.owner[i];
            cur_hl = _vm.hl[i];
            SetLight(GXColor_add(palette[cur == 0 ? 8 : (cur % 8)], cur_hl ? 0xC0 : 0x00));
        }
        entity3_render(_demo->world.snake->sub.ent[i], _demo->cam.mvp.view);
    }
}

void demo_loop(demo_t *demo)
{
    (void)demo;

    //main_quest_start();
    world_load_map();
    //error_display("That is a typical error msg, taking up to 4MB OF VRAM. Please note this has nothing to do with you, now you can //reboot your system.");
    //for (size_t i = 0; i < 32; i++)
        //snake_set(ivec3_init(rand() % CUBE_SIZE, rand() % CUBE_SIZE, rand() % CUBE_SIZE), 1);
    /*
    FILE *file = fopen("test.txt", "w+");
    fputs("XDDDDD\n", file);
    fclose(file);
    error_display("%p\n", file);*/
    _vm = vm_init();
    vm_clean();
	while (1) {
        demo_poll_pad();
        if (_demo->input.pad_press & PAD_BUTTON_START)
            return;
        if (_demo->input.pad_press & PAD_BUTTON_X)
            loop_champ();
        move(0);

        world_update();
        refresh_vp(_demo);

        Mtx view;
        dmat4_Mtx(_demo->cam.mvp.view, view);
        //world_render();
        for (size_t i = 0; i < 5; i++)
            if (vec_prog_get_alive_count(&_vm.progs) > 1)
                vec_prog_run(&_vm.progs);
        render_vm();
        demo_swap_buffers();
		VIDEO_WaitVSync();
	}
    vm_destroy(&_vm);
}

static void jukebox(int start)
{
    if (start) {
        play_new_sound(SOUNDS_FOREST, 1, 80);
        play_new_sound(SOUNDS_WATER, 1, 50);
    } else {
        stop_sound(SOUNDS_FOREST);
        stop_sound(SOUNDS_WATER);
    }
}

int demo(arg_t args, int mode_dev)
{
    demo_t *demo = demo_init();

    (void)args;
    _iu.data.mode_dev = mode_dev;
    /*if (!start(demo)) {
        demo_quit(demo);
        return 0;
    }*/
    jukebox(1);
    while (1) {
        demo_loop(demo);
        if (demo->win.do_reboot) {
            demo_quit(demo);
            demo = demo_init();
        } else
            break;
    }
    jukebox(0);
    demo_quit(demo);
    return (0);
}
