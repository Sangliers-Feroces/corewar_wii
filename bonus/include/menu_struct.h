/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** menu_struct
*/

#pragma once

typedef enum {
    MENU_BG_MAIN,
    MENU_BG_SETTING,
    MENU_BG_HELP,
    MENU_BG_END
} menu_bg_t;

typedef enum {
    MENU_LINK_CONTINUE,
    MENU_LINK_NEW,
    MENU_LINK_SETTING,
    MENU_LINK_CREDITS,
    MENU_LINK_QUIT,
    MENU_LINK_CURSOR,
    MENU_LINK_END
} menu_link_t;

typedef enum {
    MENU_BRANCH_ROOT,
    MENU_BRANCH_SETTING,
    MENU_BRANCH_END
} menu_branch_t;

typedef struct {
    //setting
    int edited_setting;
    //temporaire
    //save
    int first_save;
    //menu_state
    int state;
    int menu_choice;
    menu_branch_t branch;
    //entities
    entity2_t background[MENU_BG_END];
    entity2_t link[MENU_LINK_END];
    //music
    //sfMusic *music;
} menu_t;
