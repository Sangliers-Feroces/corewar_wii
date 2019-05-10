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
int vec_str_at(vec_str_t vec, size_t ndx, char **res);
str_t str_init(size_t size, const char *data);
char* str_to_c_str(str_t str);

vec_str_t str_sep(const char *src);

vec_asm_label_t vec_asm_label_init(void);
void vec_asm_label_destroy(vec_asm_label_t vec);
void vec_asm_label_add(vec_asm_label_t *vec, asm_label_t to_add);
asm_label_t asm_label_create(const char *to_dup, size_t off);

vec_asm_label_ref_t vec_asm_label_ref_init(void);
void vec_asm_label_ref_destroy(vec_asm_label_ref_t vec);
void vec_asm_label_ref_add(vec_asm_label_ref_t *vec, asm_label_ref_t to_add);

asm_op_arg_decl_t asm_op_arg_decl_init(asm_op_arg_type_t type, size_t value);
asm_op_arg_decl_t asm_op_arg_decl_init_label(const char *label);
