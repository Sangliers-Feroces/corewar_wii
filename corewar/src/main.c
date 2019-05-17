/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "headers.h"

int main(int ac, char **av)
{
    _vm = args_parse(ac, av);
    if (_vm.progs.count == 0)
        error_mul_exit("vm", "at least one program must be set on the core");
    vm_set_progs(&_vm);
    while (vec_prog_get_alive_count(&_vm.progs) > 1)
        vec_prog_run(&_vm.progs);
    write(1, _vm.mem, VM_SIZE);
    vm_destroy(&_vm);
    return 0;
}
