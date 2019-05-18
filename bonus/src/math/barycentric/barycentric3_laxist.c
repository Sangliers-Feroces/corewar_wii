/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** optiiiiiii rtx
*/

#include "headers.h"

static int is_float_in_0_1(double value)
{
    double laxistness = 0.01;

    return (value >= -laxistness) && (value <= 1.0 + (laxistness));
}

int is_point_in_triangle_laxist(dvec3 p, dvec3 *triangle)
{
    dvec3 bar = barycentric3(p, triangle);

    return (is_float_in_0_1(bar.x) && is_float_in_0_1(bar.y) &&
    is_float_in_0_1(bar.z));
}

int is_barycentric_valid_laxist(dvec3 bar)
{
    return (is_float_in_0_1(bar.x) && is_float_in_0_1(bar.y) &&
    is_float_in_0_1(bar.z));
}
