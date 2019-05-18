/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** optiiiiiii rtx
*/

#include "headers.h"

dvec3 ray3_compute(ray3 ray, double t)
{
    return (dvec3){ray.p.x + ray.v.x * t, ray.p.y + ray.v.y * t,
    ray.p.z + ray.v.z * t};
}
