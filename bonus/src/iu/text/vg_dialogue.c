/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** vg_dialogue
*/

#include "headers.h"

vg_dialogue vg_dialogue_create(int nb_text, text_index_t start)
{
    vg_dialogue res;

    res.texts = (dialogue_text *)malloc_safe(sizeof(dialogue_text) * nb_text);
    for (int i = 0; i < nb_text && start + i != TEXT_END; i++)
        res.texts[i].str = _iu.text_src[start + i];
    res.nb_texts = nb_text;
    res.pos_size = (rect_t){{-0.45f, -0.80f}, {0.03f, 0.04f}};
    res.font_index = FONT_MINECRAFT;
    res.choices = 0;
    res.read_head = 0;
    res.read = 0;
    res.cadre = IUCADRE_BLACK;
    return res;
}

void vg_dialogue_set_position(vg_dialogue *src, vec2 pos)
{
    src->pos_size.p.x = pos.x;
    src->pos_size.p.y = pos.y;
}

void vg_dialogue_set_size(vg_dialogue *src, vec2 size)
{
    src->pos_size.s.x = size.x;
    src->pos_size.s.y = size.y;
}

void vg_dialogue_set_font(vg_dialogue *src, font_list_t font_index)
{
    src->font_index = font_index;
}

void vg_dialogue_set_choices(vg_dialogue *src, choices_arg_t arg)
{
    src->choices = 1;
    src->choices_display[0].str = arg.c1;
    src->choices_display[1].str = arg.c2;
    src->choices_display[0].ptr = arg.ptr1;
    src->choices_display[1].ptr = arg.ptr2;
}