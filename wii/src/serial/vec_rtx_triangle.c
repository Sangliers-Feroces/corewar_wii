/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

vec_rtx_triangle* vec_rtx_triangle_create(void)
{
    vec_rtx_triangle *res =
    (vec_rtx_triangle*)malloc_safe(sizeof(vec_rtx_triangle));

    *res = (vec_rtx_triangle){0, 0, NULL, NULL};
    return res;
}

static void vec_realloc(vec_rtx_triangle *vec)
{
    size_t cur = vec->allocated;
    rtx_triangle **new_triangle;

    vec->allocated += OCTREE_ALLOC_STEP;
    new_triangle = (rtx_triangle**)malloc_safe(vec->allocated *
    sizeof(rtx_triangle*));
    for (size_t i = 0; i < cur; i++)
        new_triangle[i] = vec->triangle[i];
    free(vec->triangle);
    vec->triangle = new_triangle;
}

void vec_rtx_triangle_add(vec_rtx_triangle *vec, rtx_triangle *to_add)
{
    size_t cur = vec->count++;

    if (vec->count > vec->allocated)
        vec_realloc(vec);
    vec->triangle[cur] = to_add;
    vec->triangle[cur]->root = vec;
    vec->triangle[cur]->root_ndx = cur;
}
