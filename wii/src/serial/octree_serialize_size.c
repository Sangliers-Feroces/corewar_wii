/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** serialization for the GPU
*/

#include "headers.h"

static size_t get_vec_rtx_triangle_size(vec_rtx_triangle *vec)
{
    return 1 + vec->count * SERIAL_VEC_RTX_TRIAGLE_SIZE;
}

static size_t get_size_actual(octree *tree, size_t size)
{
    if (tree == NULL)
        return size;
    size += SERIAL_OCTREE_SIZE;
    size += get_vec_rtx_triangle_size(tree->triangles);
    for (size_t i = 0; i < 8; i++)
        size = get_size_actual(tree->sub[i], size);
    return size;
}

size_t octree_serialize_get_size(octree *tree)
{
    return get_size_actual(tree, 16);
}
