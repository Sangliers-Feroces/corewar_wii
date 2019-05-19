/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "headers.h"

size_t vec_prog_get_alive_count(vec_prog_t *vec)
{
    size_t res = 0;

    for (size_t i = 0; i < vec->count; i++)
        res += vec->prog[i].is_alive;
    return res;
}

void vec_prog_run(vec_prog_t *vec)
{
    for (size_t i = 0; i < vec->count; i++)
        prog_run(&vec->prog[i]);
    _vm.prog_running = NULL;
}
