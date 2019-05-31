/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sound_gain
*/

#include "headers.h"

void sound_refresh_gain(sounds_t index, float new_gain)
{
    _demo->sounds.sounds[index].gain = new_gain;
}

void music_refresh_gain(musics_t index, float new_gain)
{
    _demo->sounds.musics[index].gain = new_gain;
}

void refresh_sound_volume(void)
{
    /*for (int i = 0; i < MUSICS_END; i++)
        sfMusic_setVolume(_demo->sounds.musics[i].sample,
        (_demo->sounds.musics[i].gain * _demo->sounds.music_vol) *
        _demo->sounds.master_vol);
    for (int i = 0; i < SOUNDS_END; i++)
        sfSound_setVolume(_demo->sounds.sounds[i].sample,
        (_demo->sounds.sounds[i].gain * _demo->sounds.sound_vol) *
        _demo->sounds.master_vol);*/
}

void unpause_all_sound(void)
{
    /*for (int i = 0; i < SOUNDS_END; i++)
        sfSound_play(_demo->sounds.sounds[i].sample);*/
}

void pause_all_sound(void)
{
    /*for (int i = 0; i < SOUNDS_END; i++)
        sfSound_pause(_demo->sounds.sounds[i].sample);*/
}
