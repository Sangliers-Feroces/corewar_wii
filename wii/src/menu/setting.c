/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** menu_setting
*/

#include "headers.h"

/*int analyse_setting_input(demo_t *demo, menu_t *menu)
{
    for (int i = 0; i < SETTING_END; i++) {
        if (check_click_pos(sfMouse_getPosition((sfWindow *)demo->win.window),
        menu->setting[i], demo->win.w, demo->win.h)) {
            setting_buttons_effects(demo, menu, SETTING_RES + i);
        }
    }
    return 1;
}

void setting_draw(menu_t *menu)
{
    iu_entity_draw(menu->background[MENU_BG_SETTING]);
    for (int i = 0; i < SETTING_END; i++) {
        iu_entity_draw(menu->setting[i]);
        if (menu->setting[i].pattern == PATTERN_SLIDE_BUTTON) {
            iu_entity_draw((*menu->setting[i].slider));
        }
    }
}

void menu_setting_loop(demo_t *demo, menu_t *menu)
{
    while (menu_poll_events(demo, menu)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(_demo->shader[SHADER_IU].program);
        menu_draw(menu);
        setting_draw(menu);
        sfRenderWindow_display(demo->win.window);
    }
}*/