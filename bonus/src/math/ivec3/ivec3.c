/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

ivec3 ivec3_add(ivec3 a, ivec3 b)
{
    return (ivec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

ivec3 ivec3_sub(ivec3 a, ivec3 b)
{
    return (ivec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

ivec3 ivec3_muls(ivec3 vec, int32_t value)
{
    return (ivec3){vec.x * value, vec.y * value, vec.z * value};
}

ivec3 ivec3_divs(ivec3 vec, int32_t value)
{
    return (ivec3){vec.x / value, vec.y / value, vec.z / value};
}

int ivec3_eq(ivec3 a, ivec3 b)
{
    return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}

ivec3 ivec3_init(int32_t x, int32_t y, int32_t z)
{
    return (ivec3){x, y, z};
}

dvec3 ivec3_dvec3(ivec3 src)
{
    return dvec3_init(src.x, src.y, src.z);
}
