/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static dvec3 mid_triangle(dvec3 a, dvec3 b, dvec3 c, double stren)
{
    double dist = dvec3_dist(b, c);
    dvec3 normal = dnormal3(a, b, c);
    dvec3 mid = dvec3_add(
    dvec3_divs(dvec3_add(b, c), 2.0),
    dvec3_muls(normal, (randf() - 0.5) * dist * stren));

    return mid;
}

static void split_mid(arr2d_dvec3_t *arr, arr2d_dvec3_t *new_arr, double stren)
{
    for (size_t i = 0; i < arr->h - 1; i++)
        for (size_t j = 0; j < arr->w - 1; j++) {
            new_arr->dvec3[(i * 2 + 1) * new_arr->w + (j * 2 + 1)] =
            mid_triangle(new_arr->dvec3[i * 2 * new_arr->w + j * 2],
            new_arr->dvec3[(i + 1) * 2 * new_arr->w + j * 2],
            new_arr->dvec3[i * 2 * new_arr->w + (j + 1) * 2], stren);
        }
}

static void split_borders(arr2d_dvec3_t *arr, arr2d_dvec3_t *new_arr,
double stren)
{
    for (size_t i = 0; i < arr->h - 1; i++)
        for (size_t j = 0; j < arr->w - 1; j++) {
            new_arr->dvec3[(i * 2 + 1) * new_arr->w + (j + 1) * 2] =
            mid_triangle(new_arr->dvec3[(i * 2 + 1) * new_arr->w + (j * 2 + 1)],
            new_arr->dvec3[i * 2 * new_arr->w + (j + 1) * 2],
            new_arr->dvec3[(i + 1) * 2 * new_arr->w + (j + 1) * 2], stren);
            new_arr->dvec3[(i + 1) * 2 * new_arr->w + j * 2 + 1] =
            mid_triangle(new_arr->dvec3[(i * 2 + 1) * new_arr->w + (j * 2 + 1)],
            new_arr->dvec3[(i + 1) * 2 * new_arr->w + (j + 1) * 2],
            new_arr->dvec3[(i + 1) * 2 * new_arr->w + j * 2], stren);
        }
}

void terrain_split(arr2d_dvec3_t *arr, double stren)
{
    arr2d_dvec3_t new_arr = arr2d_dvec3_create(arr->w * 2 - 1, arr->h * 2 - 1);

    for (size_t i = 0; i < arr->h; i++)
        for (size_t j = 0; j < arr->w; j++)
            new_arr.dvec3[i * 2 * new_arr.w + j * 2] =
            arr->dvec3[i * arr->w + j];
    split_mid(arr, &new_arr, stren);
    split_borders(arr, &new_arr, stren);
    for (size_t i = 0; i < arr->w - 1; i++)
        new_arr.dvec3[i * 2 + 1] = dvec3_divs(
        dvec3_add(new_arr.dvec3[i * 2], new_arr.dvec3[(i + 1) * 2]), 2.0);
    for (size_t i = 0; i < arr->h - 1; i++)
        new_arr.dvec3[(i * 2 + 1) * new_arr.w] =
        dvec3_divs(dvec3_add(new_arr.dvec3[i * 2 * new_arr.w],
        new_arr.dvec3[(i + 1) * 2 * new_arr.w]), 2.0);
    arr2d_dvec3_destroy(*arr);
    *arr = new_arr;
}
