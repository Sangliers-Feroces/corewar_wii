/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** optiiiiiii rtx
*/

#include "headers.h"

void octree_reset_lumels(octree *tree)
{
    (void)tree;
    texture2f_reset(_lightmaps.base);
}

float octree_get_max_lumel(octree *tree)
{
    (void)tree;
    return texture2f_get_max_lumel(_lightmaps.base);
}

void octree_update_lightmap(octree *tree, float max_lumel)
{
    (void)tree;
    (void)max_lumel;
}
