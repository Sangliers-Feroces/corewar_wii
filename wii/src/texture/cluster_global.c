/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

#include "global_shenanigans_vol.h"

void lightmap_init(void)
{
    _lightmaps = texture_cluster_create();
    lightmap_fill((rect_t){{0.0f, 0.0f}, {1.0f, 1.0f}}, _lightmaps.aperture);
    texture2f_refresh_gpu(_lightmaps.base);
}

void lightmap_quit(void)
{
    texture_cluster_destroy(_lightmaps);
}

int lightmap_allocate(ivec2 size, texture_cluster_row_alloc **pres)
{
    return texture_cluster_allocate(&_lightmaps, size, pres);
}
