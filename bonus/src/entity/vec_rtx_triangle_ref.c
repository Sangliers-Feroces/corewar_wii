/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

vec_rtx_triangle_ref vec_rtx_triangle_ref_create(size_t count)
{
    vec_rtx_triangle_ref res;

    res.count = count;
    res.triangle = (rtx_triangle**)malloc_safe(count * sizeof(rtx_triangle*));
    return res;
}

vec_rtx_triangle_ref vec_rtx_triangle_ref_get_void(void)
{
    vec_rtx_triangle_ref res;

    res.count = 0;
    res.triangle = NULL;
    return res;
}

void vec_rtx_triangle_ref_destroy(vec_rtx_triangle_ref vec)
{
    for (size_t i = 0; i < vec.count; i++)
        rtx_triangle_destroy(vec.triangle[vec.count - 1 - i]);
    free(vec.triangle);
}
