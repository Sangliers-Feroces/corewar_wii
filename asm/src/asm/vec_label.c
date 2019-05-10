/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

vec_asm_label_t vec_asm_label_init(void)
{
    vec_asm_label_t res;

    res.count = 0;
    res.allocated = 0;
    res.label = NULL;
    return res;
}

void vec_asm_label_destroy(vec_asm_label_t vec)
{
    for (size_t i = 0; i < vec.count; i++)
        free(vec.label[i].name);
    free(vec.label);
}

static int is_label_dup(vec_asm_label_t *vec, asm_label_t to_add)
{
    for (size_t i = 0; i < vec->count; i++)
        if (streq(vec->label[i].name, to_add.name))
            return 1;
    return 0;
}

void vec_asm_label_add(vec_asm_label_t *vec, asm_label_t to_add)
{
    size_t cur;

    if (is_label_dup(vec, to_add))
        error_line_exit(_line, "Multiple label declaration", to_add.name);
    cur = vec->count++;
    if (vec->count > vec->allocated) {
        vec->allocated += 16;
        vec->label =
        (asm_label_t*)realloc(vec->label, vec->allocated * sizeof(asm_label_t));
    }
    vec->label[cur] = to_add;
}
