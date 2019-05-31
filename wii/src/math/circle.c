/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** cicle-circle intersection
*/

#include "headers.h"

static float square(float value)
{
    return value * value;
}

vec2 circle_intersect(circle a, circle b)
{
    float dist = sqrtf(square(b.c.x - a.c.x) + square(b.c.y - a.c.y));
    float dist_sq = dist * dist;
    float sum_rad_sq = a.r * a.r + b.r * b.r;
    float sub_rad_sq = a.r * a.r - b.r * b.r;
    float buf1 = sub_rad_sq / (2.0f * dist_sq);
    float buf2_inter = 2.0f * (sum_rad_sq / dist_sq) -
    (sub_rad_sq * sub_rad_sq) / (dist_sq * dist_sq) - 1.0f;
    float buf2;
    vec2 res = {0.0f, 0.0f};

    if (buf2_inter <= 0.0f)
        return res;
    buf2 = 0.5f * sqrtf(buf2_inter);
    res.x = 0.5f * (a.c.x + b.c.x) + buf1 * (b.c.x - a.c.x) +
    buf2 * (b.c.y - a.c.y);
    res.y = 0.5f * (a.c.y + b.c.y) + buf1 * (b.c.y - a.c.y) +
    buf2 * (a.c.x - b.c.x);
    return res;
}
