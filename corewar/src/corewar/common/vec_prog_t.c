/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "headers.h"

vec_prog_t vec_prog_init(void)
{
    vec_prog_t res;

    res.count = 0;
    res.allocated = 0;
    res.prog = NULL;
    return res;
}

void vec_prog_add(vec_prog_t *v, prog_t *prog)
{
    size_t cur = v->count++;

    if (v->count > v->allocated) {
        v->allocated += 8;
        v->prog = (prog_t**)realloc(v->prog, v->allocated * sizeof(prog_t*));
    }
    v->prog[cur] = prog;
}

void vec_prog_destroy(vec_prog_t *v)
{
    for (size_t i = 0; i < v->count; i++)
        prog_destroy(v->prog[i]);
    free(v->prog);
}
