/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static void chunk_set_terrain(chunk_t *chunk)
{
    if (chunk->terrain != NULL)
        return;
    chunk_gen_terrain(chunk->pos);
}

chunk_t* chunk_create_adv(ssize2 pos, int do_gen)
{
    chunk_t *res;
    chunk_t **pexist;

    pexist = world_chunk2d_get(pos);
    if (pexist != NULL)
        if (*pexist != NULL)
            return *pexist;
    res = chunk_create_detached(pos);
    chunk_attach(res);
    if (do_gen)
        chunk_set_terrain(res);
    return res;
}

chunk_t* chunk_create(ssize2 pos)
{
    return chunk_create_adv(pos, 1);
}

void chunk_destroy(chunk_t *chunk)
{
    chunk_t **lookup;

    if (chunk == NULL)
        return;
    chunk_save(chunk);
    lookup = world_chunk2d_get(chunk->pos);
    if (lookup != NULL)
        *lookup = NULL;
    if (chunk->world_ndx != ~0UL) {
        _demo->world.chunk[chunk->world_ndx] =
        _demo->world.chunk[--_demo->world.chunk_count];
        _demo->world.chunk[chunk->world_ndx]->world_ndx = chunk->world_ndx;
    }
    chunk_border_destroy(chunk->border);
    chunk_border_destroy(chunk->border_ter);
    arr2d_dvec3_destroy(chunk->terrain_base);
    chunk_store_ext(chunk);
    entity3_destroy(chunk->ents);
    entity3_destroy(chunk->ents_global);
    free(chunk);
}
