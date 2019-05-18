/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** optiiiiiii rtx
*/

#include "headers.h"

vec2 barycentric2_get_point(vec2 *triangle, dvec3 bar)
{
    return vec2_add(vec2_add(vec2_muls(triangle[0], bar.x),
    vec2_muls(triangle[1], bar.y)), vec2_muls(triangle[2], bar.z));
}
