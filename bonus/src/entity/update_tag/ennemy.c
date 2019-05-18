/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

int entity3_is_fish(entity3 *ent)
{
    entity3_tag_enemy_data_t *data = ent->tag_data;

    return (data->enemy_type == ENEMY_FISH) ||
    (data->enemy_type == ENEMY_FISH_BOSS);
}

static void walk_around(entity3 *ent, double a_dif, double y_dif)
{
    dvec3 d;
    entity3_tag_enemy_data_t *data = ent->tag_data;

    if (ent->trans.is_grounded || entity3_is_fish(ent))
    ent->trans.rot.y += a_dif *
    _demo->win.framelen * data->a_vel;
    d = dvec3_muls(dmat4_mul_dvec3(ent->trans.world_rot,
    dvec3_init(1.0, 0.0, 0.0)), _demo->win.framelen * 10.0);
    if (entity3_is_fish(ent) && data->is_furious)
        d.y += y_dif * _demo->win.framelen * 0.2;
    ent->trans.speed = dvec3_add(ent->trans.speed, d);
}

static void update_furious(entity3 *ent, double dist, double y_p)
{
    entity3_tag_enemy_data_t *data = ent->tag_data;

    if (entity3_is_fish(ent))
        if (y_p > -42.0)
            return;
    if (dist < (data->min_furious * data->min_furious) && (!data->is_npc))
            data->is_furious = 1;
}

static void update_target(entity3 *ent, double dist, dvec3 p)
{
    entity3_tag_enemy_data_t *data = ent->tag_data;

    update_furious(ent, dist, p.y);
    if (data->is_furious && (!data->is_npc))
        data->target = p;
    else {
        if (ent->trans.t > data->max_state) {
            data->target = dvec3_add(data->spawn,
            dvec3_init((randf() - 0.5) * 64.0, 0.0, (randf() - 0.5) * 64.0));
            data->max_state = ent->trans.t + 1.0 + randf() * 5.0;
            data->is_moving = rand() % 2;
        }
    }
    if (entity3_is_fish(ent))
        ent->trans.speed = dvec3_add(ent->trans.speed,
        dvec3_muls((dvec3){0.0, 1.0, 0.0}, _demo->win.framelen));
}

void entity3_tag_update_enemy(entity3 *ent)
{
    entity3_tag_enemy_data_t *data = ent->tag_data;
    dvec3 p = dmat4_trans(_demo->world.player->trans.world);
    dvec3 e = dmat4_trans(ent->trans.world);
    dvec3 v;
    double dist = dvec3_dist_sq(dmat4_trans(ent->trans.world), p);
    double a_dif;

    update_target(ent, dist, p);
    v = dvec3_sub(data->target, e);
    a_dif = atan2(v.z, v.x) - ent->trans.rot.y;
    if (data->is_moving || data->is_furious)
        walk_around(ent, a_dif, p.y - e.y);
    if ((dist < (4.0 * 4.0)) && ent->trans.is_grounded && (fabs(a_dif) < 0.5))
        ent->trans.speed.y = 5.0;
    if (ent->trans.life < FLT64_INF)
        ent->trans.rot.z += _demo->win.framelen * 2.0;
    player_update(ent, data->is_furious ? data->max_speed :
    data->max_speed / 4.0);
}
