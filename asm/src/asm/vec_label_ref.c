/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

vec_asm_label_ref_t vec_asm_label_ref_init(void)
{
    vec_asm_label_ref_t res;

    res.count = 0;
    res.allocated = 0;
    res.ref = NULL;
    return res;
}

void vec_asm_label_ref_destroy(vec_asm_label_ref_t vec)
{
    for (size_t i = 0; i < vec.count; i++)
        asm_label_ref_destroy(vec.ref[i]);
    free(vec.ref);
}

void vec_asm_label_ref_add(vec_asm_label_ref_t *vec, asm_label_ref_t to_add)
{
    size_t cur = vec->count++;

    if (vec->count > vec->allocated) {
        vec->allocated += 16;
        vec->ref =
        (asm_label_ref_t*)realloc(
        vec->ref, vec->allocated * sizeof(asm_label_ref_t));
    }
    vec->ref[cur] = to_add;
}
