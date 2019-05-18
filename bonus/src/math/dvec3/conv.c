/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

vec3 dvec3_vec3(dvec3 value)
{
    return (vec3){value.x, value.y, value.z};
}

dvec3 vec3_dvec3(vec3 value)
{
    return (dvec3){value.x, value.y, value.z};
}

dvec3 dvec3_init(double x, double y, double z)
{
    return (dvec3){x, y, z};
}

dvec3 dvec3_mul(dvec3 a, dvec3 b)
{
    return (dvec3){a.x * b.x, a.y * b.y, a.z * b.z};
}
