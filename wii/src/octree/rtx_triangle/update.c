/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** optiiiiiii rtx
*/

#include "headers.h"

void lightmap_fill(rect_t rect, float value)
{
    ivec2 start = {rect.p.x * (float)_lightmaps.base->w,
    rect.p.y * (float)_lightmaps.base->h};
    ivec2 size = {rect.s.x * (float)_lightmaps.base->w,
    rect.s.y * (float)_lightmaps.base->h};
    vec4 to_fill = {value, value, value, 0.0f};

    for (int i = 0; i < size.y; i++)
        for (int j = 0; j < size.x; j++)
            _lightmaps.base->pixel[
            (start.y + i) * _lightmaps.base->w + (start.x + j)] = to_fill;
}
