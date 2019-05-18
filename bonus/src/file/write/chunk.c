/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void file_write_ssize2(file_write_t *file, ssize2 value)
{
    file_write(file, &value, sizeof(ssize2));
}

void file_write_arr_dvec3(file_write_t *file, arr_dvec3_t arr)
{
    file_write_size_t(file, arr.count);
    file_write(file, arr.dvec3, arr.count * sizeof(dvec3));
}

void file_write_arr2d_dvec3(file_write_t *file, arr2d_dvec3_t arr)
{
    file_write_size_t(file, arr.w);
    file_write_size_t(file, arr.h);
    file_write(file, arr.dvec3, arr.w * arr.h * sizeof(dvec3));
}

void file_write_chunk_border(file_write_t *file, chunk_border_t *border)
{
    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 2; j++)
            for (size_t k = 0; k < CHUNK_GEN_ITER; k++)
                file_write_arr_dvec3(file, border->data[i][j][k]);
}

void file_write_chunk(file_write_t *file, chunk_t *chunk)
{
    file_write_ssize2(file, chunk->pos);
    file_write_chunk_border(file, &chunk->border);
    file_write_chunk_border(file, &chunk->border_ter);
    file_write_arr2d_dvec3(file, chunk->terrain_base);
    file_write_size_t(file, chunk->enemy_count);
    file_write_size_t(file, chunk->enemy_count_max);
    file_write_entity3(file, chunk->ents);
    file_write_entity3(file, chunk->ents_global);
}
