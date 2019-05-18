/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void material_fun_skybox_world(dmat4 mvp, dmat4 world, dmat4 rot)
{
    shader_set(SHADER_SKYBOX, mvp, world, rot);
}

void material_fun_skybox_entity(dmat4 mvp, dmat4 world, dmat4 rot)
{
    shader_set(SHADER_SKYBOX, mvp, world, rot);
}
