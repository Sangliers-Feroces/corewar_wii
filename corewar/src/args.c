/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "header.h"

void print_help(void)
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

void args(int ac, char **av, vec_prog_t *v)
{
    prog_t prog = prog_init();
    int last_number = 0;

    if (strcmp_c(av[1], "-h"))
        print_help();
    for (int i = 1; i < ac; i++) {
        if (strcmp_c(av[i], "-a")) {
            prog.address = getnbr_c(av[i + 1]);
            i++;
        } else if (strcmp_c(av[i], "-n")) {
            prog.number = getnbr_c(av[i + 1]);
            i++;
            last_number = prog.number;
        } else {
            prog.number = last_number++;
            get_asm(av[i], &prog);
            prog_vector_add(v, prog);
        }
    }
}