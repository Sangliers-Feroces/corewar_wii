/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static void slow_ent_down(entity3 *ent)
{
    ent->trans.speed.x *= 1.0 - _demo->win.framelen * 1.0;
    ent->trans.speed.z *= 1.0 - _demo->win.framelen * 1.0;
}

static void apply_ext(entity3 *ent)
{
    int is_underwater = dmat4_trans(ent->trans.world).y < -42.0;

    ent->trans.speed = dvec3_add(ent->trans.speed,
    dvec3_muls((dvec3){0.0, !is_underwater ?
    -9.8 : -1.0, 0.0}, _demo->win.framelen));
    if (is_underwater)
        slow_ent_down(ent);
}

static void physics_collision(entity3 *ent, dvec3 p)
{
    dvec3 speed_frame;
    dvec3 old_speed;
    dvec3 norm = {0.0, 0.0, 0.0};
    int do_fast = ent->tag != ENTITY3_TAG_PLAYER;

    apply_ext(ent);
    speed_frame = dvec3_muls(ent->trans.speed, _demo->win.framelen);
    old_speed = speed_frame;
    for (size_t i = 0; i < 4; i++)
        if (!physics_check_col((physics_param_t){do_fast, i > 0,
        ent->trans.slide_threshold}, p, &speed_frame, &norm))
            break;
    dvec3 disp = dvec3_add(speed_frame,
    dvec3_muls(dvec3_normalize(norm), 0.001));
    physics_apply_disp(do_fast, &p, disp);
    ent->trans.pos = p;
    ent->trans.is_grounded = old_speed.y < speed_frame.y;
    ent->trans.speed = dvec3_divs(speed_frame, _demo->win.framelen);
}

static void physics_basic(entity3 *ent)
{
    dvec3 speed_frame;
    dvec3 old_speed;
    int is_underwater = dmat4_trans(ent->trans.world).y < -42.0;

    ent->trans.speed = dvec3_add(ent->trans.speed,
    dvec3_muls((dvec3){0.0, !is_underwater ?
    -9.8 : -1.0, 0.0}, _demo->win.framelen));
    if (is_underwater)
        slow_ent_down(ent);
    speed_frame = dvec3_muls(ent->trans.speed, _demo->win.framelen);
    old_speed = speed_frame;
    ent->trans.pos = dvec3_add(ent->trans.pos, speed_frame);
    ent->trans.is_grounded = old_speed.y < speed_frame.y;
    ent->trans.speed = dvec3_divs(speed_frame, _demo->win.framelen);
}

void entity3_physics(entity3 *ent)
{
    dvec3 p = dmat4_trans(ent->trans.world);

    if (ent->trans.is_collision)
        physics_collision(ent, p);
    else
        physics_basic(ent);
    if (ent->trans.pos.y < -512.0)
        ent->trans.pos.y = world_get_ground_level(ent->trans.pos, 2.0);
}
