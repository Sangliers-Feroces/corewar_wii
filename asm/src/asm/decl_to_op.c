/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

static uint8_t get_arg_code(asm_op_decl_t decl)
{
    uint8_t res = 0;

    for (size_t i = 0; i < decl.arg_count; i++)
        res |= (asm_decl_type_get_short(decl.arg[i].type) + 1) << (6 - (i * 2));
    return res;
}

static void write_arg(asm_t *a, asm_decl_arg_t arg, size_t instr_size,
int is_index)
{
    switch (arg.type) {
    case ASM_DECL_ARG_REGISTER:
        return file_write_8(&a->out, arg.value);
    case ASM_DECL_ARG_IMMEDIATE:
    case ASM_DECL_ARG_IMMEDIATE_LABEL:
        if (arg.type == ASM_DECL_ARG_IMMEDIATE_LABEL)
            vec_asm_label_ref_add(&a->refs,
            asm_label_ref_create(arg.label, a->out.size, instr_size, is_index));
        if (is_index)
            return file_write_16(&a->out, swap16(arg.value));
        else
            return file_write_32(&a->out, swap32(arg.value));
    case ASM_DECL_ARG_POINTER:
        return file_write_16(&a->out, swap16(arg.value));
    }
}

void asm_decl_inline(asm_t *a, asm_op_decl_t decl)
{
    asm_op_t op = asm_decl_get_op(decl);
    size_t instr_size = a->out.size;

    asm_check_decl(decl, op);
    file_write_8(&a->out, op.code);
    if (!op.hide_arg_byte)
        file_write_8(&a->out, get_arg_code(decl));
    for (size_t i = 0; i < decl.arg_count; i++)
        write_arg(a, decl.arg[i], instr_size, op.is_index);
}
