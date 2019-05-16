/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** hidden stuff. don't look !
*/

#include "headers.h"

uint16_t swap16(uint16_t value)
{
    return ((value & 0xFF) << 8) | ((value & 0xFF00) >> 8);
}

uint32_t swap32(uint32_t value)
{
    return ((value & 0xFF) << 24) | ((value & 0xFF00) << 8) |
    ((value & 0xFF0000) >> 8) | ((value & 0xFF000000) >> 24);
}
