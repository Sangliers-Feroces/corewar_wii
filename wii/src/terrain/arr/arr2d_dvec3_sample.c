/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

int arr2d_dvec3_is_coord_valid(arr2d_dvec3_t arr, ssize2 uv)
{
    return (uv.x >= 0) && (uv.x < (ssize_t)arr.w) &&
    (uv.y >= 0) && (uv.y < (ssize_t)arr.h);
}

dvec3 arr2d_dvec3_sample(arr2d_dvec3_t arr, ssize2 uv)
{
    if (arr2d_dvec3_is_coord_valid(arr, uv))
        return arr.dvec3[uv.y * arr.w + uv.x];
    else
        return dvec3_init(0.0, 0.0, 0.0);
}

dvec3 arr2d_dvec3_sample_linear(arr2d_dvec3_t arr, vec2 uv)
{
    vec2 uv_af = {(arr.w - 1) * uv.x, (arr.h - 1) * uv.y};
    ssize2 uv_a = {uv_af.x, uv_af.y};
    vec2 off = {uv_af.x - uv_a.x, uv_af.y - uv_a.y};
    double c = arr2d_dvec3_is_coord_valid(arr, uv_a) +
    arr2d_dvec3_is_coord_valid(arr, ssize2_add(uv_a, (ssize2){1, 0})) +
    arr2d_dvec3_is_coord_valid(arr, ssize2_add(uv_a, (ssize2){0, 1})) +
    arr2d_dvec3_is_coord_valid(arr, ssize2_add(uv_a, (ssize2){1, 1}));
    dvec3 p[4];

    if (c != 4)
        return arr2d_dvec3_sample(arr, uv_a);
    p[0] = arr2d_dvec3_sample(arr, uv_a);
    p[1] = arr2d_dvec3_sample(arr, ssize2_add(uv_a, (ssize2){1, 0}));
    p[2] = arr2d_dvec3_sample(arr, ssize2_add(uv_a, (ssize2){0, 1}));
    p[3] = arr2d_dvec3_sample(arr, ssize2_add(uv_a, (ssize2){1, 1}));
    return dvec3_interpolate(
    dvec3_interpolate(p[0], p[2], off.y), dvec3_interpolate(p[1], p[3], off.y),
    off.x);
}
