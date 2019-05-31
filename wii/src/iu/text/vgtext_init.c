/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** vgtext_init
*/

#include "headers.h"

vg_text vg_text_create(char *str, char *optional_value)
{
    vg_text res;

    res.str = str;
    if (optional_value)
        res.value = optional_value;
    else
        res.value = NULL;
    res.pos_size = (rect_t){{0.0f, 0.0f}, {0.03f, 0.04f}};
    res.font_index = FONT_MINECRAFT;
    return res;
}

void vg_text_set_position(vg_text *src, vec2 pos)
{
    src->pos_size.p.x = pos.x;
    src->pos_size.p.y = pos.y;
}

void vg_text_set_size(vg_text *src, vec2 size)
{
    src->pos_size.s.x = size.x;
    src->pos_size.s.y = size.y;
}

void vg_text_reset_str(vg_text *src, char *str, char *optional_value)
{
    if (str)
        src->str = str;
    if (optional_value)
        src->value = optional_value;
}

void vg_text_set_font(vg_text *src, font_list_t font_index)
{
    src->font_index = font_index;
}