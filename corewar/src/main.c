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
    vec_prog_t v;

    if (ac == 1) {
        my_putstr_fd(2, "Not enough arguments\n");
        return 84;
    }
    prog_vector_init(&v);
    args(ac, av, &v);
    vm.vec = &v;
    prog_vector_destroy(&v);
    vm_destroy(&vm);
    return 0;
}
