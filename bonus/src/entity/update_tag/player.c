/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static void slow_ent_down(entity3 *ent)
{
    dvec3 d = dvec3_normalize(dvec3_init(
    ent->trans.speed.x, 0.0, ent->trans.speed.z));
    dvec3 f = dvec3_muls(d, _demo->win.framelen * 8.0);
    double norm = dvec3_norm(ent->trans.speed);

    if (norm > 1.0)
        ent->trans.speed = dvec3_sub(ent->trans.speed, f);
    else
        ent->trans.speed = dvec3_sub(ent->trans.speed, dvec3_muls(
        ent->trans.speed, _demo->win.framelen * 6.0));
}

static void cap_ent_speed(dvec3 *speed, double max)
{
    vec2 xz = {speed->x, speed->z};
    float dist = vec2_norm(xz);

    if (dist > max) {
        xz = vec2_muls(xz, max / dist);
        *speed = (dvec3){xz.x, speed->y, xz.y};
    }
}

void player_update(entity3 *ent, double max_speed)
{
    if (ent->trans.is_grounded)
        slow_ent_down(ent);
    if (_iu.invent.inventory[10].item != ITEM_PLANE)
        cap_ent_speed(&ent->trans.speed, max_speed);
}

void entity3_tag_update_player(entity3 *ent)
{
    dvec3 cam_x;
    dvec3 cam_z;
    entity3 *ref_move = ent->trans.is_physics ? ent : ent->sub.ent[0];
    entity3_tag_player_data_t *data = ent->tag_data;

    if (data->hp > 0.0) {
        entity3_tag_update_player_poll_mouse(ent);
        cam_x = dvec3_muls(dmat4_mul_dvec3(ref_move->trans.world_rot,
        dvec3_init(1.0, 0.0, 0.0)), _demo->win.framelen);
        cam_z = dvec3_muls(dmat4_mul_dvec3(ref_move->trans.world_rot,
        dvec3_init(0.0, 0.0, 1.0)), _demo->win.framelen);
        if (ent->trans.is_physics)
            entity3_tag_update_player_poll_playing(ent, cam_x, cam_z);
        else
            entity3_tag_update_player_poll_editor(ent, cam_x, cam_z);
        /*player_update(ent, sfKeyboard_isKeyPressed(sfKeyLShift) ?
        PLAYER_MAX_SPEED : PLAYER_MAX_SPEED_WALK);*/
        player_state(ent);
    }
    player_anim(ent);
}
