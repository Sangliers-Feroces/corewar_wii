/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "headers.h"

static prog_op_t prog_op_init(void)
{
    prog_op_t res;

    res.code = VM_NULL_HANDLE;
    res.cycles = 0;
    res.arg_count = 0;
    for (size_t i = 0; i < 4; i++)
        res.arg[i] = vm_mem_ref_get_null();
    return res;
}

prog_t prog_init(void)
{
    prog_t res;

    res.id = 0;
    res.inst_size = 0;
    res.inst = NULL;
    res.carry = 0;
    res.pc = VM_NULL_HANDLE;
    for (size_t i = 0; i < 16; i++)
        res.r[i] = 0;
    res.op = prog_op_init();
    res.cycle = 0;
    res.life = 0;
    res.is_alive = 1;
    return res;
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
    prog->inst_size = size_raw;
    prog->inst = malloc_safe(sizeof(char) * prog->inst_size);
    fseek(file, sizeof(asm_header_t), SEEK_SET);
    if (fread(prog->inst, 1, prog->inst_size, file) != prog->inst_size)
        error_mul_exit(path, "Can't read data");
    fclose(file);
}
