/*
** EPITECH PROJECT, 2019
** h
** File description:
** invent_main_action
*/

#include "headers.h"

void invent_refresh_attack_added(void)
{
    if (_iu.invent.inventory[10].item == NO_ITEM)
        _demo->player.attack_add = 0;
    else
        _demo->player.attack_add =
        _iu.invent.items_list[_iu.invent.inventory[10].item].attack;
}

static void invent_equip(void)
{
    items_t save;

    if (_demo->input.key_press[KEY_ENTER]) {
        save = _iu.invent.inventory[_iu.invent.focused_item].item;
        if (_iu.invent.inventory[10].item != NO_ITEM)
            _iu.invent.inventory[_iu.invent.focused_item].item =
            _iu.invent.inventory[10].item;
        else {
            _iu.invent.inventory[_iu.invent.focused_item].item = NO_ITEM;
            _iu.invent.inventory[_iu.invent.focused_item].nb = 0;
        }
        _iu.invent.inventory[10].item = save;
    }
}

static void invent_consume_hp(void)
{
    entity3_tag_player_data_t *data = _demo->world.player->tag_data;

    if (data->hp == data->max_hp)
        return;
    data->hp += _iu.invent.items_list[
    _iu.invent.inventory[_iu.invent.focused_item].item].restored_hp;
    if (data->hp > data->max_hp)
        data->hp = data->max_hp;
    _iu.invent.inventory[_iu.invent.focused_item].nb--;
    if (!_iu.invent.inventory[_iu.invent.focused_item].nb)
        _iu.invent.inventory[_iu.invent.focused_item].item = NO_ITEM;
    return;
}

static void invent_consume_mana(void)
{
    _demo->player.curr_mana += _iu.invent.items_list[
    _iu.invent.inventory[_iu.invent.focused_item].item].restored_mana;
    if (_demo->player.curr_mana > _demo->player.mana)
        _demo->player.curr_mana -=
        (_demo->player.curr_mana - _demo->player.mana);
    _iu.invent.inventory[_iu.invent.focused_item].nb--;
    if (!_iu.invent.inventory[_iu.invent.focused_item].nb)
        _iu.invent.inventory[_iu.invent.focused_item].item = NO_ITEM;
    return;
}

void invent_switch_action(void)
{
    if (_iu.invent.inventory[_iu.invent.focused_item].item == NO_ITEM) {
        invent_equip();
        return;
    }
    switch (_iu.invent.items_list[_iu.invent.inventory[
        _iu.invent.focused_item].item].type) {
        case TYPE_CAC:
            return invent_equip();
        case TYPE_REST_HP:
            return invent_consume_hp();
        case TYPE_REST_MANA:
            return invent_consume_mana();
        case TYPE_VEHICULE:
            return;
        default:
            return;
    }
}
