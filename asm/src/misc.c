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

double randf(void)
{
    return ((double)rand() / (double)RAND_MAX);
}

double randfn(void)
{
    return (randf() - 0.5) * 2.0;
}

uint32_t swap32(uint32_t base)
{
    return ((base >> 24) & 0xFF) | ((base >> 16) & 0xFF00) |
    ((base >> 8) & 0xFF0000) | ((base >> 0) & 0xFF000000);
}
