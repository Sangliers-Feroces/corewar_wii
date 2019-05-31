/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

texture2_binding texture2_binding_create(dvec3 *triangle)
{
    texture2_binding res = {NULL, {{0.0f, 0.0f}, {1.0f, 0.0f}, {0.0f, 1.0f}}};

    (void)triangle;
    return res;
}

void texture2_binding_destroy(texture2_binding binding)
{
    (void)binding;
}
