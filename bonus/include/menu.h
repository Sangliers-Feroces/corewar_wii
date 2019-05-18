/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** menu
*/

#pragma once

int start(demo_t *demo);

void menu_init(menu_t *menu);

void menu_set_entities(menu_t *menu);

int menu_loop(demo_t *demo, menu_t *menu);

void menu_draw(menu_t *menu);
int intro(void);
void menu_display_help(void);

int menu_poll_events(demo_t *demo, menu_t *menu);
float menu_slider_move(demo_t *demo, entity2_t *slider);

//int check_music_match_time(sfTime expected, musics_t index);
size_t music_play_mod(size_t mod, musics_t index);
void music_check_breakpoint(int *display_vm);
