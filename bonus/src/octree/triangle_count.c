/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** optiiiiiii rtx
*/

#include "headers.h"

static void get_triangle_count_actual(octree *tree, size_t *res)
{
    if (tree == NULL)
        return;
    for (size_t i = 0; i < 8; i++)
        get_triangle_count_actual(tree->sub[i], res);
    *res += tree->triangles->count;
}

size_t octree_get_rtx_triangle_count(octree *tree)
{
    size_t res = 0;

    get_triangle_count_actual(tree, &res);
    return res;
}
