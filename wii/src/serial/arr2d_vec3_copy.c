/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

arr2d_dvec3_t arr2d_dvec3_copy(arr2d_dvec3_t to_copy)
{
    arr2d_dvec3_t res = arr2d_dvec3_create(to_copy.w, to_copy.h);

    memcpy(res.dvec3, to_copy.dvec3, res.w * res.h * sizeof(dvec3));
    return res;
}

arr2d_dvec3_t arr2d_dvec3_copy_rect(arr2d_dvec3_t to_copy, srect area)
{
    arr2d_dvec3_t res = arr2d_dvec3_create(area.s.x, area.s.y);

    for (ssize_t i = 0; i < area.s.y; i++)
        for (ssize_t j = 0; j < area.s.x; j++)
            res.dvec3[i * res.w + j] =
            to_copy.dvec3[(area.p.y + i) * to_copy.w + area.p.x + j];
    return res;
}
