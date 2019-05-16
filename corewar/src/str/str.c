/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

str_t str_init(size_t size, const char *data)
{
    str_t res;

    res.size = size;
    res.data = data;
    return res;
}

char* str_to_c_str(str_t str)
{
    char *res = (char*)malloc_safe(str.size + 1);

    memcpy_slow(res, str.data, str.size);
    res[str.size] = '\0';
    return res;
}
