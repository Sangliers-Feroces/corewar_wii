/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

float vec2_norm(vec2 vec)
{
    return sqrtf((vec.x * vec.x) + (vec.y * vec.y));
}

float vec2_dist(vec2 a, vec2 b)
{
    return vec2_norm(vec2_sub(a, b));
}

int vec2_eq(vec2 a, vec2 b)
{
    return (a.x == b.x) && (a.y == b.y);
}
