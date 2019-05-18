/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** intro_tools
*/

#include "headers.h"

void music_check_breakpoint(int *display_vm)
{
    (void)display_vm;
    /*if (check_music_match_time((sfTime){3042000}, MUSICS_VALVE)) {
        _iu.intro[BG].index = IUTEX_INTRO_VM_BG;
        (*display_vm) = 1;
    }
    if (check_music_match_time((sfTime){8737000}, MUSICS_VALVE)) {
        _iu.intro[BG].index = IUTEX_INTRO_DEV;
        (*display_vm) = 0;
    }
    if (check_music_match_time((sfTime){11438000}, MUSICS_VALVE))
        _iu.intro[BG].index = IUTEX_INTRO_ENG;*/
}

/*int check_music_match_time(sfTime expected, musics_t index)
{
    sfTime current_time = sfMusic_getPlayingOffset(
    _demo->sounds.musics[index].sample);

    if (current_time.microseconds >= expected.microseconds)
        return 1;
    return 0;
}*/

size_t music_play_mod(size_t mod, musics_t index)
{
    (void)mod;
    (void)index;
    /*sfTime current_time = sfMusic_getPlayingOffset(
    _demo->sounds.musics[index].sample);

    return (current_time.microseconds % mod);*/
    return 0;
}
