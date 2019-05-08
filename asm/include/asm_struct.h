/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** headaaaas
*/

#pragma once

typedef struct {
    file_write_t out;
    size_t line;
} asm_t;

typedef struct {
    size_t count;
    size_t allocated;
    char **str;
} vec_str_t;

typedef struct {
    size_t size;
    const char *data;
} str_t;
