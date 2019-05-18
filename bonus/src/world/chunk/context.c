/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void world_chunk_add(chunk_t *chunk)
{
    size_t cur = _demo->world.chunk_count++;
    chunk_t **new_chunk;

    if (_demo->world.chunk_count > _demo->world.chunk_allocated) {
        _demo->world.chunk_allocated += 16;
        new_chunk =
        (chunk_t**)malloc_safe(_demo->world.chunk_allocated * sizeof(chunk_t*));
        for (size_t i = 0; i < cur; i++)
            new_chunk[i] = _demo->world.chunk[i];
        free(_demo->world.chunk);
        _demo->world.chunk = new_chunk;
    }
    _demo->world.chunk[cur] = chunk;
    chunk->world_ndx = cur;
}

chunk_t* chunk_create_detached(ssize2 pos)
{
    chunk_t *res;

    res = (chunk_t*)malloc_safe(sizeof(chunk_t));
    res->pos = pos;
    res->border = chunk_border_init();
    res->border_ter = chunk_border_init();
    res->terrain_base = (arr2d_dvec3_t){0, 0, NULL};
    res->world_ndx = ~0UL;
    res->enemy_count = 0;
    res->enemy_count_max =
    (0.1 + 0.9 * randf()) * chunk_get_strength(pos) * 256.0;
    res->ents = entity3_create_pos(NULL,
    dvec3_init(pos.x * CHUNK_SIZE, 0.0, pos.y * CHUNK_SIZE));
    res->ents_ext = NULL;
    res->ents_global = entity3_create_pos(NULL, dvec3_init(0.0, 0.0, 0.0));
    res->inserting = NULL;
    res->terrain = NULL;
    res->is_stalled = 1;
    return res;
}

void chunk_attach(chunk_t *chunk)
{
    world_chunk2d_insert(chunk);
    world_chunk_add(chunk);
}
