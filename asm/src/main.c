/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

static FILE* open_read_file(const char *path)
{
    FILE *res;

    res = fopen(path, "r");
    if (res == NULL)
        error_mul_exit(path, "Cannot be opened");
    return res;
}

static void do_stuff(const char *path)
{
    FILE *in = open_read_file(path);
    file_write_t out;

    out = asm_file(in);
    fclose(in);
    file_write_flush(&out, "out.txt");
}

int main(int argc, char **argv)
{

    if (argc != 2)
        error_exit("Only one file should be given to this assembler ! "
        "That is not a linker !");
    do_stuff(argv[1]);
    return 0;
}
