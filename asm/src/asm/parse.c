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

static void remove_comment(vec_str_t *vec)
{
    for (size_t i = 0; i < vec->count; i++)
        if (streq(vec->str[i], "#"))
            return vec_str_reduce(vec, i);
}

static void try_get_label(asm_t *a, vec_str_t t, size_t *i)
{
    if ((*i) + 2 > t.count)
        return;
    if (!streq(t.str[(*i) + 1], ":"))
        return;
    vec_asm_label_add(&a->labels, asm_label_create(t.str[*i], a->out.size));
    (*i) += 1;
}

void asm_parse_line(asm_t *a, const char *line)
{
    vec_str_t tokens = str_sep(line);
    size_t i = 0;

    remove_comment(&tokens);
    for (size_t i = 0; i < tokens.count; i++)
        printf("'%s', ", tokens.str[i]);
    printf("\n");
    try_get_label(a, tokens, &i);
    vec_str_destroy(tokens);
}
