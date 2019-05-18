/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

vec_size3_t vec_size3_init(void)
{
    vec_size3_t res;

    res.count = 0;
    res.allocated = 0;
    res.size3 = NULL;
    return res;
}

void vec_size3_add(vec_size3_t *vec, size3 to_add)
{
    size_t cur = vec->count++;

    if (vec->count > vec->allocated) {
        vec->allocated += 256;
        vec->size3 =
        (size3*)realloc(vec->size3, vec->allocated * sizeof(size3));
    }
    vec->size3[cur] = to_add;
}

void vec_size3_flush(vec_size3_t *vec)
{
    vec->count = 0;
}

void vec_size3_destroy(vec_size3_t vec)
{
    free(vec.size3);
}
