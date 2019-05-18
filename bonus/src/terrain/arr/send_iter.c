/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void terrain_send_iter_to_ter_border(arr2d_dvec3_t arr, size_t ndx, ssize2 pos)
{
    ssize2 pos_first_chunk = ssize2_muls(pos, CHUNK_TERRAIN_SUB_SIZE);
    chunk_t *chunk = world_chunk_get_adv(pos_first_chunk, 0, 0);

    for (size_t i = 0; i < 2; i++) {
        chunk->border_ter.data[1][i][ndx] = arr_dvec3_create(arr.w);
        chunk->border_ter.data[0][i][ndx] = arr_dvec3_create(arr.h);
    }
    for (size_t i = 0; i < arr.h; i++) {
        chunk->border_ter.data[0][0][ndx].dvec3[i] = arr.dvec3[i * arr.w];
        chunk->border_ter.data[0][1][ndx].dvec3[i] =
        arr.dvec3[i * arr.w + arr.w - 1];
    }
    for (size_t i = 0; i < arr.w; i++) {
        chunk->border_ter.data[1][0][ndx].dvec3[i] = arr.dvec3[i];
        chunk->border_ter.data[1][1][ndx].dvec3[i] =
        arr.dvec3[(arr.h - 1) * arr.w + i];
    }
}

void terrain_send_iter_to_chunk_border(chunk_t *chunk, arr2d_dvec3_t arr,
size_t ndx)
{
    for (size_t i = 0; i < 2; i++) {
        chunk->border.data[1][i][ndx] = arr_dvec3_create(arr.w);
        chunk->border.data[0][i][ndx] = arr_dvec3_create(arr.h);
    }
    for (size_t i = 0; i < arr.h; i++) {
        chunk->border.data[0][0][ndx].dvec3[i] = arr.dvec3[i * arr.w];
        chunk->border.data[0][1][ndx].dvec3[i] =
        arr.dvec3[i * arr.w + arr.w - 1];
    }
    for (size_t i = 0; i < arr.w; i++) {
        chunk->border.data[1][0][ndx].dvec3[i] = arr.dvec3[i];
        chunk->border.data[1][1][ndx].dvec3[i] =
        arr.dvec3[(arr.h - 1) * arr.w + i];
    }
}

void terrain_apply_constraints(arr2d_dvec3_t arr, chunk_border_t border,
size_t ndx)
{
    if (border.data[0][0][ndx].count > 0)
        for (size_t i = 0; i < arr.h; i++)
            arr.dvec3[i * arr.w] = border.data[0][0][ndx].dvec3[i];
    if (border.data[0][1][ndx].count > 0)
        for (size_t i = 0; i < arr.h; i++)
            arr.dvec3[i * arr.w + arr.w - 1] = border.data[0][1][ndx].dvec3[i];
    if (border.data[1][0][ndx].count > 0)
        for (size_t i = 0; i < arr.w; i++)
            arr.dvec3[i] = border.data[1][0][ndx].dvec3[i];
    if (border.data[1][1][ndx].count > 0)
        for (size_t i = 0; i < arr.w; i++)
            arr.dvec3[(arr.h - 1) * arr.w + i] =
            border.data[1][1][ndx].dvec3[i];
}
