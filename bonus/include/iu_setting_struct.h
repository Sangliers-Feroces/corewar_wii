/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** iu_setting_struct
*/

#pragma once

typedef enum {
    SETTINGS_BG,
    SETTINGS_VOL_MAST,
    SETTINGS_VOL_MUSIC,
    SETTINGS_VOL_SOUND,
    SETTINGS_CB_SCREEN,
    SETTINGS_CB_HINT,
    SETTINGS_END
} settings_entitie_t;

typedef enum {
    WINDOWED,
    FULLSCREEN
} s_screen_t;

typedef enum {
    NO_HINT,
    WITH_HINT
} s_hint_t;

typedef struct {
    s_screen_t screen_state;
    s_hint_t hints_state;
    entity2_t entities[SETTINGS_END];
} settings_t;
