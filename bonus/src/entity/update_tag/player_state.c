/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static void anim_ext2(entity3_tag_player_data_t *data,
entity3 *to_m)
{
    switch (data->state) {
    case PLAYER_BOOM:
        data->has_atk = 1;
        data->anim_state += _demo->win.framelen * 1.0;
        to_m->trans.rot.x = -data->anim_state * 8.0;
        to_m->trans.rot.y = data->anim_state * 4.0 * 8.0;
        to_m->trans.pos.y = data->anim_state * 8.0;
        to_m->trans.pos.z = data->anim_state * 8.0;
        break;
    default:
        break;
    }
}

static void anim_ext(entity3_tag_player_data_t *data,
entity3 *to_m, double d)
{
    switch (data->state) {
    case PLAYER_ATK:
        data->anim_state += _demo->win.framelen * 4.0;
        d = sin(data->anim_state * M_PI);
        if (d > 0.5)
            data->has_atk += data->has_atk < 2;
        to_m->trans.rot.x = -d * 6.0 * 0.2;
        to_m->trans.rot.y = -d * 0.2;
        to_m->trans.pos.y = d * 0.2;
        to_m->trans.pos.z = d * 0.2;
        break;
    default:
        return anim_ext2(data, to_m);
    }
}

void player_anim(entity3 *ent)
{
    entity3_tag_player_data_t *data = ent->tag_data;
    double d = dvec3_norm(ent->trans.speed);
    entity3 *to_m = ent->sub.ent[0]->sub.ent[0]->sub.ent[0];

    switch (data->state) {
    case PLAYER_REG:
        to_m->trans.rot = dvec3_init(0.0, 0.0, 0.0);
        data->anim_state += _demo->win.framelen * CLAMP(d, 1.0, 15.0);
        to_m->trans.pos.x = sin(data->anim_state / 3.14) / 10.0;
        to_m->trans.pos.y = cos(data->anim_state) / 30.0;
        to_m->trans.pos.z = 0.0;
        break;
    default:
        anim_ext(data, to_m, d);
        break;
    }
    if (data->hp == 0.0)
        ent->trans.rot.x += _demo->win.framelen;
}

static void state_ext(entity3 *ent)
{
    entity3_tag_player_data_t *data = ent->tag_data;

    data->mana += _demo->win.framelen;
    if (data->mana > data->max_mana)
        data->mana = data->max_mana;
    /*if (_demo->mouse.button_click & (1 << sfMouseLeft)) {
        data->state = PLAYER_ATK;
        data->anim_state = 0.0;
        data->has_atk = 0;
    }
    if ((_demo->mouse.button_state & (1 << sfMouseRight)) &&
    (_iu.invent.inventory[10].item == ITEM_PLANE))
        ent->trans.speed.y += (9.0 - ent->trans.speed.y) * _demo->win.framelen;
    if ((_demo->mouse.button_click & (1 << sfMouseRight)) &&
    (data->mana > 3.0) && (data->has_boom)) {
        data->state = PLAYER_BOOM;
        data->anim_state = 0.0;
        data->has_atk = 0;
        data->mana -= 3.0;
    }*/
}

void player_state(entity3 *ent)
{
    entity3_tag_player_data_t *data = ent->tag_data;

    state_ext(ent);
    switch (data->state) {
    case PLAYER_BOOM:
    case PLAYER_ATK:
        if (data->anim_state > 1.0) {
            data->state = PLAYER_REG;
            data->anim_state = 0.0;
            data->has_atk = 0;
        }
        break;
    default:
        break;
    }
}
