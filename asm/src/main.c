/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

static const char *msg =
"USAGE\n"
"\t./asm file_name[.s]\n\n"
"DESCRIPTION\n"
"\tfile_name\tfile in assembly language to be converted into file_name.cor,"
" an\n"
"\t\t\texecutable in the Virtual Machine.\n";

static FILE* open_read_file(const char *path)
{
    FILE *res;

    res = fopen(path, "r");
    if (res == NULL)
        error_mul_exit(path, "Cannot be opened");
    return res;
}

static char* get_out_path(const char *in)
{
    char *res = (char*)malloc_safe(strlen_slow(in) + 32);
    const char *ext = ".cor";
    size_t i = 0;

    for (size_t j = 0; (in[j] != '\0') && (in[j] != '.'); j++)
        res[i++] = in[j];
    for (size_t j = 0; ext[j] != '\0'; j++)
        res[i++] = ext[j];
    res[i++] = '\0';
    return res;
}

static void do_stuff(const char *path)
{
    FILE *in = open_read_file(path);
    file_write_t out;
    char *out_path = get_out_path(path);

    out = asm_file(in);
    fclose(in);
    file_write_flush(&out, out_path);
    free(out_path);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        error_exit("Only one file should be given to this assembler ! "
        "That is not a linker !");
    if (streq(argv[1], "-h")) {
        my_putstr(msg);
        return 0;
    }
    do_stuff(argv[1]);
    return 0;
}
