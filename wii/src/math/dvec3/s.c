/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

dvec3 dvec3_adds(dvec3 vec, double value)
{
    return (dvec3){vec.x + value, vec.y + value, vec.z + value};
}
