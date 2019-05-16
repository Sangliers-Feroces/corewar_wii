/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "headers.h"

static void print_help(void)
{
    my_putstr("USAGE\n"
    "\t./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address]"
    " prog_name] ...\n"
    "DESCRIPTION\n"
    "\t-dump nbr_cycle dumps the memory after the nbr_cycle execution "
    "(if the round isn’t\n"
    "\t\t\talready over) with the following format: 32 bytes/line in\n"
    "\t\t\thexadecimal (A0BCDEFE1DD3...)\n"
    "\t-n prog_number  sets the next program’s number. By default, the"
    " first free number\n"
    "\t\t\tin the parameter order\n"
    "\t-a load_address sets the next program’s loading address. When no"
    " address is\n"
    "\t\t\tspecified, optimize the addresses so that the processes are"
    " as far\n"
    "\t\t\taway from each other as possible. The addresses are MEM_SIZE"
    " modulo.\n");
    exit(0);
}

static vec_str_t extract_args(int ac, char **av)
{
    vec_str_t res = vec_str_init();

    for (int i = 0; i < ac; i++)
        vec_str_add(&res, str_init(strlen_slow(av[i]), av[i]));
    return res;
}

static void parse_first_arg(vm_t *vm, vec_str_t args, size_t *i)
{
    char *got;

    if (!vec_str_at(args, (*i)++, &got))
        error_mul_exit("FATAL ERROR", "wtf");
    if (streq(got, "-h"))
        print_help();
    else if (streq(got, "-dump")) {
        if (!vec_str_at(args, (*i)++, &got))
            error_mul_exit("-dump", "missing arg");
        vm->timeout = size_t_from_str(got);
    }
}

vm_t args_parse(int ac, char **av)
{
    vm_t res = vm_init();
    vec_str_t args = extract_args(ac, av);
    size_t i = 1;
    char *got;

    if (vec_str_at(args, i, &got))
        parse_first_arg(&res, args, &i);
    res.progs = vec_prog_from_args(args, &i);
    vec_str_destroy(args);
    return res;
}
