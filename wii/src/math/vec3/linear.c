/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

float vec3_dot(vec3 a, vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float vec3_norm(vec3 vec)
{
    return sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}

float vec3_dist(vec3 a, vec3 b)
{
    return vec3_norm(vec3_sub(a, b));
}

vec3 vec3_cross(vec3 a, vec3 b)
{
    return (vec3){a.y * b.z - a.z * b.y, -(a.x * b.z - a.z * b.x),
    a.x * b.y - a.y * b.x};
}

vec3 vec3_normalize(vec3 vec)
{
    float dist = vec3_norm(vec);

    if (dist == 0.0f)
        return (vec3){0.0f, 0.0f, 0.0f};
    return (vec3){vec.x / dist, vec.y / dist, vec.z / dist};
}
