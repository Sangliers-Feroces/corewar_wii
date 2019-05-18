/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

vertex_t vertex_init(vec3 pos, vec3 normal, vec2 uv)
{
    vertex_t res;

    res.pos = pos;
    res.normal = normal;
    res.uv = uv;
    return res;
}
