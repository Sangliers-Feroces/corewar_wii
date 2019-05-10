/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

static void try_get_label(asm_t *a, vec_str_t t, size_t *i)
{
    if (!vec_str_at(t, *i + 1, NULL))
        return;
    if (!streq(t.str[*i + 1], ":"))
        return;
    vec_asm_label_add(&a->labels, asm_label_create(t.str[*i], a->out.size));
    (*i) += 2;
}

static void check_colon(int *is_first, char *got, size_t *i)
{
    if (*is_first) {
        *is_first = 0;
    } else {
        if (!streq(got, ","))
            error_line_exit(_line,
            "Missing separator", "expected ',' between two args");
        (*i)++;
    }
}

static void try_get_op(asm_t *a, vec_str_t t, size_t *i)
{
    asm_op_decl_t op = {NULL, 0, {{}}};
    int is_first = 1;
    char *got;

    if (!vec_str_at(t, (*i)++, (char**)&op.name))
        return;
    if (asm_get_header(a, t, i, (char*)op.name))
        return;
    while (vec_str_at(t, *i, &got)) {
        check_colon(&is_first, got, i);
        asm_parse_add_op(&op, t, i);
        if (op.arg_count == 64)
            error_line_exit(_line,
            "Exceed arg count limit", "64");
    }
    asm_decl_inline(a, op);
}

void asm_parse_line(asm_t *a, const char *line)
{
    vec_str_t tokens = str_sep(line);
    size_t i = 0;

    asm_parse_remove_comment(&tokens);
    try_get_label(a, tokens, &i);
    try_get_op(a, tokens, &i);
    vec_str_destroy(tokens);
}
