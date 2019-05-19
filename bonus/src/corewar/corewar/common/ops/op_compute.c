/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** op_compute
*/

#include "headers.h"

void add(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read(prog->op.arg[0]);
    int32_t arg1_val = vm_mem_ref_read(prog->op.arg[1]);

    prog->carry = (arg0_val + arg1_val) == 0;
    vm_mem_ref_write(prog->op.arg[2], (arg0_val + arg1_val));
}

void sub(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read(prog->op.arg[0]);
    int32_t arg1_val = vm_mem_ref_read(prog->op.arg[1]);

    prog->carry = (arg0_val - arg1_val) == 0;
    vm_mem_ref_write(prog->op.arg[2], (arg0_val - arg1_val));
}

void and(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read(prog->op.arg[0]);
    int32_t arg1_val = vm_mem_ref_read(prog->op.arg[1]);

    prog->carry = (arg0_val & arg1_val) == 0;
    vm_mem_ref_write(prog->op.arg[2], (arg0_val & arg1_val));
}

void or(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read(prog->op.arg[0]);
    int32_t arg1_val = vm_mem_ref_read(prog->op.arg[1]);

    prog->carry = (arg0_val | arg1_val) == 0;
    vm_mem_ref_write(prog->op.arg[2], (arg0_val | arg1_val));
}

void xor(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read(prog->op.arg[0]);
    int32_t arg1_val = vm_mem_ref_read(prog->op.arg[1]);

    prog->carry = (arg0_val ^ arg1_val) == 0;
    vm_mem_ref_write(prog->op.arg[2], (arg0_val ^ arg1_val));
}