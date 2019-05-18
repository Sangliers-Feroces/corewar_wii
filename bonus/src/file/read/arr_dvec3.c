/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

arr_dvec3_t file_read_arr_dvec3(file_read_t *file)
{
    arr_dvec3_t res;

    res = arr_dvec3_create(file_read_size_t(file));
    file_read(file, res.dvec3, res.count * sizeof(dvec3));
    return res;
}

arr2d_dvec3_t file_read_arr2d_dvec3(file_read_t *file)
{
    size_t w = file_read_size_t(file);
    size_t h = file_read_size_t(file);
    arr2d_dvec3_t res = arr2d_dvec3_create(w, h);

    file_read(file, res.dvec3, res.w * res.h * sizeof(dvec3));
    return res;
}
