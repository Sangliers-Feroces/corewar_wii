/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** 09/05/2019, vm_t.c
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
    for (int i = 0; i < (MEM_SIZE / sizeof(char)); i++)
        vm->mem[i] = '0';
}

void vm_destroy(vm_t *vm)
{
    free(vm->mem);
}