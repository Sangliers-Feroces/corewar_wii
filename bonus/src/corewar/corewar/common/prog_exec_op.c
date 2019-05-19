/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "headers.h"

static void prog_exec_op_ext(prog_t *prog)
{
    switch (prog->op.code) {
    case 9:
        return zjmp(prog);
    case 10:
        return ldi(prog);
    case 11:
        return sti(prog);
    case 12:
        return fork_(prog);
    case 13:
        return lld(prog);
    case 14:
        return lldi(prog);
    case 15:
        return lfork(prog);
    case 16:
        return aff(prog);
    }
}

void prog_exec_op(prog_t *prog)
{
    switch (prog->op.code) {
    case 1:
        return live(prog);
    case 2:
        return ld(prog);
    case 3:
        return st(prog);
    case 4:
        return add(prog);
    case 5:
        return sub(prog);
    case 6:
        return and(prog);
    case 7:
        return or(prog);
    case 8:
        return xor(prog);
    default:
        return prog_exec_op_ext(prog);
    }
}
