/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

ivec2 get_texture_dim(vec2 *uv)
{
    vec2 min;
    vec2 max;
    vec2 dim;
    float scale = 2.0f;

    min = vec2_min(vec2_min(uv[0], uv[1]), uv[2]);
    max = vec2_max(vec2_max(uv[0], uv[1]), uv[2]);
    dim = vec2_sub(max, min);
    for (size_t i = 0; i < 3; i++)
        uv[i] = vec2_div(vec2_sub(uv[i], min), dim);
    return (ivec2){dim.x * scale, dim.y * scale};
}

texture2f_binding texture2f_binding_create(dvec3 *triangle)
{
    texture2f_binding res = {.texture = _lightmaps.base, .alloc = NULL};

    res.uv[0] = (vec2){0.0f, 0.0f};
    res.uv[1] = (vec2){dvec3_dist(triangle[0], triangle[1]), 0.0f};
    res.uv[2] = circle_intersect(
    (circle){res.uv[0], dvec3_dist(triangle[0], triangle[2])},
    (circle){res.uv[1], dvec3_dist(triangle[1], triangle[2])});
    if (!lightmap_allocate(get_texture_dim(res.uv), &res.alloc)) {
        printf("Can't allocate this lightmap. (out of GPU memory)\n");
        exit(84);
    }
    for (size_t i = 0; i < 3; i++)
        res.uv[i] = vec2_add(res.alloc->rect.p,
        vec2_mul(res.uv[i], res.alloc->rect.s));
    return res;
}

void texture2f_binding_destroy(texture2f_binding binding)
{
    texture2f_binding_free(binding);
}
