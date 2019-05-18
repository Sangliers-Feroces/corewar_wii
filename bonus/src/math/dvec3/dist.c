/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

double dvec3_dist(dvec3 a, dvec3 b)
{
    return dvec3_norm(dvec3_sub(a, b));
}

double dvec3_dist_sq(dvec3 a, dvec3 b)
{
    dvec3 diff = dvec3_sub(a, b);

    return dvec3_dot(diff, diff);
}
