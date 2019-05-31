/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** settings_loop
*/

#include "headers.h"

/*void display_x(demo_t *demo)//c'est pour le debug
{
    vec2 screen = {demo->win.w , demo->win.h};
    vec2 mouse_posf = {demo->mouse.mouse_pos.x, demo->mouse.mouse_pos.y};
    vec2 relative_mouse_pos;

    relative_mouse_pos = vec2_muls(
    vec2_subs(vec2_div(mouse_posf, screen), 0.5f), 2.0f);
    relative_mouse_pos.y *= -1.0;
    printf("x : %f || y : %f\n", relative_mouse_pos.x, relative_mouse_pos.y);
}*/

static void refresh_checkbox(void)
{
    if (_iu.settings.screen_state == FULLSCREEN)
        _iu.settings.entities[SETTINGS_CB_SCREEN].index
        = IUTEX_SETTINGS_CB_FULL;
    else
        _iu.settings.entities[SETTINGS_CB_SCREEN].index
        = IUTEX_SETTINGS_CB_EMPTY;
    if (_iu.settings.hints_state == WITH_HINT)
        _iu.settings.entities[SETTINGS_CB_HINT].index
        = IUTEX_SETTINGS_CB_FULL;
    else
        _iu.settings.entities[SETTINGS_CB_HINT].index
        = IUTEX_SETTINGS_CB_EMPTY;
}

static void setting_draw(s_screen_t warning)
{
    refresh_checkbox();
    for (int i = 0; i < SETTINGS_END; i++) {
        iu_entity_draw(_iu.settings.entities[i]);
        if (_iu.settings.entities[i].pattern == PATTERN_SLIDE_BUTTON)
            iu_entity_draw((*_iu.settings.entities[i].slider));
    }
    if (_iu.settings.screen_state != warning)
        vg_text_draw(_iu.data.error_message[WARNING_SCREEN_MODIF]);
}

void setting_loop(void)
{
    settings_t before = _iu.settings;

    _iu.data.is_focus = 1;
    demo_update_cursor_visibility(_demo);
    //glBindFramebuffer(GL_FRAMEBUFFER, 0);
    do {
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        setting_draw(before.screen_state);
        //sfRenderWindow_display(_demo->win.window);
    } while (setting_poll_event());
    _iu.data.is_focus = 0;
    demo_update_cursor_visibility(_demo);
    if (_iu.settings.screen_state != before.screen_state)
        _demo->win.do_reboot = 1;
}
