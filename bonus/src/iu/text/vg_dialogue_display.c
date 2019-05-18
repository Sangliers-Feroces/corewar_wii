/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** vg_dialogue_display
*/

#include "headers.h"

static float get_canvas_size(rect_t target)
{
    return (target.p.x + target.s.x) - 0.05f;
}

static void display_choices(vg_dialogue *src)
{
    iu_display_str(src->choices_display[0].str,
    (rect_t){{_iu.cadre[src->cadre].rect.p.x + 0.05f,
    _iu.cadre[src->cadre].rect.p.y
    + src->pos_size.s.y}, {src->pos_size.s.x, src->pos_size.s.y}},
    src->font_index, 1);
    iu_display_str(src->choices_display[1].str,
    (rect_t){{_iu.cadre[src->cadre].rect.p.x + 0.05f,
    _iu.cadre[src->cadre].rect.p.y
    + (src->pos_size.s.y * 2) + 0.02f},
    {src->pos_size.s.x, src->pos_size.s.y}}, src->font_index, 1);
}

static void draw_choices(vg_dialogue *src)
{
    display_choices(src);
    if (_demo->input.key_press['A']) {
        _iu.current_dialogue = DIALOGUE_END;
        src->choices_display[0].ptr();
    }
    else if (_demo->input.key_press['E']) {
        _iu.current_dialogue = DIALOGUE_END;
        src->choices_display[1].ptr();
    }
    return;
}

void vg_dialogue_draw(vg_dialogue *src)
{
    iu_entity_draw(_iu.cadre[src->cadre]);
    iu_display_str(src->texts[src->read_head].str, src->pos_size,
    src->font_index, get_canvas_size(_iu.cadre[src->cadre].rect));
    if (src->read_head == src->nb_texts - 1 && src->choices)
        return draw_choices(src);
    if (_demo->input.key_press[KEY_ENTER]) {
        if (src->read_head == src->nb_texts - 1) {
            _iu.current_dialogue = DIALOGUE_END;
            return;
        }
        src->read_head++;
    }
}

void vg_dialogue_quit(void)
{
    for (int i = 0; i < DIALOGUE_END; i++) {
        free(_iu.dialogue_list[i].texts);
    }
}