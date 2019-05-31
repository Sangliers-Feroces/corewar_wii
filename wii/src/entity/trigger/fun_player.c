/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static void bleed(dvec3 p)
{
    size_t c = rand() % 50 + 10;
    entity3 *ent;

    for (size_t i = 0; i < c; i++) {
        ent = world_add_entity();
        ent->trans.is_static = 0;
        ent->trans.is_physics = 1;
        ent->trans.pos = dvec3_add(p, dvec3_init(randfn(), 0.0, randfn()));
        ent->trans.speed = dvec3_init(randfn(), randfn() * 5.0, randfn());
        ent->trans.life = 10.0;
        ent->trans.rot.y = randf() * M_PI;
        entity3_set_render(ent, 0, mesh_full_ref_bank_init(MESH_BANK_PARTICLE1),
        MATERIAL_BLOOD);
        entity3_trans_update(ent);
    }
}

static void make_damage_to_enemy(entity3 *ent, dvec3 dir, double hp)
{
    entity3_tag_enemy_data_t *data = ent->tag_data;

    if ((data->last_damage + 1.0) > ent->trans.t)
        return;
    if (data->is_npc)
        return;
    ent->trans.speed = dvec3_add(ent->trans.speed, dir);
    ent->trans.speed.y += 3.0;
    data->hp -= hp;
    data->last_damage = ent->trans.t;
    data->is_furious = 1;
    if (hp > 0.0)
        bleed(dmat4_trans(ent->trans.world));
    if (data->hp <= 0.0) {
        ent->trans.life = ent->trans.t + 1.0;
        dvec3_add(ent->trans.speed, dir);
        dvec3_add(ent->trans.speed, dir);
        for (size_t i = 0; i < 4; i++)
            bleed(dmat4_trans(ent->trans.world));
    }
}

static void make_damage_to_player(entity3 *ent, dvec3 dir, double hp)
{
    entity3_tag_player_data_t *data = ent->tag_data;

    if ((data->last_damage + 1.0) > ent->trans.t)
        return;
    if (data->hp <= 0.0)
        return;
    ent->trans.speed = dvec3_add(ent->trans.speed, dir);
    ent->trans.speed.y += 2.0;
    data->hp -= hp;
    data->last_damage = ent->trans.t;
    bleed(dmat4_trans(_demo->world.camera->trans.world));
    if (data->hp <= 0.0) {
        data->hp = 0.0;
        ent->trans.life = ent->trans.t + 4.0;
        dvec3_add(ent->trans.speed, dir);
        dvec3_add(ent->trans.speed, dir);
        for (size_t i = 0; i < 64; i++)
            bleed(dmat4_trans(_demo->world.camera->trans.world));
    }
}

void trigger_on_hit_sword(entity3 *ent, entity3 *other)
{
    entity3 *enemy = entity3_get_parent(other, 0);
    entity3_tag_player_data_t *player_data = _demo->world.player->tag_data;

    (void)ent;
    if (enemy != NULL && (enemy->tag == ENTITY3_TAG_ENEMY)) {
        if (player_data->has_atk != 1)
            return;
        make_damage_to_enemy(enemy, dvec3_add(dvec3_muls(dvec3_mul(
        dmat4_mul_dvec3(_demo->world.camera->trans.world_rot,
        dvec3_init(0.0, 0.0, 1.0)), dvec3_init(1.0, 0.0, 1.0)), 16.0),
        _demo->world.player->trans.speed),
        player_data->atk);
    }
}

void trigger_on_hit_player(entity3 *ent, entity3 *other)
{
    entity3 *enemy = entity3_get_parent(other, 0);
    entity3_tag_enemy_data_t *enemy_data;

    if (other->tag == ENTITY3_TAG_SWORD)
        return;
    if (enemy != NULL && (enemy->tag == ENTITY3_TAG_ENEMY)) {
        enemy_data = enemy->tag_data;
        if ((!enemy_data->is_furious) || enemy_data->is_npc)
            return;
        make_damage_to_player(ent, dvec3_add(dvec3_muls(dvec3_mul(
        dmat4_mul_dvec3(enemy->trans.world_rot,
        dvec3_init(1.0, 0.0, 0.0)), dvec3_init(1.0, 0.0, 1.0)), 16.0),
        dvec3_muls(enemy->trans.speed, 1.5)),
        enemy_data->atk);
    }
}
