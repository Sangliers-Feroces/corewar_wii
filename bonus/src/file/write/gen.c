/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void file_write_int(file_write_t *file, int value)
{
    file_write(file, &value, sizeof(int));
}

void file_write_string(file_write_t *file, const char *value)
{
    size_t size = strlen(value) + 1;

    file_write_actual(file, &size, sizeof(size_t));
    file_write_actual(file, value, size);
}

void file_write_dvec3(file_write_t *file, dvec3 value)
{
    file_write(file, &value, sizeof(dvec3));
}
