/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

vec_mesh_full_t vec_mesh_full_init(void)
{
    vec_mesh_full_t res;

    res.count = 0;
    res.allocated = 0;
    res.mesh = NULL;
    return res;
}

void vec_mesh_full_add(vec_mesh_full_t *vec, mesh_full_t *to_add)
{
    size_t cur = vec->count++;

    if (vec->count > vec->allocated) {
        vec->allocated += 8;
        vec->mesh = (mesh_full_t**)realloc(vec->mesh,
        vec->allocated * sizeof(mesh_full_t*));
    }
    vec->mesh[cur] = to_add;
}

void vec_mesh_full_destroy(vec_mesh_full_t vec)
{
    for (size_t i = 0; i < vec.count; i++)
        mesh_full_destroy(vec.mesh[i]);
    free(vec.mesh);
}
