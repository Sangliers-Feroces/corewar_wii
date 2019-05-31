/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static ssize2 get_off(size_t dim, size_t is_pos)
{
    ssize2 res = dim == 0 ? (ssize2){1, 0} : (ssize2){0, 1};

    if (!is_pos)
        res = ssize2_muls(res, -1);
    return res;
}

static void border_ter_fetch(chunk_border_t *res,
ssize2 pos, size_t dim, size_t is_pos)
{
    ssize2 off = get_off(dim, is_pos);
    ssize2 off_chunk =
    ssize2_muls(ssize2_add(pos, off), CHUNK_TERRAIN_SUB_SIZE);
    dvec3 voff =
    dvec3_init(off.x * CHUNK_SIZE_TERRAIN, 0.0, off.y * CHUNK_SIZE_TERRAIN);
    arr_dvec3_t *copy_arr;
    chunk_t **adj;

    chunk_try_load(off_chunk, NULL);
    adj = world_chunk2d_get(off_chunk);
    if ((adj == NULL) || (*adj == NULL))
        return;
    for (size_t i = 0; i < CHUNK_GEN_ITER; i++) {
        copy_arr = &(*adj)->border_ter.data[dim][!is_pos][i];
        res->data[dim][is_pos][i] = arr_dvec3_create(copy_arr->count);
        for (size_t j = 0; j < copy_arr->count; j++)
            res->data[dim][is_pos][i].dvec3[j] =
            dvec3_add(copy_arr->dvec3[j], voff);
    }
}

chunk_border_t chunk_border_ter_fetch(ssize2 pos)
{
    chunk_border_t res = chunk_border_init();

    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 2; j++)
            border_ter_fetch(&res, pos, i, j);
    return res;
}
