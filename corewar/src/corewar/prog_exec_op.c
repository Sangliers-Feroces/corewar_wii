/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "headers.h"

static void live(prog_t *prog)
{
    int32_t id = vm_mem_ref_read(prog->op.arg[0]);

    for (size_t i = 0; i < _vm.progs.count; i++)
        if (_vm.progs.prog[i].id == id)
            _vm.progs.prog[i].life = 0;
}

static void ld(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read(prog->op.arg[0]);

    if (!arg0_val)
        prog->carry = 1;
    else
        prog->carry = 0;
    vm_mem_ref_write(prog->op.arg[1], arg0_val);
}

void prog_exec_op(prog_t *prog)
{
    switch (prog->op.code) {
    case 1:
        return live(prog);
    }
}
