/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** ui
*/

#pragma once

void ui_init(demo_t *demo);
void ui_quit(void);

display_nbr_array_t ui_fill_display_nbr_array(int max_value, vec2 pos,
float size, float offset_nbr);

void ui_draw_full_rel(int index, rect_t rect, float depth);
void button_draw(button_t button);
void ui_display(int task, demo_t *demo);

void ui_set_textures_to_null(void);
void ui_load_texture(const ui_texture_descriptor_t descriptors_array[]);
void ui_set_buttons(void);

void ui_swicth_button_action(demo_t *demo);
void ui_refresh_hover(demo_t *demo);
void ui_check_click_button(demo_t *demo);
rect_t button_get_size(entity2_t button);

void ui_button_effect(demo_t *demo);

void display_selected_texture(demo_t *demo, float depth);
