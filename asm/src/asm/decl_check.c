/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

asm_decl_arg_type_t asm_decl_type_get_short(asm_decl_arg_type_t decl_type)
{
    if (decl_type == ASM_DECL_ARG_IMMEDIATE_LABEL)
        return ASM_DECL_ARG_IMMEDIATE;
    else
        return decl_type;
}

static int is_arg_type_valid(asm_decl_arg_type_t decl_type,
asm_arg_type_t op_type)
{
    return op_type & (1 << asm_decl_type_get_short(decl_type));
}

static void check_args_type(asm_op_decl_t decl, asm_op_t op)
{
    for (size_t i = 0; i < op.arg_count; i++)
        if (!is_arg_type_valid(decl.arg[i].type, op.arg_type[i]))
            error_line_exit(_line, "Wrong type for this arg", op.name);
}

void asm_check_decl(asm_op_decl_t decl, asm_op_t op)
{
    if (decl.arg_count < op.arg_count)
        error_line_exit(_line,
        "Not enough args for this instruction", op.name);
    if (decl.arg_count > op.arg_count)
        error_line_exit(_line, "Too much args for this instruction", op.name);
    check_args_type(decl, op);
}
