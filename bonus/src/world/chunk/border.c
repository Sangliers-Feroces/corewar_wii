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

static void border_fetch(chunk_border_t *res,
ssize2 pos, size_t dim, size_t is_pos)
{
    ssize2 off = get_off(dim, is_pos);
    ssize2 off_chunk = ssize2_add(pos, off);
    dvec3 voff =
    dvec3_init(off.x * CHUNK_SIZE, 0.0, off.y * CHUNK_SIZE);
    arr_dvec3_t *copy_arr;
    chunk_t **adj;

    chunk_try_load(off_chunk, NULL);
    adj = world_chunk2d_get(off_chunk);
    if ((adj == NULL) || (*adj == NULL))
        return;
    for (size_t i = 0; i < CHUNK_GEN_EXT_ITER; i++) {
        copy_arr = &(*adj)->border.data[dim][!is_pos][i];
        res->data[dim][is_pos][i] = arr_dvec3_create(copy_arr->count);
        for (size_t j = 0; j < copy_arr->count; j++)
            res->data[dim][is_pos][i].dvec3[j] =
            dvec3_add(copy_arr->dvec3[j], voff);
    }
}

chunk_border_t chunk_border_fetch(ssize2 pos)
{
    chunk_border_t res = chunk_border_init();

    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 2; j++)
            border_fetch(&res, pos, i, j);
    return res;
}

chunk_border_t chunk_border_init(void)
{
    chunk_border_t res;

    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 2; j++)
            for (size_t k = 0; k < CHUNK_GEN_ITER; k++)
                res.data[i][j][k] = (arr_dvec3_t){0, NULL};
    return res;
}

void chunk_border_destroy(chunk_border_t border)
{
    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 2; j++)
            for (size_t k = 0; k < CHUNK_GEN_ITER; k++)
                arr_dvec3_destroy(border.data[i][j][k]);
}
