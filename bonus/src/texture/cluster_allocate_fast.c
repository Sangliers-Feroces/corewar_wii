/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

/* the texture is subdivided into rows of height 2^n */

static int try_lookup_row(texture_cluster_row *row, ivec2 size,
int32_t *pres, int32_t *start)
{
    int32_t cur_end;
    size_t i = row->to_lookup;

    if (i + 1 >= row->row_allocs.count) {
        row->to_lookup = 0;
        return 0;
    }
    cur_end = row->row_allocs.cluster_row[i]->start +
    row->row_allocs.cluster_row[i]->size;
    if (row->row_allocs.cluster_row[i + 1]->start - cur_end >=
    size.x + TEXTURE_ALLOC_MARGIN) {
        *pres = i + 1;
        *start = cur_end;
        row->to_lookup = *pres;
        return 1;
    }
    return 0;
}

int texture_cluster_alloc_try_fast_lookup(texture_cluster *cluster,
ivec2 size, int32_t power, texture_cluster_row_alloc **pres)
{
    int32_t pos;
    int32_t start;

    for (size_t i = 0; i < cluster->rows.count; i++) {
        if (cluster->rows.cluster_row[i].power != power)
            continue;
        if (try_lookup_row(&cluster->rows.cluster_row[i], size,
        &pos, &start)) {
            *pres = texture_cluster_insert_alloc(cluster,
            (texture_cluster_alloc_info){i, power, size}, pos, start);
            return 1;
        }
    }
    return 0;
}
