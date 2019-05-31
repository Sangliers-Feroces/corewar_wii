/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** optiiiiiii rtx
*/

#include "headers.h"

octree* octree_create_node(octree *root, bounds3 bounds)
{
    octree *res = malloc_safe(sizeof(octree));

    res->root = root;
    for (size_t i = 0; i < 8; i++)
        res->sub[i] = NULL;
    res->triangles = vec_rtx_triangle_create();
    res->triangles->node = res;
    res->bounds = bounds;
    return res;
}

octree* octree_create(octree *root)
{
    octree *res = malloc_safe(sizeof(octree));

    res->root = root;
    for (size_t i = 0; i < 8; i++)
        res->sub[i] = NULL;
    res->triangles = vec_rtx_triangle_create();
    res->triangles->node = res;
    res->bounds = (bounds3){{0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}, 1.0f};
    return res;
}

void octree_destroy(octree **root)
{
    for (size_t i = 0; i < 8; i++)
        if ((*root)->sub[i] != NULL)
            octree_destroy(&((*root)->sub[i]));
    vec_rtx_triangle_destroy((*root)->triangles);
    free(*root);
    *root = NULL;
}
