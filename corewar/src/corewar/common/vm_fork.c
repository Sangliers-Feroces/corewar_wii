/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "headers.h"

static prog_t* prog_dup(prog_t *src)
{
    prog_t *res = prog_init();

    *res = *src;
    res->inst = malloc_safe(res->inst_size);
    memcpy_slow(res->inst, src->inst, res->inst_size);
    return res;
}

static int32_t generate_id(void)
{
    int32_t max;

    if (_vm.progs.count == 0)
        return 1;
    max = _vm.progs.prog[0]->id;
    for (size_t i = 0; i < _vm.progs.count; i++)
        if (_vm.progs.prog[i]->id > max)
            max = _vm.progs.prog[i]->id;
    return max + 1;
}

void vm_fork(int32_t offset)
{
    prog_t *fork = prog_dup(_vm.prog_running);

    fork->id = generate_id();
    fork->pc = _vm.prog_running->op.pc + offset % PTR_RANGE;
    vec_prog_add(&_vm.progs, fork);}

void vm_fork_nomod(int32_t offset)
{
    prog_t *fork = prog_dup(_vm.prog_running);

    fork->id = generate_id();
    fork->pc = _vm.prog_running->op.pc + offset;
    vec_prog_add(&_vm.progs, fork);}
