/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** hidden stuff. don't look !
*/

#include "headers.h"

/* full shenanigans */

void exit_full_custom(void)
{
    __asm__("mov $60, %rax");
    __asm__("mov $84, %rdi");
    __asm__("syscall");
}

void* malloc_safe(size_t size)
{
    void *res;

    res = malloc(size);
    if (res == NULL)
        exit_full_custom();
    return (res);
}
