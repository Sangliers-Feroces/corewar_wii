/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "header.h"

vm_t vm_init(void)
{
    vm_t vm;

    vm.mem = NULL;
    vm.vec = NULL;
    return vm;
}

void vm_create(vm_t *vm)
{
    for (int32_t i = 0; i < (int32_t)(MEM_SIZE / sizeof(char)); i++)
        vm->mem[i] = '0';
}

void vm_destroy(vm_t *vm)
{
    free(vm->mem);
}

void vm_fill_mem(vm_t *vm)
{
    int32_t total_size = 0;
    int32_t space;

    for (int i = 0; i < vm->vec->count; i++)
        total_size += vm->vec->prog[i].size;
    space = total_size / vm->vec->count;
    for (int i = 0; i < vm->vec->count; i++) {
        for (int j = 0; j < vm->vec->prog[i].size; j++)
            vm->mem[space * i + j] = vm->vec->prog[i].inst[j];
    }
}
