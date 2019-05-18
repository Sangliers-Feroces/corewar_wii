/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** iu_constructor
*/

#include "headers.h"

static void entity_set_new_rel(void)
{
    _iu.buttons[IUBUTTON_ELON].rel = IUREL_X;
}

static void entity_set_new_pattern(void)
{
    _iu.buttons[IUBUTTON_ELON].pattern = PATTERN_CLICK_BUTTON;
    _iu.settings.entities[SETTINGS_VOL_MAST].pattern = PATTERN_SLIDE_BUTTON;
    _iu.settings.entities[SETTINGS_VOL_MUSIC].pattern = PATTERN_SLIDE_BUTTON;
    _iu.settings.entities[SETTINGS_VOL_SOUND].pattern = PATTERN_SLIDE_BUTTON;
}

void entity_constructor(entity2_t *entity, entity2_param_t params)
{
    entity->index = params.index;
    entity->rect = params.rect;
    entity->depth = params.depth;
    entity->pattern = PATTERN_CLASSIC;
    entity->rel = IUREL_FULL;
    entity_set_new_rel();
    entity_set_new_pattern();
}
