/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static ssize_t get_1d_pos(double value)
{
    ssize_t ival = (ssize_t)value;
    ssize_t sign = value >= 0 ? 1 : -1;

    return (ival % ((ssize_t)CHUNK_SIZE)) >=
    (((ssize_t)CHUNK_SIZE) * sign / 2) ? 1 : -1;
}

static ssize2 get_inner_chunk_pos(dvec3 src)
{
    return (ssize2){get_1d_pos(src.x), get_1d_pos(src.z)};
}

int world_is_pos_col_oob(dvec3 p)
{
    ssize2 chunk_pos = chunk_get_pos(p);
    ssize2 inner = get_inner_chunk_pos(p);

    if (!world_is_chunk_active(chunk_pos))
        return 1;
    if (!world_is_chunk_active(ssize2_add(chunk_pos, (ssize2){inner.x, 0})))
        return 1;
    if (!world_is_chunk_active(ssize2_add(chunk_pos, (ssize2){0, inner.y})))
        return 1;
    if (!world_is_chunk_active(ssize2_add(chunk_pos,
    (ssize2){inner.x, inner.y})))
        return 1;
    return 0;
}
