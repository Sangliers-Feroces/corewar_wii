/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#pragma once

#define MEM_SIZE                (6*1024)
#define IDX_MOD                 512   /* modulo of the index < */
#define MAX_ARGS_NUMBER         4     /* this may not be changed 2^*IND_SIZE */

#define COMMENT_CHAR            '#'
#define LABEL_CHAR              ':'
#define DIRECT_CHAR             '%'
#define SEPARATOR_CHAR          ','

#define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"

#define REGISTER_COUNT 16

typedef enum {
    ASM_ARG_REGISTER = 1,
    ASM_ARG_IMMEDIATE = 2,
    ASM_ARG_PTR = 4
} asm_arg_type_t;

typedef struct {
   char *mnemo;
   size_t arg_count;
   asm_arg_type_t arg_type[MAX_ARGS_NUMBER];
   size_t code;
   size_t cycle_count;
   char *com;
} asm_op_t;

#define PTR_SIZE 2
#define IMMEDIATE_SIZE 4
#define REGISTER_SIZE IMMEDIATE_SIZE

#define PROG_NAME_LENGTH        128
#define COMMENT_LENGTH          2048
#define COREWAR_EXEC_MAGIC      0xea83f3

typedef struct {
   int32_t id;
   char name[PROG_NAME_LENGTH + 1];
   int32_t size;
   char com[COMMENT_LENGTH + 1];
} asm_header_t;

# define CYCLE_TO_DIE    1536
# define CYCLE_DELTA     5
# define NBR_LIVE        40
