/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** op_nomod
*/

#include "headers.h"

void lld(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read_nomod(prog->op.arg[0]);

    prog->carry = (arg0_val == 0);
    vm_mem_ref_write_nomod(prog->op.arg[1], arg0_val);
}

void lldi(prog_t *prog)
{
    int32_t s =
    vm_mem_ref_read_nomod(prog->op.arg[0]) +
    vm_mem_ref_read_nomod(prog->op.arg[1]);
    int32_t res = vm_mem_ref_read_nomod(vm_mem_ref_init_rel(s));

    prog->carry = (res == 0);
    vm_mem_ref_write_nomod(prog->op.arg[2], res);
}

void lfork(prog_t *prog)
{   
    int32_t offset = vm_mem_ref_read_nomod(prog->op.arg[0]);

    vm_fork_nomod(offset);
}