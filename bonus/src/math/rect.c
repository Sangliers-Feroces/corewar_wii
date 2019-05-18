/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** rect
*/

#include "headers.h"

int rect_is_vec2_inside(rect_t rect, vec2 vec)
{
    return (vec.x >= rect.p.x && vec.x < (rect.p.x + rect.s.x)) &&
    (vec.y >= rect.p.y && vec.y < (rect.p.y + rect.s.y));
}
