/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static void boss_set_trans(entity3 *ent)
{
    ent->trans.is_physics = 1;
    ent->trans.is_static = 0;
    ent->trans.is_collision = 1;
    ent->trans.slide_threshold = 0.85;
    ent->trans.speed = dvec3_init(0.0, -10.0, 0.0);
}

void world_spawn_boss(void)
{
    entity3 *ent;
    entity3_tag_enemy_data_t *data;

    ent = world_add_entity();
    boss_set_trans(ent);
    entity3_set_tag(ent, ENTITY3_TAG_ENEMY);
    data = ent->tag_data;
    data->max_speed = 4.0 + randf() * 4.0;
    data->a_vel = 2.0 + randf() * 4.0;
    entity3_spawn_fish(ent, data, 0.0, 1);
    ent->trans.pos = dvec3_add(dmat4_trans(_demo->world.player->trans.world),
    dvec3_mul(dvec3_muls(dmat4_mul_dvec3(_demo->world.player->trans.world_rot,
    dvec3_init(0.0, 0.0, 1.0)), 20.0), dvec3_init(1.0, 0.0, 1.0)));
    ent->trans.pos.y = dmat4_trans(_demo->world.player->trans.world).y + 10.0;
    entity3_trans_update(ent);
    data->is_furious = 1;
    data->hp *= 10.0;
    data->enemy_type = ENEMY_FISH_BOSS;
}

double world_get_ground_level(dvec3 p, double bias)
{
    inter_ray3 inter = world_inter((ray3){dvec3_init(p.x, 4096.0, p.z),
    dvec3_init(0.0, -1.0, 0.0)});

    if (inter.triangle == NULL)
        return 64000.0;
    else
        return inter.p.y + bias;
}

double double_inter(double a, double b, double ratio)
{
    return a * (1.0 - ratio) + b * ratio;
}
