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
    size_t size = my_strlen(value) + 1;

    file_write_actual(file, &size, sizeof(size_t));
    file_write_actual(file, value, size);
}
