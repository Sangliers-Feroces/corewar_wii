/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

int world_is_chunk_active(ssize2 chunk_pos)
{
    chunk_t **pexist = world_chunk2d_get(chunk_pos);

    if ((pexist == NULL) || (*pexist == NULL))
        return 0;
    return !(*pexist)->is_stalled;
}

static int is_ent_unloadable(entity3 *ent)
{
    return (ent->tag != ENTITY3_TAG_PLAYER) && (ent->tag != ENTITY3_TAG_SKYBOX);
}

int try_unload_ent(entity3 *ent)
{
    ssize2 chunk_pos = chunk_get_pos(dmat4_trans(ent->trans.world));

    if (is_ent_unloadable(ent)) {
        world_chunk_send_global_ent(chunk_pos, ent);
        return 1;
    }
    return 0;
}

void entity3_global_update(entity3 *ent)
{
    /*dvec3 player = dmat4_trans(_demo->world.player->trans.world);
    dvec3 p;
    int is_far;*/

    entity3_update_solo(ent);
    for (size_t i = 0; i < ent->sub.count; i++) {
        /*p = dmat4_trans(ent->sub.ent[i]->trans.world);
        if (world_is_pos_col_oob(p)) {
            i -= try_unload_ent(ent->sub.ent[i]);
            continue;
        }
        is_far = dvec3_dist_sq(dvec3_init(player.x, 0.0, player.z),
        dvec3_init(p.x, 0.0, p.z)) > (CHUNK_SIZE / 4.0) * (CHUNK_SIZE / 4.0);
        if (is_far)
            continue;*/
        entity3_update(ent->sub.ent[i]);
    }
}
