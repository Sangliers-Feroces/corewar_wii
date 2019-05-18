/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** quest_dialogues
*/

#include "headers.h"

void set_quest_dialogues(void)
{
    _iu.dialogue_list[DIALOGUE_MAIN1_START] = vg_dialogue_create(4,
    TEXT_MAIN1_START1);
    vg_dialogue_set_choices(&_iu.dialogue_list[DIALOGUE_MAIN1_START],
    (choices_arg_t){
    "(A) : Accept", "(E) : Accept", &vg_no_effect, &vg_no_effect});
    _iu.dialogue_list[DIALOGUE_MAIN2_START] = vg_dialogue_create(3,
    TEXT_MAIN2_START1);
    _iu.dialogue_list[DIALOGUE_MAIN3_START] = vg_dialogue_create(3,
    TEXT_MAIN3_START1);
    _iu.dialogue_list[DIALOGUE_MAINBOSS] = vg_dialogue_create(1,
    TEXT_MAINBOSS);
    _iu.dialogue_list[DIALOGUE_END_STORIE] = vg_dialogue_create(3,
    TEXT_END_1);
    vg_dialogue_set_choices(&_iu.dialogue_list[DIALOGUE_END_STORIE],
    (choices_arg_t){
    "(A) : Stay", "(E) : Leave", &vg_no_effect, &vg_effect_quit});
}