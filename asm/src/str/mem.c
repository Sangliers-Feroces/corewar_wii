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

void memset_slow(void *dst, uint8_t value, size_t count)
{
    char *dst_a = dst;

    for (size_t i = 0; i < count; i++)
        dst_a[i] = value;
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

char* strdup_slow(const char *to_dup)
{
    size_t len = strlen_slow(to_dup);
    char *res = (char*)malloc_safe(len + 1);

    memcpy_slow(res, to_dup, len);
    res[len] = '\0';
    return res;
}
