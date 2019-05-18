/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

void vec_rtx_triangle_destroy(vec_rtx_triangle *vec)
{
    while (vec->count > 0)
        rtx_triangle_destroy(vec->triangle[vec->count - 1]);
    free(vec->triangle);
    free(vec);
}

void vec_rtx_triangle_free(vec_rtx_triangle *vec)
{
    free(vec->triangle);
    free(vec);
}

void vec_rtx_triangle_flush(vec_rtx_triangle *vec)
{
    if (vec->count > 0)
        return;
    free(vec->triangle);
    vec->triangle = NULL;
    vec->allocated = 0;
}
