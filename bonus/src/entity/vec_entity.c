/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

vec_entity3_t vec_entity3_create(void)
{
    vec_entity3_t res;

    res.count = 0;
    res.allocated = 0;
    res.ent = NULL;
    return res;
}

size_t vec_entity3_add(vec_entity3_t *vec, entity3 *entity)
{
    size_t cur = vec->count++;
    entity3 **new_ent;

    if (vec->count > vec->allocated) {
        vec->allocated += 16;
        new_ent = (entity3**)malloc_safe(vec->allocated * sizeof(entity3*));
        for (size_t i = 0; i < cur; i++)
            new_ent[i] = vec->ent[i];
        free(vec->ent);
        vec->ent = new_ent;
    }
    vec->ent[cur] = entity;
    return cur;
}

void vec_entity3_destroy(vec_entity3_t vec)
{
    for (size_t i = 0; i < vec.count; i++)
        entity3_destroy(vec.ent[i]);
    free(vec.ent);
}
