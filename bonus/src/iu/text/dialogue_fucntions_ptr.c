/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** dialogue_fucntions_ptr
*/

#include "headers.h"

void vg_no_effect(void)
{
    return;
}

void vg_effect_quit(void)
{
    //sfRenderWindow_close(_demo->win.window);
}

void vg_next_mq(void)
{
    if (_demo->quest.curr_main_quest == QUEST_END)
        return;
    _demo->quest.curr_main_quest++;
    stop_current_music();
    main_quest_start();
}

void vg_end_storie(void)
{
    stop_current_music();
    _demo->quest.curr_main_quest = QUEST_END;
    _iu.current_dialogue = DIALOGUE_END_STORIE;
}
