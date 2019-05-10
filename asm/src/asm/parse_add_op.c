/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

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

void asm_parse_add_op(asm_op_decl_t *res, vec_str_t t, size_t *i)
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
