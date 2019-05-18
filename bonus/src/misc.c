/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** hidden stuff. don't look !
*/

#include "headers.h"

/* full shenanigans */

void* malloc_safe(size_t size)
{
    void *res;

    res = malloc(size);
    if (res == NULL)
        error_display("malloc returned NULL after an alloc of %u bytes", size);
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
