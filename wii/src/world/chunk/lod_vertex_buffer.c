/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

vec_chunk_vertex_t vec_chunk_vertex_create(size_t count)
{
    vec_chunk_vertex_t res;

    res.count = count;
    res.vertex =
    (chunk_vertex_t*)malloc_safe(count * sizeof(chunk_vertex_t));
    return res;
}

void vec_chunk_vertex_destroy(vec_chunk_vertex_t vec)
{
    free(vec.vertex);
}

vec_chunk_dvertex_t vec_chunk_dvertex_create(size_t count)
{
    vec_chunk_dvertex_t res;

    res.count = count;
    res.dvertex =
    (chunk_dvertex_t*)malloc_safe(count * sizeof(chunk_dvertex_t));
    return res;
}

void vec_chunk_dvertex_destroy(vec_chunk_dvertex_t vec)
{
    free(vec.dvertex);
}
