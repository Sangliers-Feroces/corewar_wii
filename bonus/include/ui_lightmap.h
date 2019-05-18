/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** ui_lightmap
*/

#pragma once

void ui_lightmap_set_buttons(void);

void ui_lightmap_display(demo_t *demo);

int ui_lm_poll_events(demo_t *demo);

void ui_lightmap_draw(void);

void compute_lightmap(demo_t *demo);

void refresh_display_nbr_array(display_nbr_array_t nbr_array,
size_t new_value);
