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