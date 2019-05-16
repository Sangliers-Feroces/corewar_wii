/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#pragma once

vm_t vm_init(void);
void vm_destroy(vm_t *vm);
void vm_set_progs(vm_t *vm);

prog_t prog_init(void);
void prog_destroy(prog_t prog);

void prog_read(prog_t *prog, char *path);

void vec_prog_add(vec_prog_t *v, prog_t prog);
vec_prog_t vec_prog_init(void);
void vec_prog_destroy(vec_prog_t *v);

vec_prog_t vec_prog_from_args(vec_str_t args, size_t *i);

vm_t args_parse(int ac, char **av);
