/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

static const asm_op_t op_data[] = {
    {"live", 1, 1, {ASM_ARG_IMMEDIATE}, 10, 0, 1},
    {"ld", 2, 2, {ASM_ARG_NREGISTER, ASM_ARG_REGISTER}, 5, 0, 0},
    {"st", 3, 2, {ASM_ARG_REGISTER, ASM_ARG_LVALUE}, 5, 0, 0},
    {"add", 4, 3, {ASM_ARG_REGISTER, ASM_ARG_REGISTER, ASM_ARG_REGISTER}, 10,
    0, 0},
    {"sub", 5, 3, {ASM_ARG_REGISTER, ASM_ARG_REGISTER, ASM_ARG_REGISTER}, 10,
    0, 0},
    {"and", 6, 3, {ASM_ARG_ALL, ASM_ARG_ALL, ASM_ARG_REGISTER}, 6, 0, 0},
    {"or", 7, 3, {ASM_ARG_ALL, ASM_ARG_ALL, ASM_ARG_REGISTER}, 6, 0, 0},
    {"xor", 8, 3, {ASM_ARG_ALL, ASM_ARG_ALL, ASM_ARG_REGISTER}, 6, 0, 0},
    {"zjmp", 9, 1, {ASM_ARG_IMMEDIATE}, 20, 1, 1},
    {"ldi", 10, 3, {ASM_ARG_ALL, ASM_ARG_INDEX, ASM_ARG_REGISTER}, 25, 1, 0},
    {"sti", 11, 3, {ASM_ARG_REGISTER, ASM_ARG_ALL, ASM_ARG_INDEX}, 25, 1, 0},
    {"fork", 12, 1, {ASM_ARG_IMMEDIATE}, 800, 1, 1},
    {"lld", 13, 2, {ASM_ARG_NREGISTER, ASM_ARG_REGISTER}, 10, 0, 0},
    {"lldi", 14, 3, {ASM_ARG_ALL, ASM_ARG_INDEX, ASM_ARG_REGISTER}, 50, 0, 0},
    {"lfork", 15, 1, {ASM_ARG_IMMEDIATE}, 1000, 0, 1},
    {"aff", 16, 1, {ASM_ARG_REGISTER}, 2, 0, 0},
    {NULL, 0, 0, {0}, 0, 0, 0}
};

static size_t get_op_ndx(asm_op_decl_t decl)
{
    for (size_t i = 0; op_data[i].name != NULL; i++)
        if (streq(op_data[i].name, decl.name))
            return i;
    error_line_exit(_line, "Unknown mnemo", decl.name);
    return ~0ULL;
}

asm_op_t asm_decl_get_op(asm_op_decl_t decl)
{
    size_t ndx = get_op_ndx(decl);

    return op_data[ndx];
}
