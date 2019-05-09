/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** headaaaas
*/

#pragma once

typedef struct {
    char *name;
    size_t off;
} asm_label_t;

typedef struct {
    size_t count;
    size_t allocated;
    asm_label_t *label;
} vec_asm_label_t;

typedef struct {
    size_t label;
    size_t off;
} asm_label_ref_t;

typedef struct {
    size_t count;
    size_t allocated;
    asm_label_ref_t *ref;
} vec_asm_label_ref_t;

typedef struct {
    file_write_t out;
    size_t line;
    vec_asm_label_t labels;
    vec_asm_label_ref_t refs;
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

typedef struct {
    size_t start;
    size_t i;
    size_t is_quote;
    int is_sep;
    int is_last_sep;
} str_sep_data_t;
