/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "header.h"

int main(int ac, char **av)
{
    vm_t vm = vm_init();

    get_asm(av[1]);
    vm_destroy(&vm);
    return 0;
}