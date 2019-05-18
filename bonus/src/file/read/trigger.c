/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

trigger_on_hit_t file_read_trigger_on_hit(file_read_t *file)
{
    trigger_on_hit_t res;

    file_read(file, &res, sizeof(trigger_on_hit_t));
    return res;
}

trigger_t* file_read_trigger(file_read_t *file)
{
    dvec3 min;
    dvec3 max;
    trigger_on_hit_t on_hit;

    if (file_read_data_ref(file) == FILE_DATA_NULL)
        return NULL;
    min = file_read_dvec3(file);
    max = file_read_dvec3(file);
    on_hit = file_read_trigger_on_hit(file);
    return trigger_create(min, max, on_hit);
}
