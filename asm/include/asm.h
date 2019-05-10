/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#pragma once

file_write_t asm_file(FILE *in);

void asm_parse_line(asm_t *a, const char *line);

void asm_parse_add_op(asm_op_decl_t *res, vec_str_t t, size_t *i);

void asm_parse_remove_comment(vec_str_t *vec);

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
asm_label_ref_t asm_label_ref_create(const char *label, size_t off,
size_t instr_base, int is_short);
void asm_label_ref_destroy(asm_label_ref_t ref);

asm_decl_arg_t asm_op_arg_decl_init(asm_decl_arg_type_t type, size_t value);
asm_decl_arg_t asm_op_arg_decl_init_label(const char *label);

void asm_decl_inline(asm_t *a, asm_op_decl_t decl);

asm_decl_arg_type_t asm_decl_type_get_short(asm_decl_arg_type_t decl_type);
void asm_check_decl(asm_op_decl_t decl, asm_op_t op);

asm_op_t asm_decl_get_op(asm_op_decl_t decl);

int asm_get_header(asm_t *a, vec_str_t t, size_t *i, char *got);

void asm_label_refs_resolve(asm_t *a);
