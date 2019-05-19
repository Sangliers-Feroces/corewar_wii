/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#pragma once

#define VM_SIZE (1024 * 6)
#define PTR_RANGE 512
#define VM_NULL_HANDLE ~0ULL
#define IS_PC 1

typedef enum {
    VM_MEM_REF_MAIN,
    VM_MEM_REF_VM_ABS,
    VM_MEM_REF_VM_REL
} vm_mem_ref_type_t;

typedef struct {
    vm_mem_ref_type_t type;
    size_t ptr;
    int is_short;
} vm_mem_ref_t;

typedef struct {
    size_t pc;
    size_t code;
    size_t cycles;
    size_t arg_count;
    vm_mem_ref_t arg[4];  // WARNING : PTR ONLY
} prog_op_t;              // (must use helper proc to read / write in RAM)

typedef struct {
    int32_t id;
    size_t inst_size;
    char *inst;
    char *name;
    int carry;
    size_t pc;
    int32_t r[16];
    prog_op_t op;
    size_t cycle;
    size_t life;
    int is_alive;
} prog_t;

typedef struct {
    size_t count;
    size_t allocated;
    prog_t **prog;
} vec_prog_t;

typedef struct {
    char *mem;
    vec_prog_t progs;
    prog_t *prog_running;
    prog_t *prog_live;
    size_t timeout;
} vm_t;
