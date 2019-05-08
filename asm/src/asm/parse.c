/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

void asm_parse_line(asm_t *a, const char *line)
{
    vec_str_t tokens = str_sep(a, line);

    for (size_t i = 0; i < tokens.count; i++)
        printf("'%s', ", tokens.str[i]);
    printf("\n");
    vec_str_destroy(tokens);
}
