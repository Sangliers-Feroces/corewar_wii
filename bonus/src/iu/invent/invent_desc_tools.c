/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** invent_desc_tools
*/

#include "headers.h"

char *invent_get_item_type(void)
{
    switch (
    _iu.invent.items_list[
    _iu.invent.inventory[_iu.invent.focused_item].item].type) {
        case TYPE_CAC:
            return "CaC";
        case TYPE_REST_HP:
            return "Healing";
        case TYPE_REST_MANA:
            return "Mana";
        case TYPE_BAZAR:
            return "BAZAR";
        case TYPE_VEHICULE:
            return "Vehicule";
        default:
            return NULL;
    }
}

char *invent_get_item_value(void)
{
    switch (
    _iu.invent.items_list[
    _iu.invent.inventory[_iu.invent.focused_item].item].type) {
        case TYPE_CAC:
            return "ATTACK:";
        case TYPE_REST_HP:
            return "RESTORATION:";
        case TYPE_REST_MANA:
            return "RESTORATION";
        case TYPE_BAZAR:
            return "NO VALUE:";
        case TYPE_VEHICULE:
            return "SPEED:";
        default:
            return NULL;
    }
}

int invent_get_item_data(void)
{
    switch (
    _iu.invent.items_list[
    _iu.invent.inventory[_iu.invent.focused_item].item].type) {
        case TYPE_CAC:
            return _iu.invent.items_list[
            _iu.invent.inventory[_iu.invent.focused_item].item].attack;
        case TYPE_REST_HP:
            return _iu.invent.items_list[
            _iu.invent.inventory[_iu.invent.focused_item].item].restored_hp;
        case TYPE_REST_MANA:
            return _iu.invent.items_list[
            _iu.invent.inventory[_iu.invent.focused_item].item].restored_mana;
        case TYPE_VEHICULE:
            return _iu.invent.items_list[
            _iu.invent.inventory[_iu.invent.focused_item].item].speed;
        default:
            return 0;
    }
}

void invent_display_icon(void)
{
    if (_iu.invent.inventory[_iu.invent.focused_item].item == NO_ITEM) {
        _iu.invent.item_image.index = IUTEX_ITEM_VOID;
    } else
        _iu.invent.item_image.index = _iu.invent.items_list[
        _iu.invent.inventory[_iu.invent.focused_item].item].texture;
    iu_entity_draw(_iu.invent.item_image);
    if (_iu.invent.inventory[10].item == NO_ITEM)
        _iu.invent.equiped_img.index = IUTEX_ITEM_VOID;
    else
        _iu.invent.equiped_img.index = _iu.invent.items_list[
        _iu.invent.inventory[10].item].texture;
    iu_entity_draw(_iu.invent.equiped_img);
}

void invent_desc_set_default(void)
{
    vg_text_reset_str(&_iu.invent.desc_name, "NAME:Neant Distordu",
    NULL);
    vg_text_reset_str(&_iu.invent.desc_type, "TYPE:No Type",
    NULL);
    vg_text_reset_str(&_iu.invent.desc_value, "VALUE:Over 9000",
    NULL);
}
