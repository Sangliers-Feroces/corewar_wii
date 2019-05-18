/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** setting_set_slider
*/

#include "headers.h"

static double ratio_to_norm_screen(double min, double max, double ratio)
{
    return min * (1.0 - ratio) + max * ratio;
}

static void set_slider_ext(double min, double max)
{
    _iu.settings.entities[SETTINGS_VOL_MUSIC].slider =
    malloc_safe(sizeof(entity2_t));
    entity_constructor(_iu.settings.entities[SETTINGS_VOL_MUSIC].slider,
    (entity2_param_t){
    IUTEX_SLIDER, (rect_t){{-0.325417f, -0.17f}, {0.05f, 0.05f}}, -0.999});
    _iu.settings.entities[SETTINGS_VOL_MUSIC].x_min = min;
    _iu.settings.entities[SETTINGS_VOL_MUSIC].x_max = max;
    _iu.settings.entities[SETTINGS_VOL_MUSIC].slider->rect.p.x =
    ratio_to_norm_screen(min, max, _demo->sounds.music_vol);
    _iu.settings.entities[SETTINGS_VOL_SOUND].slider =
    malloc_safe(sizeof(entity2_t));
    entity_constructor(_iu.settings.entities[SETTINGS_VOL_SOUND].slider,
    (entity2_param_t){
    IUTEX_SLIDER, (rect_t){{-0.325417f, -0.505f}, {0.05f, 0.05f}}, -0.999});
    _iu.settings.entities[SETTINGS_VOL_SOUND].x_min = min;
    _iu.settings.entities[SETTINGS_VOL_SOUND].x_max = max;
    _iu.settings.entities[SETTINGS_VOL_SOUND].slider->rect.p.x =
    ratio_to_norm_screen(min, max, _demo->sounds.sound_vol);
}

void setting_set_slider(void)
{
    double min = -0.77f;
    double max = -0.34f;

    _iu.settings.entities[SETTINGS_VOL_MAST].slider =
    malloc_safe(sizeof(entity2_t));
    entity_constructor(_iu.settings.entities[SETTINGS_VOL_MAST].slider,
    (entity2_param_t){
    IUTEX_SLIDER, (rect_t){{-0.325417f, 0.185f}, {0.05f, 0.05f}}, -0.999});
    _iu.settings.entities[SETTINGS_VOL_MAST].x_min = min;
    _iu.settings.entities[SETTINGS_VOL_MAST].x_max = max;
    _iu.settings.entities[SETTINGS_VOL_MAST].slider->rect.p.x =
    ratio_to_norm_screen(min, max, _demo->sounds.master_vol);
    set_slider_ext(min, max);
}