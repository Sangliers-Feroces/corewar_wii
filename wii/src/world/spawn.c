/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static void spawn_base(chunk_t *chunk, entity3 *ent,
entity3_tag_enemy_data_t *data)
{
    ent->trans.pos.y = world_get_ground_level(ent->trans.pos, 0.1);
    data->spawn = ent->trans.pos;
    entity3_add_trigger(ent, trigger_create(dvec3_init(-1.0, 0.0, -1.0),
    dvec3_init(1.0, 1.0, 1.0), TRIGGER_ON_HIT_NONE));
    entity3_trans_update(ent);
    ent = entity3_create(ent);
    entity3_set_render(ent, 0, mesh_full_ref_bank_init(MESH_BANK_ENEMY_BASE),
    MATERIAL_GRASS);
    ent->trans.scale = dvec3_init(0.04, 0.04, 0.04);
    entity3_trans_update(ent);
    ent->trans.is_static = 0;
    ent->lod_dist = RENDER_OBJ_LOD_DIST_FAR;
    data->enemy_type = ENEMY_BASE;
    data->level = MAX(1.0, chunk_get_strength(chunk->pos) * 20.0 - 1.0);
    data->atk = 4.0 * pow(1.1, data->level);
    data->hp = data->atk * 10.0;
}

static void set_fish_data(entity3 *ent, entity3_tag_enemy_data_t *data,
double stren, int is_boss)
{
    data->spawn = ent->trans.pos;
    data->enemy_type = ENEMY_FISH;
    data->min_furious = 32.0;
    data->max_speed = 32.0 + randf() * 32.0;
    entity3_trans_update(ent);
    data->level = MAX(1.0, stren *
    20.0 - 1.0 + (is_boss ? 10.0 : 0.0));
    data->atk = 7.0 * pow(1.1, data->level);
    data->hp = data->atk * 2.0;
}

void entity3_spawn_fish(entity3 *ent, entity3_tag_enemy_data_t *data,
double stren, int is_boss)
{
    double scale = is_boss ? 3.5 : 1.0;

    ent->trans.speed = dvec3_init(0.0, 0.0, 0.0);
    entity3_add_trigger(ent, trigger_create(dvec3_init(-scale, -scale, -scale),
    dvec3_init(scale, scale, scale), TRIGGER_ON_HIT_NONE));
    ent->trans.pos.y = MIN(double_inter(ent->trans.pos.y, -42.0, randf()), 0.0);
    entity3_trans_update(ent);
    ent = entity3_create(ent);
    entity3_set_render(ent, 0, mesh_full_ref_bank_init(MESH_BANK_ENEMY_FISH),
    MATERIAL_BLOOD);
    ent->trans.scale = dvec3_init(4.0 * scale, 4.0 * scale, 4.0 * scale);
    ent->trans.rot = dvec3_init(0.0, M_PI, 0.0);
    ent->trans.is_static = 0;
    ent->lod_dist = RENDER_OBJ_LOD_DIST_FAR;
    set_fish_data(ent, data, stren, is_boss);
}

static void set_trans(chunk_t *chunk, entity3 *ent, dvec3 pos)
{
    ent->trans.is_physics = 1;
    ent->trans.is_static = 0;
    ent->trans.is_collision = 1;
    ent->trans.slide_threshold = 0.85;
    ent->trans.pos = dvec3_add(dmat4_trans(chunk->ents->trans.world),
    dvec3_init(pos.x, 1024.0, pos.z));
    ent->trans.speed = dvec3_init(0.0, -10.0, 0.0);
}

void chunk_spawn_at(chunk_t *chunk, dvec3 pos)
{
    entity3 *ent;
    entity3_tag_enemy_data_t *data;

    ent = world_add_entity();
    set_trans(chunk, ent, pos);
    entity3_set_tag(ent, ENTITY3_TAG_ENEMY);
    data = ent->tag_data;
    data->chunk = chunk->pos;
    data->max_speed = 4.0 + randf() * 4.0;
    data->a_vel = 2.0 + randf() * 4.0;
    ent->trans.pos.y = world_get_ground_level(ent->trans.pos, 0.1);
    if (ent->trans.pos.y > -42.0)
        spawn_base(chunk, ent, data);
    else
        entity3_spawn_fish(ent, data, chunk_get_strength(chunk->pos), 0);
    chunk->enemy_count++;
}
