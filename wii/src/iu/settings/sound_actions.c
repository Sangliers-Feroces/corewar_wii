/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sound_actions
*/

#include "headers.h"

void play_new_music_ensure(musics_t index, int loop, float alt_gain)
{
    (void)loop;
    _demo->sounds.musics[index].gain = alt_gain;
    if (_demo->sounds.curr_music != NO_MUSIC) {
        if (_demo->sounds.curr_music == index)
            return;
        //sfMusic_stop(_demo->sounds.musics[_demo->sounds.curr_music].sample);
    }
    /*sfMusic_setVolume(_demo->sounds.musics[index].sample,
    _demo->sounds.musics[index].gain);
    sfMusic_play(_demo->sounds.musics[index].sample);
    sfMusic_setLoop(_demo->sounds.musics[index].sample, loop);*/
    _demo->sounds.curr_music = index;
}

void play_new_music(musics_t index, int loop, float alt_gain)
{
    (void)loop;
    _demo->sounds.musics[index].gain = alt_gain;
    /*if (_demo->sounds.curr_music != NO_MUSIC)
        sfMusic_stop(_demo->sounds.musics[_demo->sounds.curr_music].sample);
    sfMusic_setVolume(_demo->sounds.musics[index].sample,
    _demo->sounds.musics[index].gain);
    sfMusic_play(_demo->sounds.musics[index].sample);
    sfMusic_setLoop(_demo->sounds.musics[index].sample, loop);*/
    _demo->sounds.curr_music = index;
}

void stop_current_music(void)
{
    /*if (_demo->sounds.curr_music != NO_MUSIC)
        sfMusic_stop(_demo->sounds.musics[_demo->sounds.curr_music].sample);*/
}

void stop_sound(sounds_t index)
{
    (void)index;
    //sfSound_stop(_demo->sounds.sounds[index].sample);
}

void play_new_sound(sounds_t index, int loop, float alt_gain)
{
    (void)loop;
    _demo->sounds.sounds[index].gain = alt_gain;
    /*sfSound_setVolume(_demo->sounds.sounds[index].sample,
    _demo->sounds.sounds[index].gain);
    sfSound_play(_demo->sounds.sounds[index].sample);
    sfSound_setLoop(_demo->sounds.sounds[index].sample, loop);*/
}
