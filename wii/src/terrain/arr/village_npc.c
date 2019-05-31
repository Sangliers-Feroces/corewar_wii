/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static int is_pos_valid(dvec3 pos)
{
    return (pos.x > 0.1 * CHUNK_SIZE) && (pos.y < 0.9 * CHUNK_SIZE) &&
    (pos.z > 0.1 * CHUNK_SIZE) && (pos.z < 0.9 * CHUNK_SIZE) && (pos.y > -40.0);
}

static void set_physics(chunk_t *chunk, entity3 *ent, dvec3 p)
{
    ent->trans.is_physics = 1;
    ent->trans.is_static = 0;
    ent->trans.is_collision = 1;
    ent->trans.slide_threshold = 0.85;
    ent->trans.pos = dvec3_add(p, chunk->ents->trans.pos);
    ent->trans.pos.y += 0.1;
    ent->trans.speed = dvec3_init(0.0, -10.0, 0.0);
}

static void set_stuff(chunk_t *chunk, entity3 *ent, dvec3 p)
{
    entity3_tag_enemy_data_t *data;

    set_physics(chunk, ent, p);
    entity3_set_tag(ent, ENTITY3_TAG_ENEMY);
    data = ent->tag_data;
    data->chunk = chunk->pos;
    data->max_speed = 2.0 + randf() * 2.0;
    data->a_vel = 2.0 + randf() * 4.0;
    entity3_trans_update(ent);
    data->spawn = ent->trans.pos;
    entity3_add_trigger(ent, trigger_create(dvec3_init(-1.0, 0.0, -1.0),
    dvec3_init(1.0, 1.0, 1.0), TRIGGER_ON_HIT_NONE));
    entity3_trans_update(ent);
    data->atk = chunk_get_strength(chunk->pos) * 30.0;
    data->is_npc = 1;
}

void chunk_add_npc(chunk_t *chunk, dvec3 p)
{
    entity3 *ent;

    if (!is_pos_valid(p))
        return;
    ent = world_add_entity();
    set_stuff(chunk, ent, p);
    ent = entity3_create(ent);
    if ((rand() % 2) == 0)
        entity3_set_render(ent, 0, mesh_full_ref_bank_init(MESH_BANK_KNIGHT),
        MATERIAL_WOOD);
    else
        entity3_set_render(ent, 0, mesh_full_ref_bank_init(MESH_BANK_NPC1),
        MATERIAL_NPC1);
    ent->trans.scale = dvec3_init(1.5, 1.5, 1.5);
    ent->trans.rot = dvec3_init(0.0, -M_PI / 2.0, 0.0);
    entity3_trans_update(ent);
    ent->trans.is_static = 0;
    ent->lod_dist = RENDER_OBJ_LOD_DIST_FAR;
}
