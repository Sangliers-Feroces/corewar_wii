/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "headers.h"

prog_t prog_init(void)
{
    prog_t prog;

    prog.address = 0;
    prog.id = 0;
    prog.inst_size = 0;
    prog.inst = NULL;
    return prog;
}

void prog_destroy(prog_t prog)
{
    free(prog.inst);
}

void prog_read(prog_t *prog, char *path)
{
    FILE *file = fopen(path, "r");
    int32_t size_raw;

    if (file == NULL)
        error_mul_exit(path, "File does not exist");
    fseek(file, offsetof(asm_header_t, size), SEEK_SET);
    if (fread(&size_raw, sizeof(int32_t), 1, file) != 1)
        error_mul_exit(path, "Can't read data size");
    prog->inst_size = swap32(size_raw);
    prog->inst = malloc_safe(sizeof(char) * prog->inst_size);
    fseek(file, sizeof(asm_header_t), SEEK_SET);
    if (fread(prog->inst, 1, prog->inst_size, file) != prog->inst_size)
        error_mul_exit(path, "Can't read data");
    fclose(file);
}
