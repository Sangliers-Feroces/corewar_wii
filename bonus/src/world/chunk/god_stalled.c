/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void entity3_switch_col(entity3 *ent, int new_state)
{
    entity3_set_col(ent, new_state);
    if (ent->trigger != NULL) {
        if (new_state)
            trigger_attach(ent->trigger);
        else
            trigger_detach(ent->trigger);
    }
    for (size_t i = 0; i < ent->sub.count; i++)
        entity3_switch_col(ent->sub.ent[i], new_state);
}

static int get_stalled(chunk_t *chunk)
{
    int res = 0;
    dvec3 cam = dmat4_trans(_demo->world.camera->trans.world);
    dvec3 c = dvec3_init(cam.x, 0.0, cam.z);
    dvec3 p = dvec3_init(chunk->pos.x * CHUNK_SIZE + CHUNK_SIZE * 0.5, 0.0,
    chunk->pos.y * CHUNK_SIZE + CHUNK_SIZE * 0.5);

    if ((chunk->terrain == NULL) || (chunk->terrain->render[2].mesh.m == NULL))
        return 1;
    if (dvec3_dist_sq(c, p) > 600.0 * 600.0)
        return 1;
    for (ssize_t i = -1; i <= 1; i++)
        for (ssize_t j = -1; j <= 1; j++)
            res |= !chunk_is_loaded(ssize2_add(chunk->pos, (ssize2){j, i}));
    return res;
}

static void switch_stalled(chunk_t *chunk, int new_state)
{
    if (chunk->is_stalled == new_state)
        return;
    entity3_switch_col(chunk->ents, !new_state);
    if (chunk->ents_ext != NULL)
        entity3_switch_col(chunk->ents_ext, !new_state);
    chunk->is_stalled = new_state;
}

static void update_stalled(chunk_t *chunk)
{
    switch_stalled(chunk, get_stalled(chunk));
}

void world_chunk_god_stalled(void)
{
    ssize2 cam = chunk_get_pos(dmat4_trans(_demo->world.camera->trans.world));

    for (size_t i = 0; i < _demo->world.chunk_count; i++)
        update_stalled(_demo->world.chunk[i]);
    for (size_t i = 0; i < _demo->world.chunk_count; i++)
        if (chunk_refresh_ext(_demo->world.chunk[i], cam))
            return;
}
