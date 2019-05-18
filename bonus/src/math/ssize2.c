/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

ssize2 ssize2_add(ssize2 a, ssize2 b)
{
    return (ssize2){a.x + b.x, a.y + b.y};
}

ssize2 ssize2_sub(ssize2 a, ssize2 b)
{
    return (ssize2){a.x - b.x, a.y - b.y};
}

ssize2 ssize2_muls(ssize2 value, ssize_t mul)
{
    return (ssize2){value.x * mul, value.y * mul};
}

ssize2 ssize2_abs(ssize2 value)
{
    ssize2 res = {value.x < 0 ? -value.x : value.x,
    value.y < 0 ? -value.y : value.y};

    return res;
}

ssize_t ssize2_dist_sq_man(ssize2 a, ssize2 b)
{
    ssize2 cen = ssize2_abs(ssize2_sub(a, b));

    return MAX(cen.x, cen.y);
}
