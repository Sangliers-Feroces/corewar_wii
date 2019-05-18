/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static void world_chunk_flush_inserting(void)
{
    for (size_t i = 0; i < _demo->world.chunk_count; i++)
        _demo->world.chunk[i]->inserting = NULL;
}

void world_insert_start(void)
{
    world_chunk_flush_inserting();
}

void world_insert_end(size_t lod_collision)
{
    if (lod_collision != ~0UL)
        for (size_t i = 0; i < _demo->world.chunk_count; i++)
            if (_demo->world.chunk[i]->inserting != NULL) {
                entity3_bind_col(_demo->world.chunk[i]->inserting,
                entity3_get_lod_ref(_demo->world.chunk[i]->inserting,
                lod_collision));
            }
    world_chunk_flush_inserting();
}
