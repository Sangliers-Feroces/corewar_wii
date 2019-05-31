/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** menu_draw
*/

#include "headers.h"

static void reset_cursor(menu_t *menu)
{
    menu->link[MENU_LINK_CURSOR].rect.p.y =
    (-0.30f + (menu->menu_choice * -0.1f));
}

void menu_draw(menu_t *menu)
{
    iu_entity_draw(menu->background[MENU_BG_MAIN]);
    for (int i = menu->first_save; i < MENU_LINK_END; i++)
        iu_entity_draw(menu->link[i]);
}

static void delete_maps(void)
{
    world_unload_map();
    system("rm -rf maps/");
    world_load_map();
}

static int state_ananlyse(demo_t *demo, menu_t *menu)
{
    switch (menu->state) {
        case MENU_LINK_NEW:
            delete_maps();
            _demo->quest.curr_main_quest = MAIN_QUEST_1;
            main_quest_start();
            _iu.dialogue_list[_demo->quest.quest[
            _demo->quest.curr_main_quest].first_dial].read_head = 0;
            return 1;
        case MENU_LINK_QUIT:
            return 0;
        case MENU_LINK_SETTING:
            setting_loop();
            return menu_loop(demo, menu);
        case MENU_LINK_CREDITS:
            menu_display_help();
            return menu_loop(demo, menu);
        default:
            return 1;
    };
}

int menu_loop(demo_t *demo, menu_t *menu)
{
    menu->state = 0;
    reset_cursor(menu);
    do {
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //glUseProgram(_demo->shader[SHADER_IU].program);
        menu_draw(menu);
        //sfRenderWindow_display(demo->win.window);
        reset_cursor(menu);
    } while (menu_poll_events(demo, menu));
    return (state_ananlyse(demo, menu));
}
