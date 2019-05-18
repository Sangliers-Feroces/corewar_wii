/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** serialization for the GPU
*/

#include "headers.h"

static int32_t serialize_rec(octree *tree, gpu_serial_t *serial)
{
    int32_t res = serial->size;
    int32_t tri_pos;

    if (tree == NULL)
        return 0;
    serial->size += 8;
    gpu_serial_write_dvec3(serial, tree->bounds.min);
    gpu_serial_write_dvec3(serial, tree->bounds.max);
    tri_pos = serial->size++;
    serial->data[tri_pos] =
    vec_rtx_triangle_serialize(tree->triangles, serial);
    for (size_t i = 0; i < 8; i++)
        serial->data[res + i] = serialize_rec(tree->sub[i], serial);
    return res;
}

gpu_serial_t octree_serialize(octree *tree)
{
    gpu_serial_t res = {octree_serialize_get_size(tree), 16, NULL};

    res.data = malloc_safe(res.buf_size * sizeof(int32_t));
    for (size_t i = 0; i < 16; i++)
        res.data[i] = 0;
    serialize_rec(tree, &res);
    return res;
}
