/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
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

vm_mem_ref_t vm_mem_ref_get_null(void)
{
    vm_mem_ref_t res;

    res.type = VM_MEM_REF_MAIN;
    res.ptr = 0;
    res.is_short = 0;
    return res;
}

static vm_mem_ref_t get_mem_ref(prog_t *prog, size_t arg_type, int is_index)
{
    vm_mem_ref_t res;

    res.is_short = 0;
    switch (arg_type) {
    case 1:
        res.type = VM_MEM_REF_MAIN;
        res.ptr = (size_t)&prog->r[CLAMP(vm_read_uint8(prog->pc) - 1, 0, 15)];
        prog->pc++;
        break;
    case 2:
        res.type = VM_MEM_REF_VM_ABS;
        res.ptr = prog->pc;
        res.is_short = is_index;
        prog->pc += is_index ? 2 : 4;
        break;
    case 3:
        res.type = VM_MEM_REF_VM_REL;
        res.ptr = vm_read_uint16(prog->pc);
        prog->pc += 2;
    default:
        break;
    }
    return res;
}

static int get_op(uint8_t code, asm_op_t *res)
{
    for (size_t i = 0; op_data[i].name != NULL; i++)
        if (op_data[i].code == code) {
            *res = op_data[i];
            return 1;
        }
    return 0;
}

prog_op_t vm_read_prog_op(prog_t *prog)
{
    prog_op_t res;
    uint8_t arg_desc;
    size_t arg_type;
    asm_op_t op;

    res.pc = prog->pc;
    res.cycles = 1;
    res.arg_count = 0;
    res.code = vm_read_uint8(prog->pc++);
    if (!get_op(res.code, &op))
        return res;
    res.cycles = op.cycles;
    if (!op.hide_arg_byte)
        arg_desc = vm_read_uint8(prog->pc++);
    else
        arg_desc = 0x80;
    for (size_t i = 0; i < 4; i++) {
        arg_type = (arg_desc >> (3 - i) * 2) & 3;
        if (arg_type == 0)
            break;
        res.arg[res.arg_count++] =
        get_mem_ref(prog, arg_type, op.is_index);
    }
    if (res.arg_count != op.arg_count) {
        res.code = 0;
        res.cycles = 1;
    }
    prog->pc = prog->pc % VM_SIZE;
    return res;
}
