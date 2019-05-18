/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** settings_entities
*/

#include "headers.h"

static void set_checkbox(void)
{
    entity_constructor(&_iu.settings.entities[SETTINGS_CB_SCREEN],
    (entity2_param_t){ IUTEX_SETTINGS_CB_EMPTY,
    (rect_t){{0.50f, 0.17f}, {0.1f, 0.15f}}, -0.998});
    entity_constructor(&_iu.settings.entities[SETTINGS_CB_HINT],
    (entity2_param_t){ IUTEX_SETTINGS_CB_EMPTY,
    (rect_t){{0.50f, -0.13f}, {0.1f, 0.15f}}, -0.998});
}

void setting_set_entities(void)
{
    entity_constructor(&_iu.settings.entities[SETTINGS_BG], (entity2_param_t){
    IUTEX_SETTINGS_BG, (rect_t){{-1.0f, -1.0f}, {2.0f, 2.0f}}, -0.997});
    entity_constructor(&_iu.settings.entities[SETTINGS_VOL_MAST],
    (entity2_param_t){IUTEX_SETTINGS_VOLUME,
    (rect_t){{-0.83f, 0.13f}, {0.6f, 0.2f}}, -0.998});
    entity_constructor(&_iu.settings.entities[SETTINGS_VOL_MUSIC],
    (entity2_param_t){IUTEX_SETTINGS_VOLUME,
    (rect_t){{-0.83f, -0.23f}, {0.6f, 0.2f}}, -0.998});
    entity_constructor(&_iu.settings.entities[SETTINGS_VOL_SOUND],
    (entity2_param_t){IUTEX_SETTINGS_VOLUME,
    (rect_t){{-0.83f, -0.56f}, {0.6f, 0.2f}}, -0.998});
    setting_set_slider();
    set_checkbox();
}

void slider_free(void)
{
    for (int i = SETTINGS_VOL_MAST; i < SETTINGS_VOL_SOUND + 1; i++)
        free(_iu.settings.entities[i].slider);
}
