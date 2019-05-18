/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

/*static const tex_desc_t desc[] = {
    {TEX_GRASS, "res/texture/grass.png"},
    {TEX_WATER, "res/texture/water.jpg"},
    {TEX_VEG_GRASS1, "res/texture/veg/grass1.png"},
    {TEX_RED, "res/texture/red.png"},
    {TEX_WOOD, "res/texture/bois.jpg"},
    {TEX_NPC1, "res/model/veget/texture/pnj.jpg"},
    {TEX_METAL_RUST, "res/texture/metal_rust.jpg"},
    {TEX_METAL_BARE, "res/texture/metal_rust.jpg"},
    {0, NULL}
};*/

/*static void set_param_veg(gluint tex)
{
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
}

static void add_param(void)
{
    set_param_veg(_demo->tex[TEX_VEG_GRASS1]->id);
}*/

void tex_init(demo_t *demo)
{
    (void)demo;
    /*for (size_t i = 0; i < TEX_MAX; i++)
        demo->tex[i] = NULL;
    for (size_t i = 0; desc[i].path != NULL; i++)
        demo->tex[desc[i].tex] = texture2_load(desc[i].path);
    for (size_t i = 0; i < TEX_MAX; i++)
        if (demo->tex[i] == NULL) {
            printf("Can't load texture #%zu.\n", i);
            exit(84);
        }*/
    //add_param();
}

void tex_quit(demo_t *demo)
{
    (void)demo;
    /*for (size_t i = 0; i < TEX_MAX; i++)
        texture2_destroy(demo->tex[i]);*/
}

texture2* texture2_load(const char *path)
{
    (void)path;
    /*sfImage *image = sfImage_createFromFile(path);
    const uint8_t *pixels;
    texture2 *res;
    sfVector2u size;

    if (image == NULL)
        return NULL;
    pixels = sfImage_getPixelsPtr(image);
    size = sfImage_getSize(image);
    res = texture2_create(size.x, size.y);
    glGenTextures(1, &res->id);
    gl_set_texture_parameters(res->id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, res->w, res->h,
    0, GL_RGBA, GL_UNSIGNED_BYTE, (uint8_t*)pixels);
    sfImage_destroy(image);
    return res;*/
    return NULL;
}
