/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

dvec3 spherical_to_cartesian_z(dvec3 spherical)
{
    dvec3 res;

    res.x = -sin(spherical.y) * cos(spherical.x);
    res.z = cos(spherical.y) * cos(spherical.x);
    res.y = sin(spherical.x);
    return res;
}

dvec3 spherical_to_cartesian_z_to_x(dvec3 spherical)
{
    dvec3 res;

    res.x = -sin(spherical.y - M_PI_2);
    res.z = cos(spherical.y - M_PI_2);
    res.y = 0.0;
    return res;
}
