/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** headaaaas
*/

#pragma once

#define ASM_HEADER_MAGIC 0xea83f3
#define ASM_HEADER_NAME_LEN 128
#define ASM_HEADER_COM_LEN 2048

typedef struct {
    int32_t id;
    char name[ASM_HEADER_NAME_LEN + 1];
    int32_t size;
    char com[ASM_HEADER_COM_LEN + 1];
} asm_header_t;

typedef struct {
    size_t count;
    size_t allocated;
    char **str;
} vec_str_t;

typedef struct {
    size_t size;
    const char *data;
} str_t;

typedef enum {
    ASM_DECL_ARG_REGISTER,
    ASM_DECL_ARG_IMMEDIATE,
    ASM_DECL_ARG_POINTER,
    ASM_DECL_ARG_IMMEDIATE_LABEL,
} asm_decl_arg_type_t;

typedef struct {
    asm_decl_arg_type_t type;
    size_t value;
    const char *label;
} asm_decl_arg_t;

typedef struct {
    const char *name;
    size_t arg_count;
    asm_decl_arg_t arg[64];
} asm_op_decl_t;

typedef enum {
    ASM_ARG_REGISTER = 1,
    ASM_ARG_IMMEDIATE = 2,
    ASM_ARG_POINTER = 4,
} asm_arg_type_t;

#define ASM_ARG_NREGISTER (ASM_ARG_IMMEDIATE | ASM_ARG_POINTER)
#define ASM_ARG_LVALUE (ASM_ARG_REGISTER | ASM_ARG_POINTER)
#define ASM_ARG_INDEX (ASM_ARG_REGISTER | ASM_ARG_IMMEDIATE)
#define ASM_ARG_ALL (ASM_ARG_REGISTER | ASM_ARG_IMMEDIATE | ASM_ARG_POINTER)

typedef struct {
    const char *name;
    size_t code;
    size_t arg_count;
    asm_arg_type_t arg_type[64];
    int is_index;
    int hide_arg_byte;
} asm_op_t;
