/*
** EPITECH PROJECT, 2018
** 104インターセッくション
** File description:
** レンダー
*/

#include "headers.h"

uint32_t rtx(demo_t *demo, dvec3 ray)
{
    (void)demo;
    (void)ray;
    return 0;
}

dvec3 dvec3_interpolate(dvec3 a, dvec3 b, long double ratio)
{
    dvec3 res;
    long double ratio_inv = 1.0L - ratio;

    res.x = a.x * ratio_inv + b.x * ratio;
    res.y = a.y * ratio_inv + b.y * ratio;
    res.z = a.z * ratio_inv + b.z * ratio;
    return (res);
}
