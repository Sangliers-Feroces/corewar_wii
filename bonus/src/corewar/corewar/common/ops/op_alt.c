/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** op_alt
*/

#include "headers.h"

void zjmp(prog_t *prog)
{
    int32_t index = (vm_mem_ref_read(prog->op.arg[0]) % PTR_RANGE);

    if (prog->carry)
        prog->pc = prog->op.pc + index;
}

void ldi(prog_t *prog)
{
    int32_t s =
    vm_mem_ref_read(prog->op.arg[0]) + vm_mem_ref_read(prog->op.arg[1]);
    int32_t res = vm_mem_ref_read(vm_mem_ref_init_rel(s));

    prog->carry = (res == 0);
    vm_mem_ref_write(prog->op.arg[2], res);
}

void sti(prog_t *prog)
{
    int32_t s =
    vm_mem_ref_read(prog->op.arg[1]) + vm_mem_ref_read(prog->op.arg[2]);

    vm_mem_ref_write(vm_mem_ref_init_rel(s), vm_mem_ref_read(prog->op.arg[0]));
}

void aff(prog_t *prog)
{
    int32_t char_ = vm_mem_ref_read(prog->op.arg[0]) % 256;

    my_putchar(char_);
}

void fork_(prog_t *prog)
{   
    int32_t offset = vm_mem_ref_read(prog->op.arg[0]);

    vm_fork(offset);
}
