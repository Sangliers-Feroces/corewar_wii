/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__ls
** File description:
** integer fun
*/

#include "headers.h"

void memcpy_slow(void *dst, const void *src, size_t size)
{
    char *dst_a = dst;
    const char *src_a = src;

    for (size_t i = 0; i < size; i++)
        dst_a[i] = src_a[i];
}

int streq(const char *a, const char *b)
{
    for (size_t i = 0; 1; i++) {
        if (a[i] != b[i])
            return 0;
        if (a[i] == '\0')
            return 1;
    }
}
