/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

static asm_t asm_init(void)
{
    asm_t res;

    res.out = file_write_create();
    res.line = 1;
    return res;
}

file_write_t asm_file(FILE *in)
{
    asm_t a = asm_init();
    char *line = NULL;
    size_t n = 0;

    while (getline(&line, &n, in) >= 0) {
        asm_parse_line(&a, line);
        a.line++;
    }
    free(line);
    return a.out;
}
