/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

texture2* texture2_create(uint32_t w, uint32_t h)
{
    texture2 *res = (texture2*)malloc_safe(sizeof(texture2));

    res->size = (vec2){(float)w, (float)h};
    res->w = w;
    res->h = h;
    res->max_ndx = res->w * res->h;
    res->id = 0;
    return res;
}

void texture2_destroy(texture2 *texture)
{
    //if (texture->id != 0)
    //    glDeleteTextures(1, &texture->id);
    free(texture);
}

ivec2 texture2_get_nearest(vec2 p, vec2 size)
{
    p = vec2_mul(p, size);
    return (ivec2){p.x, p.y};
}

vec4 texture2f_sample(texture2f *texture, vec2 uv)
{
    ivec2 pos;
    ssize_t ndx;

    pos = texture2_get_nearest(uv, texture->size);
    ndx = pos.y * (ssize_t)texture->w + pos.x;
    if (!((ndx >= 0) && (ndx < (ssize_t)texture->max_ndx)))
        return (vec4){0.0f, 0.0f, 0.0f, 0.0f};
    return texture->pixel[ndx];
}
