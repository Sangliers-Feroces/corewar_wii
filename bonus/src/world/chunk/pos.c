/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

ssize2 chunk_get_pos(dvec3 pos)
{
    ssize2 res;

    res.x = pos.x / CHUNK_SIZE - (pos.x < 0.0 ? 1 : 0);
    res.y = pos.z / CHUNK_SIZE - (pos.z < 0.0 ? 1 : 0);
    return res;
}

ssize2 chunk_get_terrain_pos(ssize2 chunk_pos)
{
    ssize2 res;

    if (chunk_pos.x >= 0)
        res.x = chunk_pos.x / CHUNK_TERRAIN_SUB_SIZE;
    else
        res.x = (chunk_pos.x + 1) / CHUNK_TERRAIN_SUB_SIZE - 1;
    if (chunk_pos.y >= 0)
        res.y = chunk_pos.y / CHUNK_TERRAIN_SUB_SIZE;
    else
        res.y = (chunk_pos.y + 1) / CHUNK_TERRAIN_SUB_SIZE - 1;
    return res;
}

chunk_t* world_chunk_get_by_pos(dvec3 pos)
{
    return world_chunk_get(chunk_get_pos(pos));
}
