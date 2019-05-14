/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#pragma once

vm_t vm_init(void);
void vm_destroy(vm_t *vm);
void get_asm(char *path, prog_t *prog);
void my_putstr(const char *str);
void my_putstr_fd(int fd, const char *str);
void swap16(void *value);
void swap32(void *value);
void swap64(void *value);
int strcmp_c(char *str1, char *str2);
void prog_vector_add(vec_prog_t *v, prog_t prog);
void prog_vector_init(vec_prog_t *v);
void prog_vector_destroy(vec_prog_t *v);
void args(int ac, char **av, vec_prog_t *v);
prog_t prog_init();
int getnbr_c(char *str);