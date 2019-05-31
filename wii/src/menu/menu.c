/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** menu
*/

#include "headers.h"

void menu_display_help(void)
{
    while (demo_poll_events(_demo) && !_demo->input.key_press[KEY_ESC]) {
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //glUseProgram(_demo->shader[SHADER_IU].program);
        iu_entity_draw(_iu.help);
        //sfRenderWindow_display(_demo->win.window);
    }
}

void menu_init(menu_t *menu)
{
    DIR *rep = opendir("./maps");

    _iu.data.is_focus = 1;
    demo_update_cursor_visibility(_demo);
    menu->edited_setting = 0;
    menu->first_save = 0;
    menu->state = -1;
    menu->branch = MENU_BRANCH_ROOT;
    menu_set_entities(menu);
    if (rep == NULL)
        menu->first_save = 1;
    menu->menu_choice = menu->first_save;
}

void menu_quit(menu_t *menu)
{
    (void)menu;
    stop_current_music();
    _iu.data.is_focus = 0;
}

int start(demo_t *demo)
{
    menu_t menu;

    menu_init(&menu);
    if (!_iu.data.skip_intro)
        if (!intro())
            return 0;
    _iu.data.skip_intro = 1;
    play_new_music(MUSICS_MENU, 1, 100);
    if (!menu_loop(demo, &menu)) {
        menu_quit(&menu);
        return 0;
    }
    menu_quit(&menu);
    return 1;
}
