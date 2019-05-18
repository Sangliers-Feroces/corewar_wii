/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

vec_vec3_t vec_vec3_init(void)
{
    vec_vec3_t res;

    res.count = 0;
    res.allocated = 0;
    res.vec3 = NULL;
    return res;
}

void vec_vec3_add(vec_vec3_t *vec, vec3 to_add)
{
    size_t cur = vec->count++;

    if (vec->count > vec->allocated) {
        vec->allocated += 256;
        vec->vec3 = (vec3*)realloc(vec->vec3, vec->allocated * sizeof(vec3));
    }
    vec->vec3[cur] = to_add;
}

void vec_vec3_destroy(vec_vec3_t vec)
{
    free(vec.vec3);
}
