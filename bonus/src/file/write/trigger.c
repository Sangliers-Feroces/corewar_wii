/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void file_write_trigger_on_hit(file_write_t *file, trigger_on_hit_t value)
{
    file_write(file, &value, sizeof(trigger_on_hit_t));
}

void file_write_trigger(file_write_t *file, trigger_t *trigger)
{
    file_write_data_ref(file, trigger == NULL ?
    FILE_DATA_NULL : FILE_DATA_HERE);
    if (trigger == NULL)
        return;
    file_write_dvec3(file, trigger->min);
    file_write_dvec3(file, trigger->max);
    file_write_trigger_on_hit(file, trigger->on_hit);
}
