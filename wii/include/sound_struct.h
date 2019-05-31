/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sound_struct
*/

#pragma once

typedef enum {
    MUSICS_MENU,
    MUSICS_VALVE,
    MUSICS_BOSS,
    MUSICS_END,
    NO_MUSIC
} musics_t;

typedef enum {
    SOUNDS_SELECT,
    SOUNDS_MOVE_MENU,
    SOUNDS_WATER,
    SOUNDS_FOREST,
    SOUNDS_END
} sounds_t;

typedef struct {
    sounds_t index;
    char *path;
}  sounds_decs_t;

typedef struct {
    musics_t index;
    char *path;
}  musics_decs_t;

typedef struct {
    //sfMusic *sample;
    float gain;
} music_track_t;

typedef struct {
    //sfSound *sample;
    float gain;
} sound_strack_t;

typedef struct {
    musics_t curr_music;
    float master_vol;
    float music_vol;
    float sound_vol;
    //sfSoundBuffer *sb[SOUNDS_END];
    music_track_t musics[MUSICS_END];
    sound_strack_t sounds[SOUNDS_END];
} sound_t;
