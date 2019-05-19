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

static void parse_int32_opt(vec_str_t args, size_t *i, char **got,
int32_t *dst)
{
    if (!vec_str_at(args, (*i)++, got))
        error_mul_exit("champion parsing", "missing arg");
    *dst = size_t_from_str(*got);
    if (!vec_str_at(args, (*i)++, got))
        error_mul_exit("champion parsing", "expected path to champion");
}

static void parse_size_opt(vec_str_t args, size_t *i, char **got,
size_t *dst)
{
    if (!vec_str_at(args, (*i)++, got))
        error_mul_exit("champion parsing", "missing arg");
    *dst = size_t_from_str(*got);
    if (!vec_str_at(args, (*i)++, got))
        error_mul_exit("champion parsing", "expected path to champion");
}

vec_prog_t vec_prog_from_args(vec_str_t args, size_t *i)
{
    vec_prog_t res = vec_prog_init();
    prog_t *prog;
    int32_t last_id = 0;
    char *got;

    while (1) {
        if (!vec_str_at(args, (*i)++, &got))
            return res;
        prog = prog_init();
        prog->id = last_id + 1;
        if (streq(got, "-n"))
            parse_int32_opt(args, i, &got, &prog->id);
        if (streq(got, "-a"))
            parse_size_opt(args, i, &got, &prog->pc);
        prog_read(prog, got);
        vec_prog_add(&res, prog);
        last_id = prog->id;
    }
    return res;
}
