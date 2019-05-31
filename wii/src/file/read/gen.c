/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

int file_read_int(file_read_t *file)
{
    int res;

    file_read(file, &res, sizeof(int));
    return res;
}

char* file_read_string(file_read_t *file)
{
    size_t size;
    char *res;

    file_read_actual(file, &size, sizeof(size_t));
    file->i -= sizeof(size_t);
    res = (char*)malloc_safe(size);
    file_read(file, res, size);
    return res;
}

dvec3 file_read_dvec3(file_read_t *file)
{
    dvec3 res;

    file_read(file, &res, sizeof(dvec3));
    return res;
}
