/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** 09/05/2019, main.c
*/

#include "header.h"

int main(int ac, char **av)
{
    vm_t vm = vm_init();

    vm_destroy(&vm);
    return 0;
}