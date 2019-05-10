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
    if (!vec_str_at(t, *i + 1, NULL))
        return;
    if (!streq(t.str[*i + 1], ":"))
        return;
    vec_asm_label_add(&a->labels, asm_label_create(t.str[*i], a->out.size));
    (*i) += 2;
}

static void add_op_imm(asm_op_decl_t *res, vec_str_t t, size_t *i)
{
    char *got;

    if (!vec_str_at(t, (*i)++, &got))
        error_line_exit(_line, "Missing token after immediate character",
        "got '%'");
    if (streq(got, ":")) {
        if (!vec_str_at(t, (*i)++, &got))
            error_line_exit(_line, "Missing label after label character",
            "got ':'");
        res->arg[res->arg_count++] =
        asm_op_arg_decl_init_label(got);
    } else
        res->arg[res->arg_count++] =
        asm_op_arg_decl_init(ASM_DECL_ARG_IMMEDIATE, size_t_from_str(got));
}

static void add_op_reg(asm_op_decl_t *res, const char *token)
{
    res->arg[res->arg_count++] =
    asm_op_arg_decl_init(ASM_DECL_ARG_REGISTER, size_t_from_str(&token[1]));
}

static void add_op_ptr(asm_op_decl_t *res, const char *token)
{
    res->arg[res->arg_count++] =
    asm_op_arg_decl_init(ASM_DECL_ARG_POINTER, size_t_from_str(token));
}

static void add_op(asm_op_decl_t *res, vec_str_t t, size_t *i)
{
    char *got;

    if (!vec_str_at(t, (*i)++, &got))
        error_line_exit(_line, "Missing arg after separator", NULL);
    if (streq(got, "%"))
        add_op_imm(res, t, i);
    else if (got[0] == 'r')
        add_op_reg(res, got);
    else
        add_op_ptr(res, got);
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
        if (is_first) {
            is_first = 0;
        } else {
            if (!streq(got, ","))
                error_line_exit(_line,
                "Missing separator", "expected ',' between two args");
            (*i)++;
        }
        add_op(&op, t, i);
        if (op.arg_count == 64)
            error_line_exit(_line,
            "Exceed arg count limit", "64");
    }
    printf("%zu args\n", op.arg_count);
    for (size_t i = 0; i < op.arg_count; i++)
        printf("arg#%zu: type: %d, value: %zd, label: '%s'\n", i, op.arg[i].type, op.arg[i].value, op.arg[i].label);
    printf("\n");
    asm_decl_inline(a, op);
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
    try_get_op(a, tokens, &i);
    vec_str_destroy(tokens);
}
