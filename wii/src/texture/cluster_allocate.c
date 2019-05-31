/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

/* the texture is subdivided into rows of height 2^n */

texture_cluster_row_alloc* texture_cluster_insert_alloc(
texture_cluster *cluster, texture_cluster_alloc_info info,
int32_t pos, int32_t start)
{
    texture_cluster_row_alloc *res;

    res = vec_texture_cluster_row_alloc_insert(
    &cluster->rows.cluster_row[info.row].row_allocs, pos,
    start, info.size.x + TEXTURE_ALLOC_MARGIN);
    res->row = info.row;
    res->rect.p = (vec2){(float)start / (float)cluster->base->w,
    (float)cluster->rows.cluster_row[info.row].h / (float)cluster->base->h};
    res->rect.s = (vec2){(float)info.size.x / (float)cluster->base->w,
    (float)info.size.y / (float)cluster->base->h};
    return res;
}

static int try_allocate_on_row(texture_cluster *cluster,
texture_cluster_alloc_info info, texture_cluster_row_alloc **pres)
{
    int32_t pos;
    int32_t start;

    if (cluster->rows.cluster_row[info.row].power != info.power)
        return 0;
    if (!texture_cluster_row_search(&cluster->rows.cluster_row[info.row],
    info.size, &pos, &start))
        return 0;
    *pres = texture_cluster_insert_alloc(cluster, info, pos, start);
    return 1;
}

static int32_t get_power(int32_t x)
{
    int32_t res = 0;

    for (size_t i = 0; i < 32; i++)
        if (x & (1 << i))
            res = i;
    if ((1 << res) < x)
        res++;
    return res;
}

int texture_cluster_allocate(texture_cluster *cluster, ivec2 size,
texture_cluster_row_alloc **pres)
{
    int32_t power = get_power(size.y);

    if (power > 12)
        return 0;
    if (texture_cluster_alloc_try_fast_lookup(cluster, size, power, pres))
        return 1;
    for (size_t i = 0; i < cluster->rows.count; i++)
        if (try_allocate_on_row(cluster,
        (texture_cluster_alloc_info){i, power, size}, pres))
            return 1;
    if (!texture_cluster_add_row(cluster, power))
        return 0;
    return try_allocate_on_row(cluster,
    (texture_cluster_alloc_info){cluster->rows.count - 1, power, size}, pres);
}
