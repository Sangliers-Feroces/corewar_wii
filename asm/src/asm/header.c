/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

static void read_string(const char *src, char *dst, size_t size)
{
    size_t len = strlen_slow(src);

    if (len > size)
        error_line_exit(_line, "Overflow in com string", NULL);
    for (size_t i = 0; i < len; i++)
        dst[i] = src[i];
    dst[len] = 0;
}

int asm_get_header(asm_t *a, vec_str_t t, size_t *i, char *got)
{
    const char *name = ".name";
    const char *com = ".comment";
    char *value;

    if (streq(got, name) || streq(got, com)) {
        if (vec_str_at(t, *i + 1, NULL))
            return 0;
        if (!vec_str_at(t, *i, &value))
            error_line_exit(_line, "Missing arg", got);
        if (streq(got, name))
            read_string(value, a->header.name, ASM_HEADER_NAME_LEN);
        else
            read_string(value, a->header.com, ASM_HEADER_COM_LEN);
        return 1;
    }
    return 0;
}
