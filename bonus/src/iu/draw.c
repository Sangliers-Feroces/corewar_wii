/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** iu_draw
*/

#include "headers.h"

void iu_draw_full_rel(iutex_t index, rect_t rect, float depth)
{
    (void)index;
    (void)rect;
    (void)depth;
    /*glUniform2fv(_demo->shader[SHADER_IU].uniform[0], 1, (glfloat *)&rect.p);
    glUniform2fv(_demo->shader[SHADER_IU].uniform[1], 1, (glfloat *)&rect.s);
    glUniform1f(_demo->shader[SHADER_IU].uniform[2], depth);
    glBindVertexArray(_iu.data.vertex_array);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _iu.textures[index]->id);
    glDrawArrays(GL_TRIANGLES, 0, 6);*/
}

void iu_entity_draw(entity2_t entity)
{
    iu_draw_full_rel(entity.index, entity_get_size(entity), entity.depth);
}

static void draw_current_dialogue(void)
{
    if (_demo->quest.curr_main_quest == NO_QUEST)
        _iu.current_dialogue = DIALOGUE_END;
    if (_iu.current_dialogue == DIALOGUE_END)
        return;
    vg_dialogue_draw(&_iu.dialogue_list[_iu.current_dialogue]);
}

static void refresh_fps(void)
{
    char buff[10];

    sprintf(buff, "%d FPS", _demo->win.fps_to_display);
    vg_text_reset_str(&_iu.data.fps_display, buff, NULL);
    vg_text_draw(_iu.data.fps_display);
}

void iu_display(void)
{
    if (_demo->quest.curr_main_quest != QUEST_END)
        quest_check_success(_demo->quest.curr_main_quest);
    //glUseProgram(_demo->shader[SHADER_IU].program);
    vec_msg_display(&_demo->buf.msgs);
    draw_current_dialogue();
    refresh_fps();
    if (_iu.data.is_invent)
        _iu.data.is_focus = 1;
    else
        _iu.data.is_focus = 0;
    if (_iu.data.iu_is_display) {
        iu_refresh_bar();
        for (int i = 0; i < IUENT_END; i++)
            iu_entity_draw(_iu.entities[i]);
        if (_demo->quest.curr_main_quest != QUEST_END)
            quest_display_current();
    }
}
