/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void entity3_tag_update_player_poll_mouse(entity3 *ent)
{
    //float sensi = 0.0015f;

    if (_iu.data.is_invent)
        return;
    (void)ent;
    /*ent->trans.rot.y -=
    (float)(_demo->mouse.mouse_pos.x - _demo->mouse.last_pos.x) * sensi;
    ent->sub.ent[0]->trans.rot.x -=
    (float)(_demo->mouse.mouse_pos.y - _demo->mouse.last_pos.y) * sensi;
    ent->sub.ent[0]->trans.rot.x =
    CLAMP(ent->sub.ent[0]->trans.rot.x, -M_PI / 2.0, M_PI / 2.0);*/
}

void entity3_tag_update_player_poll_editor(
entity3 *ent, dvec3 cam_x, dvec3 cam_z)
{
    (void)ent;
    (void)cam_x;
    (void)cam_z;
    /*dvec3 *p = &ent->trans.pos;

    if (sfKeyboard_isKeyPressed(sfKeyZ))
        *p = dvec3_add(*p, dvec3_muls(cam_z, CAM_MOVE));
    if (sfKeyboard_isKeyPressed(sfKeyS))
        *p = dvec3_sub(*p, dvec3_muls(cam_z, CAM_MOVE));
    if (sfKeyboard_isKeyPressed(sfKeyD))
        *p = dvec3_add(*p, dvec3_muls(cam_x, CAM_MOVE));
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        *p = dvec3_sub(*p, dvec3_muls(cam_x, CAM_MOVE));*/
}

void entity3_tag_update_player_poll_playing(
entity3 *ent, dvec3 cam_x, dvec3 cam_z)
{
    (void)ent;
    (void)cam_x;
    (void)cam_z;
    /*dvec3 *s = &ent->trans.speed;

    cam_z.y = 0.0;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        *s = dvec3_add(*s, dvec3_muls(cam_z, PLAYER_MOVE));
    if (sfKeyboard_isKeyPressed(sfKeyS))
        *s = dvec3_sub(*s, dvec3_muls(cam_z, PLAYER_MOVE));
    if (sfKeyboard_isKeyPressed(sfKeyD))
        *s = dvec3_add(*s, dvec3_muls(cam_x, PLAYER_MOVE));
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        *s = dvec3_sub(*s, dvec3_muls(cam_x, PLAYER_MOVE));
    if (sfKeyboard_isKeyPressed(sfKeySpace) &&
    (ent->trans.is_grounded || (dmat4_trans(ent->trans.world).y < -42.0)))
        s->y = 3.0;*/
}
