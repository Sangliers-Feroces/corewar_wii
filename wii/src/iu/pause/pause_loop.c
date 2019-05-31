/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** pause_loop
*/

#include "headers.h"

static void pause_draw(void)
{
    //glUseProgram(_demo->shader[SHADER_IU].program);
    for (int i = 0; i < PAUSE_BUTTON_END; i++) {
        iu_entity_draw(_iu.pause.buttons[i]);
    }
}

static void reset_scaling(void)
{
    if (_iu.pause.last_state) {
        _iu.pause.buttons[_iu.pause.last_state].rect.s =
        vec2_divs(_iu.pause.buttons[_iu.pause.last_state].rect.s, 1.2f);
        _iu.pause.buttons[_iu.pause.last_state].rect.p =
        vec2_adds(_iu.pause.buttons[_iu.pause.last_state].rect.p, 0.02f);
    }
}

void pause_refresh_str_scaling(void)
{
    _iu.pause.buttons[_iu.pause.state].rect.s =
    vec2_muls(_iu.pause.buttons[_iu.pause.state].rect.s, 1.2f);
    _iu.pause.buttons[_iu.pause.state].rect.p =
    vec2_subs(_iu.pause.buttons[_iu.pause.state].rect.p, 0.02f);
    if (_iu.pause.last_state && _iu.pause.last_state != _iu.pause.state) {
        _iu.pause.buttons[_iu.pause.last_state].rect.s =
        vec2_divs(_iu.pause.buttons[_iu.pause.last_state].rect.s, 1.2f);
        _iu.pause.buttons[_iu.pause.last_state].rect.p =
        vec2_adds(_iu.pause.buttons[_iu.pause.last_state].rect.p, 0.02f);
    }
    _iu.pause.last_state = _iu.pause.state;
}

static void analyse_statement(void)
{
    switch (_iu.pause.state) {
        case 2:
            setting_loop();
            reset_scaling();
            pause_loop();
            return;
        case 3:
            /*if (!start(_demo))
                sfRenderWindow_close(_demo->win.window);*/
            return;
        case 4:
            menu_display_help();
            reset_scaling();
            pause_loop();
            return;
        case 5:
            //sfRenderWindow_close(_demo->win.window);
            return;
    }
}

void pause_loop(void)
{
    _iu.pause.state = 1;
    _iu.pause.last_state = 0;
    pause_refresh_str_scaling();
    //glBindFramebuffer(GL_FRAMEBUFFER, 0);
    do {
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        world_render();
        pause_draw();
        //sfRenderWindow_display(_demo->win.window);
    } while (iu_pause_poll_event());
    analyse_statement();
    reset_scaling();
    _demo->input.key_press[KEY_ENTER] = 0;
}
