/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** quest_constructor
*/

#include "headers.h"

void vg_quest_set_at_params(vg_quest *src, quest_arg_t arg)
{
    src->time_to_kill = arg.time;
    src->nb = arg.nb_item;
    src->item_to_loot = arg.item;
    src->lvl = arg.lvl;
}

void vg_quest_set_params_kill(vg_quest *src, enemy_type_t enemy, int nb)
{
    src->enemy_to_kill = enemy;
    src->nb_to_kill = nb;
}

static void vg_quest_enable_choices(vg_quest *src)
{
    if (_iu.dialogue_list[src->first_dial].choices)
        src->start_choice = 1;
}

void vg_quest_set_loot(vg_quest *src, items_t loot, int nb_loot, float xp)
{
    src->loot = loot;
    src->nb_loot = nb_loot;
    src->xp_looted = xp;
}

vg_quest vg_quest_create(dialogues_list_t start, archetype_t at, void
(*ptr)(void))
{
    vg_quest res;

    res.first_dial = start;
    res.at = at;
    res.did = 0;
    res.next_step = ptr;
    vg_quest_enable_choices(&res);
    return res;
}