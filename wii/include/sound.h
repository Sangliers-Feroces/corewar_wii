/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sound
*/

#pragma once

void sounds_init(void);

void play_new_sound(sounds_t index, int loop, float gain);
void play_new_music_ensure(musics_t index, int loop, float alt_gain);
void play_new_music(musics_t index, int loop, float gain);
void stop_current_music(void);
void stop_sound(sounds_t index);

void music_refresh_gain(musics_t index, float new_gain);
void sound_refresh_gain(sounds_t index, float new_gain);
void refresh_sound_volume(void);

void pause_all_sound(void);
void unpause_all_sound(void);

void sounds_quit(void);
