/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

texture2f* texture2f_create(uint32_t w, uint32_t h)
{
    texture2f *res = (texture2f*)malloc_safe(sizeof(texture2f));

    res->size = (vec2){(float)(w - 1), (float)(h - 1)};
    res->w = w;
    res->h = h;
    res->max_ndx = res->w * res->h;
    res->pixel = (vec4*)malloc_safe(w * h * sizeof(vec4));
    res->id = 0;
    return res;
}

void texture2f_destroy(texture2f *texture)
{
    //if (texture->id != 0)
    //    glDeleteTextures(1, &texture->id);
    free(texture->pixel);
    free(texture);
}

void texture2f_reset(texture2f *texture)
{
    memset(texture->pixel, 0, texture->w * texture->h * sizeof(vec4));
}

static void write_color(texture2f *texture, ssize_t x, ssize_t y, dvec3 color)
{
    ssize_t ndx = y * (ssize_t)texture->w + x;
    vec4 *to_mod;
    vec4 actual_color = {color.x, color.y, color.z, 0.0f};

    if (!((ndx >= 0) && (ndx < (ssize_t)texture->max_ndx)))
        return;
    to_mod = &texture->pixel[ndx];
    *to_mod = vec4_add(*to_mod, actual_color);
}

void texture2f_write_color_bar(texture2f *texture, vec2 *uv, dvec3 bar,
dvec3 color)
{
    vec2 p = barycentric2_get_point(uv, bar);
    ivec2 pos;

    pos = texture2_get_nearest(p, texture->size);
    write_color(texture, pos.x, pos.y, color);
    write_color(texture, pos.x - 1, pos.y, dvec3_muls(color, 0.5f));
    write_color(texture, pos.x + 1, pos.y, dvec3_muls(color, 0.5f));
    write_color(texture, pos.x, pos.y - 1, dvec3_muls(color, 0.5f));
    write_color(texture, pos.x, pos.y + 1, dvec3_muls(color, 0.5f));
    write_color(texture, pos.x - 1, pos.y - 1, dvec3_muls(color, 0.33f));
    write_color(texture, pos.x + 1, pos.y - 1, dvec3_muls(color, 0.33f));
    write_color(texture, pos.x - 1, pos.y + 1, dvec3_muls(color, 0.33f));
    write_color(texture, pos.x + 1, pos.y + 1, dvec3_muls(color, 0.33f));
}
