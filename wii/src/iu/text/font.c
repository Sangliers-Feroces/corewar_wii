/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** font
*/

#include "headers.h"

void iu_set_font(void)
{
    _iu.fonts[FONT_MINECRAFT] = (font_t){IUTEX_FONT_MINECRAFT, 16, 16};
    _iu.fonts[FONT_VM] = (font_t){IUTEX_INTRO_VM, 1, 4};
}
