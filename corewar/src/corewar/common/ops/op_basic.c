/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** op_basic
*/

#include "headers.h"

void prog_display(prog_t *prog)
{
    strout_num(prog->id);
    my_putstr("(");
    my_putstr(prog->name);
    my_putstr(")");
}

static void disp_live(prog_t *prog)
{
    if (!IS_PC)
        return;
    my_putstr("The player ");
    prog_display(prog);
    my_putstr(" is alive.\n");
}

void live(prog_t *prog)
{
    int32_t id = vm_mem_ref_read(prog->op.arg[0]);

    for (size_t i = 0; i < _vm.progs.count; i++)
        if (_vm.progs.prog[i]->id == id) {
            _vm.progs.prog[i]->life = 0;
            _vm.prog_live = prog;
            disp_live(prog);
        }
}

void ld(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read(prog->op.arg[0]);

    prog->carry = (arg0_val == 0);
    vm_mem_ref_write(prog->op.arg[1], arg0_val);
}

void st(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read(prog->op.arg[0]);

    vm_mem_ref_write(prog->op.arg[1], arg0_val);
}
