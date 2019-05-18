/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** invent
*/

#pragma once

void invent_load(void);
void invent_store(void);
void invent_init(void);
void invent_quit(void);

int invent_poll_event(void);

void invent_loop(void);

char *invent_get_item_type(void);
char *invent_get_item_value(void);
int invent_get_item_data(void);
void invent_display_icon(void);

void invent_draw_button(void);

void invent_stat_display_init(void);

void invent_draw_stat(void);

void invent_switch_action(void);

void invent_refresh_attack_added(void);

int invent_add_items(items_t item, size_t count);
int invent_add_item(items_t item);

void refresh_invent_help(void);

void invent_desc_set_default(void);
