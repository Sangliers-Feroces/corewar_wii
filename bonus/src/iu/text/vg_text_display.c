/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** vg_text_display
*/

#include "headers.h"

static void iu_draw_font(entity2_param_t canvas, vec2 tex_pos, vec2 tex_size)
{
    (void)canvas;
    (void)tex_pos;
    (void)tex_size;
    /*glUniform2fv(_demo->shader[SHADER_FONT].uniform[0],
    1, (glfloat *)&tex_pos);
    glUniform2fv(_demo->shader[SHADER_FONT].uniform[1],
    1, (glfloat *)&tex_size);
    glUniform2fv(_demo->shader[SHADER_FONT].uniform[2],
    1, (glfloat *)&canvas.rect.p);
    glUniform2fv(_demo->shader[SHADER_FONT].uniform[3],
    1, (glfloat *)&canvas.rect.s);
    glUniform1f(_demo->shader[SHADER_FONT].uniform[4],
    canvas.depth);
    glDrawArrays(GL_TRIANGLES, 0, 6);*/
}

void iu_display_char(char c, rect_t pos, font_list_t index)
{
    float offset_x = 1.0f / _iu.fonts[index].cols;
    float offset_y = 1.0f / _iu.fonts[index].lines;
    float char_x_pos = c % _iu.fonts[index].cols;
    float char_y_pos = c / _iu.fonts[index].cols + 1.0f;

    iu_draw_font((entity2_param_t){_iu.fonts[index].index,
    (rect_t){{pos.p.x, pos.p.y}, {pos.s.x, pos.s.y}}, -0.999},
    (vec2){char_x_pos * offset_x, char_y_pos * offset_y},
    (vec2){offset_x, offset_y});
}

static float get_word_size(char *src, rect_t start)
{
    int len = 0;

    for (; src[len] != ' ' && src[len] != '\0'; len++);
    return (start.p.x + (start.s.x * len));
}

void iu_display_str(char *str, rect_t start, font_list_t font,
float canvas_size)
{
    float save_x = start.p.x;

    /*glUseProgram(_demo->shader[SHADER_FONT].program);
    glBindVertexArray(_iu.data.vertex_array);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _iu.textures[_iu.fonts[font].index]->id);*/
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && get_word_size(&str[i + 1], start) >= canvas_size) {
            i++;
            start.p.x = save_x;
            start.p.y -= start.s.y + 0.02;
        }
        iu_display_char(str[i], start, font);
        start.p.x += start.s.x;
    }
    //glUseProgram(_demo->shader[SHADER_IU].program);
}

void vg_text_draw(vg_text src)
{
    int str_len = my_strlen(src.str);

    iu_display_str(src.str, src.pos_size, src.font_index, 1.0f);
    if (src.value != NULL) {
        src.pos_size.p.x += (str_len * src.pos_size.s.x);
        iu_display_str(src.value, src.pos_size, src.font_index, 1.0f);
    }
}
