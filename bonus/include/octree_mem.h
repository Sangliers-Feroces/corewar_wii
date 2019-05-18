/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** headers
*/

#pragma once

/* custom vector management */
/* defines how much do we allocate in advance for elements in octree */

#define OCTREE_ALLOC_STEP 8

#define SERIAL_OCTREE_SIZE (15)
// vertices + (uvs + texture ndx) + tangent space coords
#define SERIAL_VEC_RTX_TRIAGLE_SIZE (25)

size_t octree_serialize_get_size(octree *tree);
gpu_serial_t octree_serialize(octree *tree);

int32_t vec_rtx_triangle_serialize(vec_rtx_triangle *vec, gpu_serial_t *serial);
