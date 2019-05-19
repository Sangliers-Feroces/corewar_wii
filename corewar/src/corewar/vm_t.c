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
    vm.progs = vec_prog_init();
    vm.prog_running = NULL;
    vm.timeout = VM_NULL_HANDLE;
    for (size_t i = 0; i < VM_SIZE; i++)
        vm.mem[i] = 0;
    return vm;
}

void vm_destroy(vm_t *vm)
{
    free(vm->mem);
    vec_prog_destroy(&vm->progs);
}

static void set_prog(vm_t *vm, prog_t *prog)
{
    for (size_t i = 0; i < prog->inst_size; i++)
        vm->mem[(prog->pc + i) % VM_SIZE] = prog->inst[i];
    prog->r[0] = prog->id;
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
    for (size_t i = 0; i < vm->progs.count; i++) {
        if (vm->progs.prog[i].pc == VM_NULL_HANDLE)
            vm->progs.prog[i].pc = next_pc;
        set_prog(vm, &vm->progs.prog[i]);
        next_pc += vm->progs.prog[i].inst_size + space;
    }
}
