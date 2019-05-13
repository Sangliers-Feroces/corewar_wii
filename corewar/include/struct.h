/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#pragma once

typedef struct {
    size_t address;
    char *inst;
} prog_t;

typedef struct {
    int32_t capacity;
    int32_t count;
    prog_t *prog;
} vec_prog_t;

typedef struct {
    char *mem;
} vm_t;
