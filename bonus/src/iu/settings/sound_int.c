/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sound
*/

#include "headers.h"

/*static const sounds_decs_t sounds_arr[] = {
    {SOUNDS_SELECT, "res/musics/select.ogg"},
    {SOUNDS_MOVE_MENU, "res/musics/move.ogg"},
    {SOUNDS_WATER, "res/sfx/water.ogg"},
    {SOUNDS_FOREST, "res/sfx/forest.ogg"},
    {0, NULL}
};

static const musics_decs_t musics_arr[] = {
    {MUSICS_MENU, "res/musics/menu_music.ogg"},
    {MUSICS_VALVE, "res/musics/intro.ogg"},
    {MUSICS_BOSS, "res/musics/Persona 5 - Blooming Villain.ogg"},
    {0, NULL}
};*/

static void set_sound(void)
{
    /*for (int i = 0; i < SOUNDS_END; i++)
        _demo->sounds.sounds[i].sample = NULL;
    for (int i = 0; sounds_arr[i].path != NULL; i++) {
        _demo->sounds.sounds[i].sample = sfSound_create();
        _demo->sounds.sb[i] =
        sfSoundBuffer_createFromFile(sounds_arr[i].path);
        sfSound_setBuffer(_demo->sounds.sounds[i].sample, _demo->sounds.sb[i]);
    }
    for (int i = 0; i < SOUNDS_END; i++) {
        if (_demo->sounds.sounds[i].sample == NULL) {
            my_fd_putstr("Can't open sound ", 2);
            putnbr(i, 10, 0);
            my_fd_putchar('\n', 2);
            exit(84);
        }
    }*/
}

static void set_musics(void)
{
    /*for (int i = 0; i < MUSICS_END; i++)
        _demo->sounds.musics[i].sample = NULL;
    for (int i = 0; musics_arr[i].path != NULL; i++)
        _demo->sounds.musics[i].sample =
        sfMusic_createFromFile(musics_arr[i].path);
    for (int i = 0; i < MUSICS_END; i++) {
        if (_demo->sounds.musics[i].sample == NULL) {
            my_fd_putstr("Can't open music ", 2);
            putnbr(i, 10, 0);
            my_fd_putchar('\n', 2);
            exit(84);
        }
    }*/
}

void sounds_quit(void)
{
    /*for (int i = 0; i < MUSICS_END; i++)
        sfMusic_destroy(_demo->sounds.musics[i].sample);
    for (int i = 0; i < SOUNDS_END; i++) {
        sfSound_destroy(_demo->sounds.sounds[i].sample);
        sfSoundBuffer_destroy(_demo->sounds.sb[i]);
    }*/
}

void sounds_init(void)
{
    _demo->sounds.curr_music = NO_MUSIC;
    set_sound();
    set_musics();
    for (int i = 0; i < MUSICS_END; i++)
        _demo->sounds.musics[i].gain = 100.0f;
    for (int i = 0; i < SOUNDS_END; i++)
        _demo->sounds.sounds[i].gain = 100.0f;
}
