/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** invent_tools
*/

#include "headers.h"

static void player_updtate_weapon_ext2(void)
{
    entity3 *sword = _demo->world.player->sub.ent[0]->sub.ent[0]->sub.ent[0];
    entity3_tag_player_data_t *data = _demo->world.player->tag_data;

    entity3_set_render(sword, 0, mesh_full_ref_bank_init(MESH_BANK_ARM),
    MATERIAL_METAL_RUST);
    data->atk = 5.0;
    data->has_boom = 0;
}

static void player_updtate_weapon_ext1(void)
{
    entity3 *sword = _demo->world.player->sub.ent[0]->sub.ent[0]->sub.ent[0];
    entity3_tag_player_data_t *data = _demo->world.player->tag_data;

    switch (_iu.invent.inventory[10].item) {
    case ITEM_SWORD_3:
        entity3_set_render(sword, 0, mesh_full_ref_bank_init(MESH_BANK_SWORD_3),
        MATERIAL_METAL_BARE);
        data->atk = _iu.invent.items_list[_iu.invent.inventory[10].item].attack;
        data->has_boom = 1;
        break;
    case ITEM_PLANE:
        entity3_set_render(sword, 0, mesh_full_ref_bank_init(MESH_BANK_PLANE),
        MATERIAL_BLOOD);
        data->atk = _iu.invent.items_list[_iu.invent.inventory[10].item].attack;
        data->has_boom = 0;
        break;
    default:
        player_updtate_weapon_ext2();
        break;
    }
}

void player_update_weapon(void)
{
    entity3 *sword = _demo->world.player->sub.ent[0]->sub.ent[0]->sub.ent[0];
    entity3_tag_player_data_t *data = _demo->world.player->tag_data;

    switch (_iu.invent.inventory[10].item) {
    case ITEM_SWORD_1:
        entity3_set_render(sword, 0, mesh_full_ref_bank_init(MESH_BANK_SWORD_1),
        MATERIAL_METAL_RUST);
        data->atk = _iu.invent.items_list[_iu.invent.inventory[10].item].attack;
        data->has_boom = 0;
        break;
    case ITEM_SWORD_2:
        entity3_set_render(sword, 0, mesh_full_ref_bank_init(MESH_BANK_SWORD_2),
        MATERIAL_METAL_BARE);
        data->atk = _iu.invent.items_list[_iu.invent.inventory[10].item].attack;
        data->has_boom = 1;
        break;
    default:
        player_updtate_weapon_ext1();
    }
}

void refresh_invent_help(void)
{
    if (_iu.settings.hints_state == WITH_HINT)
        _iu.invent_bg[IUINVENT_BG].index = IUTEX_INVENT_HELP;
    else
        _iu.invent_bg[IUINVENT_BG].index = IUTEX_INVENT_BG;
}
