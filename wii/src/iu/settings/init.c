/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init
*/

#include "headers.h"

static const char *fmt = "fullscreen: %d\ndisplay hints: %d\n"
"master volume: %f\nmusic volume: %f\nsound volume: %f\n";

static void load_settings(settings_t *res)
{
    FILE *file = fopen("config.conf", "r");

    if (file == NULL)
        return;
    fscanf(file, fmt, &res->screen_state, &res->hints_state,
    &_demo->sounds.master_vol, &_demo->sounds.music_vol,
    &_demo->sounds.sound_vol);
    fclose(file);
}

static void store_settings(settings_t to_store)
{
    FILE *file = fopen("config.conf", "w+");

    if (file == NULL)
        return;
    fprintf(file, fmt, to_store.screen_state, to_store.hints_state,
    _demo->sounds.master_vol, _demo->sounds.music_vol,
    _demo->sounds.sound_vol);
    fclose(file);
}

settings_t settings_load(void)
{
    settings_t res;

    res.hints_state = WITH_HINT;
    res.screen_state = FULLSCREEN;
    _demo->sounds.master_vol = 1.0f;
    _demo->sounds.music_vol = 0.5f;
    _demo->sounds.sound_vol = 1.0f;
    load_settings(&res);
    return res;
}

void settings_init(void)
{
    _iu.settings = settings_load();
    setting_set_entities();
}

void settings_quit(void)
{
    store_settings(_iu.settings);
}
