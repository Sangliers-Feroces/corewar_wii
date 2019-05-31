/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

chunk_t** world_chunk2d_get(ssize2 pos)
{
    ssize2 ndx = ssize2_sub(pos, _demo->world.chunk2d_area.p);

    if (!((ndx.x >= 0) && (ndx.x < _demo->world.chunk2d_area.s.x) &&
    (ndx.y >= 0) && (ndx.y < _demo->world.chunk2d_area.s.y)))
        return NULL;
    else
        return
        &_demo->world.chunk2d[ndx.y * _demo->world.chunk2d_area.s.x + ndx.x];
}

chunk_t* world_chunk_get_adv(ssize2 pos, int do_load, int do_gen)
{
    chunk_t **pexist = world_chunk2d_get(pos);
    chunk_t *res;

    if (pexist != NULL)
        if (*pexist != NULL)
            return *pexist;
    if (do_load)
        if (chunk_try_load(pos, &res))
            return res;
    return chunk_create_adv(pos, do_gen);
}

chunk_t* world_chunk_get(ssize2 pos)
{
    return world_chunk_get_adv(pos, 1, 1);
}
