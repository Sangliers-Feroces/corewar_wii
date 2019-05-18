/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** iu_settings
*/

#pragma once

void settings_init(void);
void settings_quit(void);
settings_t settings_load(void);
void setting_set_entities(void);

void setting_loop(void);

int setting_poll_event(void);

void display_x(demo_t *demo);

void slider_free(void);
void setting_set_slider(void);

float setting_slider_move(entity2_t *slider);
