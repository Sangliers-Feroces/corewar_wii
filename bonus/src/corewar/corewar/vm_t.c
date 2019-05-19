/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "headers.h"

vm_t vm_init(void)
{
    vm_t vm;

    vm.mem = (char*)malloc_safe(VM_SIZE);
    vm.owner = (int32_t*)malloc_safe(VM_SIZE * sizeof(int32_t));
    vm.hl = (char*)malloc_safe(VM_SIZE);
    vm.progs = vec_prog_init();
    vm.prog_running = NULL;
    vm.timeout = ~0UL;
    return vm;
}

void vm_destroy(vm_t *vm)
{
    free(vm->mem);
    free(vm->owner);
    free(vm->hl);
    vec_prog_destroy(&vm->progs);
}

int vm_set_prog(prog_t *prog)
{
    for (size_t i = 0; i < prog->inst_size; i++)
        if (_vm.owner[(prog->pc + i) % VM_SIZE] != 0)
            return 0;
    for (size_t i = 0; i < prog->inst_size; i++) {
        _vm.mem[(prog->pc + i) % VM_SIZE] = prog->inst[i];
        _vm.owner[(prog->pc + i) % VM_SIZE] = prog->id;
    }
    prog->r[0] = prog->id;
    return 1;
}

void vm_clean(void)
{
    for (size_t i = 0; i < VM_SIZE; i++) {
        _vm.mem[i] = 0;
        _vm.owner[i] = 0;
        _vm.hl[i] = 0;
    }
    for (size_t i = 0; i < _vm.progs.count; i++)
        prog_destroy(_vm.progs.prog[i]);
    _vm.progs.count = 0;
}

size_t vm_get_used(void)
{
    size_t res = 0;

    for (size_t i = 0; i < VM_SIZE; i++)
        res += _vm.owner[i] != 0;
    return res;
}

void vm_set_progs(vm_t *vm)
{
    size_t total_size = 0;
    size_t space;
    int32_t next_pc = 0;

    for (size_t i = 0; i < vm->progs.count; i++)
        total_size += vm->progs.prog[i].inst_size;
    space = (VM_SIZE - total_size) / vm->progs.count;
    if ((ssize_t)space < 0)
        error_mul_exit("Can't fit those programs",
        "they are too fat for the RAM (increase its size !)");
    vm_clean();
    for (size_t i = 0; i < vm->progs.count; i++) {
        if (vm->progs.prog[i].pc == ~0UL)
            vm->progs.prog[i].pc = next_pc;
        vm_set_prog(&vm->progs.prog[i]);
        next_pc += vm->progs.prog[i].inst_size + space;
    }
}
