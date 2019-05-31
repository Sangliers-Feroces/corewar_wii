/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** random
*/

#include "headers.h"

float get_random_float(float borne_min, float borne_max)
{
    return ( rand()/(double)RAND_MAX ) * (borne_max - borne_min) + borne_min;
}

int get_random_int(int borne_min, int borne_max)
{
    return rand()%(borne_max - borne_min) + borne_min;
}