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

prog_t* prog_init(void);
void prog_destroy(prog_t *prog);

void prog_read(prog_t *prog, char *path);

void vec_prog_add(vec_prog_t *v, prog_t *prog);
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
vm_mem_ref_t vm_mem_ref_init_rel(int32_t offset);

void vm_write_uint8(size_t ptr, uint8_t value);
void vm_write_uint16(size_t ptr, uint16_t value);
void vm_write_uint32(size_t ptr, uint32_t value);

prog_op_t vm_read_prog_op(prog_t *prog);

vm_mem_ref_t vm_mem_ref_get_null(void);

int32_t vm_mem_ref_read(vm_mem_ref_t ref);
void vm_mem_ref_write(vm_mem_ref_t ref, int32_t value);
int32_t vm_mem_ref_read_nomod(vm_mem_ref_t ref);
void vm_mem_ref_write_nomod(vm_mem_ref_t ref, int32_t value);

void prog_exec_op(prog_t *prog);

void vm_fork(int32_t offset);
void vm_fork_nomod(int32_t offset);


//ops list
void live(prog_t *prog);
void ld(prog_t *prog);
void st(prog_t *prog);
void add(prog_t *prog);
void sub(prog_t *prog);
void and(prog_t *prog);
void or(prog_t *prog);
void xor(prog_t *prog);
void zjmp(prog_t *prog);
void ldi(prog_t *prog);
void sti(prog_t *prog);
void fork_(prog_t *prog);
void lld(prog_t *prog);
void lldi(prog_t *prog);
void lfork(prog_t *prog);
void aff(prog_t *prog);
