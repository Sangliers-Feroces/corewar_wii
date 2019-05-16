/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "headers.h"

int main(int ac, char **av)
{
    vm_t vm = args_parse(ac, av);

    if (vm.progs.count == 0)
        error_mul_exit("vm", "at least one program must be set on the core");
    vm_set_progs(&vm);
    write(1, vm.mem, VM_SIZE);
    vm_destroy(&vm);
    return 0;
}
