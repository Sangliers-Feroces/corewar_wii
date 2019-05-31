/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** serialization for the GPU
*/

#include "headers.h"

static void serialize_triangle(rtx_triangle *triangle, gpu_serial_t *serial)
{
    for (size_t i = 0; i < 3; i++)
        gpu_serial_write_dvec3(serial, triangle->vertex[i]);
    gpu_serial_write(serial, 0);
    gpu_serial_write_dvec3(serial, triangle->normal);
}

int32_t vec_rtx_triangle_serialize(vec_rtx_triangle *vec, gpu_serial_t *serial)
{
    int32_t res = serial->size;

    gpu_serial_write(serial, vec->count);
    for (size_t i = 0; i < vec->count; i++)
        serialize_triangle(vec->triangle[i], serial);
    return res;
}
