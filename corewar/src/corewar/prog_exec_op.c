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

    prog->carry = (arg0_val == 0);
    vm_mem_ref_write(prog->op.arg[1], arg0_val);
}

static void st(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read(prog->op.arg[0]);

    vm_mem_ref_write(prog->op.arg[1], arg0_val);
}

static void add(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read(prog->op.arg[0]);
    int32_t arg1_val = vm_mem_ref_read(prog->op.arg[1]);

    prog->carry = (arg0_val + arg1_val) == 0;
    vm_mem_ref_write(prog->op.arg[2], (arg0_val + arg1_val));
}

static void subb(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read(prog->op.arg[0]);
    int32_t arg1_val = vm_mem_ref_read(prog->op.arg[1]);

    prog->carry = (arg0_val - arg1_val) == 0;
    vm_mem_ref_write(prog->op.arg[2], (arg0_val - arg1_val));
}

void prog_exec_op(prog_t *prog)
{
    switch (prog->op.code) {
    case 1:
        return live(prog);
    }
}
