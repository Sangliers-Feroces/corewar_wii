/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "header.h"

void prog_vector_init(vec_prog_t *v)
{
    v->capacity = 2;
    v->count = 0;
    v->prog = malloc(sizeof(prog_t) * 2);
}

void prog_vector_add(vec_prog_t *v, prog_t prog)
{
    if (v->capacity == v->count) {
        v->capacity++;
        v->prog = (prog_t*)realloc(v->prog, v->capacity * sizeof(prog_t));
    }
    v->prog[v->count] = prog;
    v->count++;
}

void prog_vector_destroy(vec_prog_t *v)
{
    free(v->prog);
    free(v);
}