/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** iu_pause_struct
*/

#pragma once

typedef enum {
    PAUSE_BUTTON_BG,
    PAUSE_BUTTON_CONTINUE,
    PAUSE_BUTTON_SETTING,
    PAUSE_BUTTON_MENU,
    PAUSE_BUTTON_HELP,
    PAUSE_BUTTON_QUIT,
    PAUSE_BUTTON_END
} pause_buttons_t;

typedef struct {
    int state;
    int last_state;
    entity2_t buttons[PAUSE_BUTTON_END];
} pause_t;