/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

vec_vec2_t vec_vec2_init(void)
{
    vec_vec2_t res;

    res.count = 0;
    res.allocated = 0;
    res.vec2 = NULL;
    return res;
}

void vec_vec2_add(vec_vec2_t *vec, vec2 to_add)
{
    size_t cur = vec->count++;

    if (vec->count > vec->allocated) {
        vec->allocated += 256;
        vec->vec2 = (vec2*)realloc(vec->vec2, vec->allocated * sizeof(vec2));
    }
    vec->vec2[cur] = to_add;
}

void vec_vec2_destroy(vec_vec2_t vec)
{
    free(vec.vec2);
}
