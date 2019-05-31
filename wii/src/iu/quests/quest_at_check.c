/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** quest_at_check
*/

#include "headers.h"

static int check_at_lvl(vg_quest *src)
{
    entity3_tag_player_data_t *data = _demo->world.player->tag_data;

    if (data->level >= src->lvl) {
        src->did = 1;
        invent_add_items(src->loot, src->nb_loot);
        src->next_step();
        return 1;
    }
    return 0;
}

static int check_at_kill(vg_quest *src)
{
    if (_demo->quest.enemy_killed[src->enemy_to_kill] >=
    (size_t)src->nb_to_kill) {
        _demo->quest.enemy_killed[src->enemy_to_kill] = 0;
        invent_add_items(src->loot, src->nb_loot);
        player_loot_xp(src->xp_looted);
        src->next_step();
    }
    return 1;
}

static int check_at_loot(vg_quest *src)
{
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (_iu.invent.inventory[i].item == src->item_to_loot
        &&  _iu.invent.inventory[i].nb >= src->nb) {
            _iu.invent.inventory[i].nb -= src->nb;
            if (_iu.invent.inventory[i].nb == 0)
                _iu.invent.inventory[i].item = NO_ITEM;
            invent_add_items(src->loot, src->nb_loot);
            player_loot_xp(src->xp_looted);
            src->next_step();
            return 1;
        }
    }
    return 0;
}

int quest_check_success(quests_list_t index)
{
    switch (_demo->quest.quest[index].at) {
    case AT_LVL:
        return check_at_lvl(&_demo->quest.quest[index]);
    case AT_LOOT:
        return check_at_loot(&_demo->quest.quest[index]);
    case AT_KILL:
        return check_at_kill(&_demo->quest.quest[index]);
    default:
        return 0;
    }
}
