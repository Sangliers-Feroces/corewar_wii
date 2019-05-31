/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** quest_init
*/

#include "headers.h"

void quest_load(void)
{
    file_read_t file = file_read_create("maps/qst");

    _demo->quest.curr_main_quest = MAIN_QUEST_1;
    if (file.data == NULL)
        return;
    file_read(&file, &_demo->quest.curr_main_quest, sizeof(quests_list_t));
    file_read_flush(&file);
}

void quest_store(void)
{
    file_write_t file = file_write_create();

    file_write(&file, &_demo->quest.curr_main_quest, sizeof(quests_list_t));
    file_write_flush(&file, "maps/qst");
    _demo->quest.curr_main_quest = MAIN_QUEST_1;
    for (size_t i = 0; i < ENEMY_MAX; i++)
        _demo->quest.enemy_killed[i] = 0;
}

void quest_init(void)
{
    for (size_t i = 0; i < ENEMY_MAX; i++)
        _demo->quest.enemy_killed[i] = 0;
    quest_load();
    set_quest_dialogues();
    quest_set();
}