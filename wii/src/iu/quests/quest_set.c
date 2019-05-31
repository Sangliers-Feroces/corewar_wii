/*
** EPITECH PROJECT, 2019
** quests
** File description:
** quest_set
*/

#include "headers.h"

static void set_quest_ext(void)
{
    _demo->quest.quest[MAIN_QUEST_3] = vg_quest_create(DIALOGUE_MAIN3_START
    , AT_KILL, &vg_next_mq);
    vg_quest_set_params_kill(&_demo->quest.quest[MAIN_QUEST_3], ENEMY_FISH, 15);
    vg_quest_set_loot(&_demo->quest.quest[MAIN_QUEST_3],
    ITEM_SWORD_3, 1, 20);
    _demo->quest.quest[MAIN_QUEST_BOSS] = vg_quest_create(DIALOGUE_MAINBOSS
    , AT_KILL, &vg_end_storie);
    vg_quest_set_params_kill(&_demo->quest.quest[MAIN_QUEST_BOSS],
    ENEMY_FISH_BOSS, 1);
    vg_quest_set_loot(&_demo->quest.quest[MAIN_QUEST_BOSS],
    ITEM_PLANE, 1, 100);
}

void quest_set(void)
{
    _demo->quest.quest[MAIN_QUEST_1] = vg_quest_create(DIALOGUE_MAIN1_START
    , AT_LVL, &vg_next_mq);
    vg_quest_set_at_params(&_demo->quest.quest[MAIN_QUEST_1],
    (quest_arg_t){0, 0, 0, 3});
    vg_quest_set_loot(&_demo->quest.quest[MAIN_QUEST_1],
    ITEM_APPLE, 5, 10);
    _demo->quest.quest[MAIN_QUEST_2] = vg_quest_create(DIALOGUE_MAIN2_START
    , AT_LOOT, &vg_next_mq);
    vg_quest_set_at_params(&_demo->quest.quest[MAIN_QUEST_2],
    (quest_arg_t){0, 30, ITEM_PLANK, 0});
    vg_quest_set_loot(&_demo->quest.quest[MAIN_QUEST_2],
    ITEM_SWORD_2, 1, 10);
    set_quest_ext();
}