/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#pragma once

#define VM_SIZE (1024 * 6)

typedef struct {
    size_t address;
    size_t id;
    size_t inst_size;
    char *inst;
} prog_t;

typedef struct {
    size_t count;
    size_t allocated;
    prog_t *prog;
} vec_prog_t;

typedef struct {
    char *mem;
    vec_prog_t progs;
    size_t timeout;
} vm_t;
