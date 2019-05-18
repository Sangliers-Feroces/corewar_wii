/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** pause_entities
*/

#include "headers.h"

void set_pause_entities(void)
{
    entity_constructor(&_iu.pause.buttons[PAUSE_BUTTON_BG],
    (entity2_param_t){IUTEX_PAUSE_BG,
    (rect_t){{-1.0f, -1.0f}, {2.0f, 2.0f}}, -0.998f});
    entity_constructor(&_iu.pause.buttons[PAUSE_BUTTON_CONTINUE],
    (entity2_param_t){IUTEX_PAUSE_CONTINUE,
    (rect_t){{-0.13f, 0.21f}, {0.3f, 0.1f}}, -0.999f});
    entity_constructor(&_iu.pause.buttons[PAUSE_BUTTON_SETTING],
    (entity2_param_t){IUTEX_PAUSE_SETTING,
    (rect_t){{-0.13f, 0.01f}, {0.3f, 0.1f}}, -0.999f});
    entity_constructor(&_iu.pause.buttons[PAUSE_BUTTON_MENU],
    (entity2_param_t){IUTEX_PAUSE_MENU,
    (rect_t){{-0.08f, -0.19f}, {0.2f, 0.1f}}, -0.999f});
    entity_constructor(&_iu.pause.buttons[PAUSE_BUTTON_HELP],
    (entity2_param_t){IUTEX_MENU_HELP,
    (rect_t){{-0.04f, -0.345f}, {0.23f, 0.13f}}, -0.999f});
    entity_constructor(&_iu.pause.buttons[PAUSE_BUTTON_QUIT],
    (entity2_param_t){IUTEX_PAUSE_QUIT,
    (rect_t){{-0.08f, -0.50f}, {0.2f, 0.1f}}, -0.999f});
}