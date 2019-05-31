/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

float texture2f_get_max_lumel(texture2f *texture)
{
    float cur = 0.0f;
    float sum;

    for (size_t i = 0; i < texture->max_ndx; i++) {
        sum = texture->pixel[i].x + texture->pixel[i].y + texture->pixel[i].z;
        if (sum > cur)
            cur = sum;
    }
    return cur;
}
