/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "header.h"

void get_asm(char *path, prog_t *prog)
{
    FILE *file = fopen(path, "r");
    int32_t size;
    char *asm_c;

    if (!file) {
        my_putstr("File does not exist\n");
        exit(0);
    }
    fseek(file, offsetof(asm_header_t, size), SEEK_SET);
    fread(&size, sizeof(int32_t), 1, file);
    swap32(&size);
    asm_c = malloc(sizeof(char) * size);
    fseek(file, sizeof(asm_header_t), SEEK_SET);
    fread(asm_c, 1, size, file);
    fclose(file);
    prog->inst = asm_c;
    prog->size = size;
}
