/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** vg_text
*/

#pragma once

//vg_text
vg_text vg_text_create(char *str, char *optional_value);

void vg_text_set_position(vg_text *src, vec2 pos);
void vg_text_set_size(vg_text *src, vec2 size);
void vg_text_reset_str(vg_text *src, char *str, char *optional_value);
void vg_text_set_font(vg_text *src, font_list_t font_index);

void vg_text_draw(vg_text src);

//vg_dialogue
vg_dialogue vg_dialogue_create(int nb_text, text_index_t start);

void vg_dialogue_set_position(vg_dialogue *src, vec2 pos);
void vg_dialogue_set_size(vg_dialogue *src, vec2 size);
void vg_dialogue_set_choices(vg_dialogue *src, choices_arg_t arg);
void vg_dialogue_set_font(vg_dialogue *src, font_list_t font_index);

void vg_dialogue_draw(vg_dialogue *src);

void vg_dialogue_quit(void);

void iu_set_dialogue(void);
void iu_display_char(char c, rect_t pos, font_list_t index);

//effects
void vg_next_mq(void);
void vg_no_effect(void);
void vg_effect_quit(void);
void vg_end_storie(void);
