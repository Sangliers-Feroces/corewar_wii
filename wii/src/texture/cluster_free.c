/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

/* the texture is subdivided into rows of height 2^n */

static void vec_texture_cluster_row_free_alloc(texture_cluster_row *row,
texture_cluster_row_alloc *alloc)
{
    size_t ndx = ~0UL;

    for (size_t i = 0; i < row->row_allocs.count; i++)
        if (row->row_allocs.cluster_row[i] == alloc) {
            ndx = i;
            break;
        }
    if (ndx == ~0UL)
        return;
    free(alloc);
    row->row_allocs.count--;
    for (size_t i = ndx; i < row->row_allocs.count; i++)
        row->row_allocs.cluster_row[i] = row->row_allocs.cluster_row[i + 1];
}

static void texture_cluster_free_alloc(texture_cluster_row_alloc *alloc)
{
    size_t row = alloc->row;
    texture_cluster *cluster = &_lightmaps;

    vec_texture_cluster_row_free_alloc(&cluster->rows.cluster_row[row], alloc);
}

void texture2f_binding_free(texture2f_binding binding)
{
    if ((binding.texture == NULL) || (binding.alloc == NULL) ||
    (binding.alloc->shared_count == 0))
        return;
    binding.alloc->shared_count--;
    if (binding.alloc->shared_count == 0)
        texture_cluster_free_alloc(binding.alloc);
}
