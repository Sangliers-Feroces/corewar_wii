/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_active_quest
*/

#include "headers.h"

void quest_get_lvl_prog(void)
{
    entity3_tag_player_data_t  *data = _demo->world.player->tag_data;
    char buff[64];
    vg_text prog;

    sprintf(buff, "Level: %.f / %d", data->level,
    _demo->quest.quest[_demo->quest.curr_main_quest].lvl);
    prog = vg_text_create(buff, NULL);
    vg_text_set_position(&prog, (vec2){0.47f, 0.77f});
    vg_text_draw(prog);
}

void quest_display_current(void)
{
    vg_text quest = vg_text_create("Current Objective :", NULL);

    vg_text_set_position(&quest, (vec2){0.43f, 0.87f});
    vg_text_draw(quest);
    switch (_demo->quest.quest[_demo->quest.curr_main_quest].at) {
    case AT_LOOT:
        quest_get_loot_prog();
        break;
    case AT_KILL:
        quest_get_kill_prog();
        break;
    case AT_LVL:
        quest_get_lvl_prog();
        break;
    case AT_BOSS:
        break;
    }
    return;
}