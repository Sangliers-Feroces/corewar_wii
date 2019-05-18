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

void prog_exec_op(prog_t *prog)
{
    switch (prog->op.code) {
    case 1:
        return live(prog);
    }
}
