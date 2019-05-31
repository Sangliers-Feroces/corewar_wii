/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

vec2 vec2_add(vec2 a, vec2 b)
{
    return (vec2){a.x + b.x, a.y + b.y};
}

vec2 vec2_sub(vec2 a, vec2 b)
{
    return (vec2){a.x - b.x, a.y - b.y};
}

vec2 vec2_min(vec2 a, vec2 b)
{
    return (vec2){MIN(a.x, b.x), MIN(a.y, b.y)};
}

vec2 vec2_max(vec2 a, vec2 b)
{
    return (vec2){MAX(a.x, b.x), MAX(a.y, b.y)};
}

vec2 vec2_muls(vec2 vec, float value)
{
    return (vec2){vec.x * value, vec.y * value};
}
