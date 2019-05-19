/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "headers.h"

static char get_hex_num(size_t src)
{
    if (src >= 10)
        return 'A' + src - 10;
    else
        return '0' + src;
}

static void dump_ram(void)
{
    char buf[VM_SIZE * 3];
    size_t ndx = 0;

    for (size_t i = 0; i < VM_SIZE / 32; i++) {
        for (size_t j = 0; j < 32; j++) {
            buf[ndx++] = get_hex_num((_vm.mem[i * 32 + j] >> 4) & 0xF);
            buf[ndx++] = get_hex_num(_vm.mem[i * 32 + j] & 0xF);
        }
        buf[ndx++] = '\n';
    }
    write(1, buf, ndx);
}

static void print_winner(void)
{
    prog_t *prog;

    prog = _vm.prog_live;
    if (prog != NULL) {
        my_putstr("The player ");
        prog_display(prog);
        my_putstr(" has won.\n");
    } else
        my_putstr("Nobody won ! (draw)\n");
}

int main(int ac, char **av)
{
    size_t time = 0;

    _vm = args_parse(ac, av);
    if (_vm.progs.count == 0)
        error_mul_exit("vm", "at least one program must be set on the core");
    vm_set_progs(&_vm);
    while (vec_prog_get_alive_count(&_vm.progs) > 1) {
        vec_prog_run(&_vm.progs);
        if (time++ == _vm.timeout)
            dump_ram();
    }
    print_winner();
    vm_destroy(&_vm);
    return 0;
}
