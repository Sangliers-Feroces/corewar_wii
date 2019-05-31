/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

void vec_texture_cluster_row_alloc_init(vec_texture_cluster_row_alloc *vec,
int32_t w)
{
    vec_texture_cluster_row_alloc_insert(vec, 0, w, 0);
    vec_texture_cluster_row_alloc_insert(vec, 0, 0, 0);
}

static texture_cluster_row_alloc get_alloc_struct(int32_t start, int32_t size)
{
    return (texture_cluster_row_alloc){0, start, size, 1,
    {{0.0f, 0.0f}, {0.0f, 0.0f}}};
}

texture_cluster_row texture_cluster_row_init(texture_cluster *cluster,
int32_t power)
{
    texture_cluster_row res = {power, cluster->to_fill_y, 0, {0, 0, NULL}};

    return res;
}

texture_cluster_row_alloc* vec_texture_cluster_row_alloc_insert(
vec_texture_cluster_row_alloc *vec, size_t pos, int32_t start, int32_t size)
{
    size_t cur = vec->count++;
    texture_cluster_row_alloc **new_vec;

    if (vec->count > vec->allocated) {
        vec->allocated += TEXTURE_CLUSTER_ROW_ALLOC_STEP;
        new_vec = (texture_cluster_row_alloc**)malloc_safe(
        vec->allocated * sizeof(texture_cluster_row_alloc*));
        for (size_t i = 0;
        i < vec->allocated - TEXTURE_CLUSTER_ROW_ALLOC_STEP; i++)
            new_vec[i] = vec->cluster_row[i];
        free(vec->cluster_row);
        vec->cluster_row = new_vec;
    }
    for (size_t i = cur; i > pos; i--)
        vec->cluster_row[i] = vec->cluster_row[i - 1];
    vec->cluster_row[pos] = (texture_cluster_row_alloc*)malloc_safe(
    sizeof(texture_cluster_row_alloc));
    *vec->cluster_row[pos] = get_alloc_struct(start, size);
    return vec->cluster_row[pos];
}

int texture_cluster_row_search(texture_cluster_row *row, ivec2 size,
int32_t *pres, int32_t *start)
{
    int32_t cur_end;

    for (size_t i = 0; i < (row->row_allocs.count - 1); i++) {
        cur_end = row->row_allocs.cluster_row[i]->start +
        row->row_allocs.cluster_row[i]->size;
        if (row->row_allocs.cluster_row[i + 1]->start - cur_end >=
        size.x + TEXTURE_ALLOC_MARGIN) {
            *pres = i + 1;
            *start = cur_end;
            row->to_lookup = *pres;
            return 1;
        }
    }
    return 0;
}
