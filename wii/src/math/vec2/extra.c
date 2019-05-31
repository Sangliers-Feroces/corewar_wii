/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

vec2 vec2_mul(vec2 a, vec2 b)
{
    return (vec2){a.x * b.x, a.y * b.y};
}

vec2 vec2_div(vec2 a, vec2 b)
{
    return (vec2){a.x / b.x, a.y / b.y};
}

vec2 vec2_divs(vec2 vec, float value)
{
    return (vec2){vec.x / value, vec.y / value};
}

vec2 vec2_adds(vec2 vec, float value)
{
    return (vec2){vec.x + value, vec.y + value};
}

vec2 vec2_subs(vec2 vec, float value)
{
    return (vec2){vec.x - value, vec.y - value};
}
