/*
** EPITECH PROJECT, 2018
** dante
** File description:
** arg
*/

#include "headers.h"

static int is_digit(char to_test)
{
    return (to_test >= '0') && (to_test <= '9');
}

static size_t get_pow(size_t size)
{
    size_t res = 1;

    for (size_t i = 0; i < (size - 1); i++)
        res *= 10;
    return (res);
}

static size_t get_size(const char *src, size_t *i)
{
    size_t res;
    char err[16] = "got '\0'";

    for (res = 0; is_digit(src[*i + res]); res++);
    if (res == 0)
        error_mul_exit(src, "No digits found");

    if (src[*i + res] != '\0') {
        err[5] = src[*i + res];
        error_mul_exit(
        "Unexpected token at end of numeric value", err);
    }
    return res;
}

size_t size_t_from_str(const char *src)
{
    size_t off = 0;
    size_t size = get_size(src, &off);
    size_t res = 0;
    size_t pow = get_pow(size);

    for (size_t i = 0; i < size; i++) {
        res += (src[off + i] - '0') * pow;
        pow /= 10;
    }
    return res;
}
