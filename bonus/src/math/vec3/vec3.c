/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

vec3 vec3_add(vec3 a, vec3 b)
{
    return (vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

vec3 vec3_sub(vec3 a, vec3 b)
{
    return (vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

vec3 vec3_muls(vec3 vec, float value)
{
    return (vec3){vec.x * value, vec.y * value, vec.z * value};
}

vec3 vec3_divs(vec3 vec, float value)
{
    return (vec3){vec.x / value, vec.y / value, vec.z / value};
}

int vec3_eq(vec3 a, vec3 b)
{
    return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}
