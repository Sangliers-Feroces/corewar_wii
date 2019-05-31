/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static int try_unload_chunk(chunk_t *chunk, ssize2 cam)
{
    ssize_t dist = ssize2_dist_sq_man(chunk->pos, cam);

    if (chunk == NULL)
        return 0;
    if (dist > CHUNK_LOAD_DISTANCE) {
        chunk_destroy(chunk);
        return 1;
    } else
        return 0;
}

static int try_load_chunk(ssize2 pos)
{
    chunk_t **chunk = world_chunk2d_get(pos);

    if (chunk == NULL) {
        world_chunk_get(pos);
        return 1;
    }
    else if (*chunk == NULL) {
        world_chunk_get(pos);
        return 1;
    } else
        return 0;
}

static int ensure_lod_chunk(ssize2 pos)
{
    chunk_t **chunk = world_chunk2d_get(pos);

    if ((chunk == NULL) || (*chunk == NULL))
        return 0;
    if ((*chunk)->terrain == NULL)
        return 0;
    if ((*chunk)->terrain->render[WORLD_LOD_MAX].mesh.m == NULL) {
        chunk_detail_terrain(*chunk);
        return 1;
    }
    return 0;
}

static void terrain_last_lod(ssize2 pos)
{
    for (ssize_t i = -2; i <= 2; i++)
        for (ssize_t j = -2; j <= 2; j++)
            if (ensure_lod_chunk(ssize2_add(pos, (ssize2){j, i})))
                return;
}

void world_chunk_god(void)
{
    ssize2 cam = chunk_get_pos(dmat4_trans(_demo->world.camera->trans.world));

    world_chunk_get(cam);
    terrain_last_lod(cam);
    world_chunk_god_stalled();
    for (size_t i = 0; i < _demo->world.chunk_count; i++)
        if (try_unload_chunk(_demo->world.chunk[i], cam))
            return;
    for (ssize_t i = -CHUNK_LOAD_DISTANCE; i <= CHUNK_LOAD_DISTANCE; i++)
        for (ssize_t j = -CHUNK_LOAD_DISTANCE; j <= CHUNK_LOAD_DISTANCE; j++)
            if (try_load_chunk(ssize2_add(cam, (ssize2){j, i})))
                return;
}
