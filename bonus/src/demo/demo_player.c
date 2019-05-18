/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** demo_player
*/

#include "headers.h"

void player_init(demo_t *demo)
{
    demo->player.curr_hp = 296.0f;
    demo->player.hp = 500.0f;
    demo->player.curr_mana = 60.0f;
    demo->player.mana = 200.0f;
    demo->player.attack = 30.0f;
    demo->player.attack_add = 0.0f;
    demo->player.defense = 10.0f;
    demo->player.lvl = 1;
    demo->player.xp = 0.0f;
    demo->player.next_xp_step = 150.0f;
    demo->player.pp = IUTEX_ELON;
}