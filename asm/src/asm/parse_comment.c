/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

static void vec_str_reduce(vec_str_t *vec, size_t new_size)
{
    for (size_t i = new_size; i < vec->count; i++)
        free(vec->str[i]);
    vec->count = new_size;
}

void asm_parse_remove_comment(vec_str_t *vec)
{
    for (size_t i = 0; i < vec->count; i++)
        if (streq(vec->str[i], "#"))
            return vec_str_reduce(vec, i);
}
