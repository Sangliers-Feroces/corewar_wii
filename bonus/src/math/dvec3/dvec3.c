/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

dvec3 dvec3_add(dvec3 a, dvec3 b)
{
    return (dvec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

dvec3 dvec3_sub(dvec3 a, dvec3 b)
{
    return (dvec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

dvec3 dvec3_muls(dvec3 vec, double value)
{
    return (dvec3){vec.x * value, vec.y * value, vec.z * value};
}

dvec3 dvec3_divs(dvec3 vec, double value)
{
    return (dvec3){vec.x / value, vec.y / value, vec.z / value};
}

int dvec3_eq(dvec3 a, dvec3 b)
{
    return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}
