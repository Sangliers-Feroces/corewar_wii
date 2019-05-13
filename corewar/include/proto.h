/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#pragma once

vm_t vm_init(void);
void vm_destroy(vm_t *vm);
void get_asm(char *path);
void my_putstr(const char *str);
void swap16(void *value);
void swap32(void *value);
void swap64(void *value);