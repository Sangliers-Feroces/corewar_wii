/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "headers.h"

static void prog_next_op(prog_t *prog)
{
    prog->op = vm_read_prog_op(prog);
    prog->cycle = 0;
}

void prog_run(prog_t *prog)
{
    if (!prog->is_alive)
        return;
    if (prog->op.code == ~0ULL)
        prog_next_op(prog);
    prog->cycle++;
    prog->life++;
    if (prog->life >= 1536) {
        prog->is_alive = 0;
        return;
    }
    if (prog->cycle == prog->op.cycles) {
        prog_exec_op(prog);
        prog_next_op(prog);
    }
}
