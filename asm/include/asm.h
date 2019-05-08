/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#pragma once

file_write_t asm_file(FILE *in);

void asm_parse_line(asm_t *a, const char *line);

vec_str_t vec_str_init(void);
void vec_str_destroy(vec_str_t vec);
void vec_str_add(vec_str_t *vec, str_t to_add);
str_t str_init(size_t size, const char *data);
char* str_to_c_str(str_t str);

vec_str_t str_sep(asm_t *a, const char *src);
