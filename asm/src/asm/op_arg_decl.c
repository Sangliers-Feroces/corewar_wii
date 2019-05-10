/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

static void check_value_boundaries(asm_decl_arg_type_t type, size_t value)
{
    switch (type) {
    case ASM_DECL_ARG_REGISTER:
        if (!((value >= 1) && (value <= 16)))
            error_line_exit(_line, "Overflow register", "must be in [1-16]");
        break;
    case ASM_DECL_ARG_IMMEDIATE:
        if (!(((ssize_t)value >= INT32_MIN) && ((ssize_t)value <= INT32_MAX)))
            warning_line(_line, "Overflow for immediate value",
            "must be in [-2^31, 2^32 - 1]");
        break;
    case ASM_DECL_ARG_POINTER:
        if (!(((ssize_t)value >= INT16_MIN) && ((ssize_t)value <= INT16_MAX)))
            warning_line(_line, "Overflow for relative value",
            "must be in [-2^16, 2^16 - 1]");
        break;
    default:
        break;
    }
}

asm_decl_arg_t asm_op_arg_decl_init(asm_decl_arg_type_t type, size_t value)
{
    asm_decl_arg_t res;

    check_value_boundaries(type, value);
    res.type = type;
    res.value = value;
    res.label = NULL;
    return res;
}

asm_decl_arg_t asm_op_arg_decl_init_label(const char *label)
{
    asm_decl_arg_t res;

    res.type = ASM_DECL_ARG_IMMEDIATE_LABEL;
    res.value = 0;
    res.label = label;
    return res;
}
