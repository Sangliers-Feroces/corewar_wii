/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void world_chunk_send_global_ent(ssize2 chunk_pos, entity3 *ent)
{
    chunk_t *chunk = world_chunk_get_adv(chunk_pos, 1, 0);

    entity3_move(ent, chunk->ents_global);
}
