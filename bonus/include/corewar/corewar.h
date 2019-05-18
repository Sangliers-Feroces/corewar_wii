/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#pragma once

vm_t vm_init(void);
void vm_destroy(vm_t *vm);
int vm_set_prog(prog_t *prog);
void vm_clean(void);
size_t vm_get_used(void);
void vm_set_progs(vm_t *vm);

prog_t prog_init(void);
void prog_destroy(prog_t prog);

void prog_read(prog_t *prog, char *path);

void vec_prog_add(vec_prog_t *v, prog_t prog);
vec_prog_t vec_prog_init(void);
void vec_prog_destroy(vec_prog_t *v);

vec_prog_t vec_prog_from_args(vec_str_t args, size_t *i);

vm_t args_parse(int ac, char **av);

size_t vec_prog_get_alive_count(vec_prog_t *vec);
void vec_prog_run(vec_prog_t *vec);

void prog_run(prog_t *prog);

uint8_t vm_read_uint8(size_t ptr);
uint16_t vm_read_uint16(size_t ptr);
uint32_t vm_read_uint32(size_t ptr);

void vm_write_uint8(size_t ptr, uint8_t value);
void vm_write_uint16(size_t ptr, uint16_t value);
void vm_write_uint32(size_t ptr, uint32_t value);

prog_op_t vm_read_prog_op(prog_t *prog);

vm_mem_ref_t vm_mem_ref_get_null(void);

int32_t vm_mem_ref_read(vm_mem_ref_t ref);
void vm_mem_ref_write(vm_mem_ref_t ref, int32_t value);

void prog_exec_op(prog_t *prog);
