/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_quest_ext
*/

#include "headers.h"

static int get_curr_loot(void)
{
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (_iu.invent.inventory[i].item ==
        _demo->quest.quest[_demo->quest.curr_main_quest].item_to_loot)
            return _iu.invent.inventory[i].nb;
    }
    return 0;
}

static char *get_enemy_to_kill(void)
{
    switch (_demo->quest.quest[
    _demo->quest.curr_main_quest].enemy_to_kill) {
    case ENEMY_FISH:
        return "Fish";
    case ENEMY_FISH_BOSS:
        return "Fish boss";
    case ENEMY_BASE:
        return "Doomed House";
    default:
        return 0;
    }
}

static int get_curr_kill(void)
{
    return _demo->quest.enemy_killed[_demo->quest.quest[
    _demo->quest.curr_main_quest].enemy_to_kill];
}

void quest_get_loot_prog(void)
{
    char buff[64];
    vg_text prog;

    sprintf(buff, "%d / %d %s found", get_curr_loot(),
    _demo->quest.quest[_demo->quest.curr_main_quest].nb,
    _iu.invent.items_list[_demo->quest.quest[
    _demo->quest.curr_main_quest].item_to_loot].name);
    prog = vg_text_create(buff, NULL);
    vg_text_set_position(&prog, (vec2){0.47f, 0.77f});
    vg_text_draw(prog);
}

void quest_get_kill_prog(void)
{
    char buff[64];
    vg_text prog;

    sprintf(buff, "%d / %d %s killed", get_curr_kill(),
    _demo->quest.quest[_demo->quest.curr_main_quest].nb_to_kill,
    get_enemy_to_kill());
    prog = vg_text_create(buff, NULL);
    vg_text_set_position(&prog, (vec2){0.47f, 0.77f});
    vg_text_draw(prog);
}
