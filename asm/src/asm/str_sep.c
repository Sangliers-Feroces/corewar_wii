/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

static int is_char_sep(char to_test)
{
    char sep[] = {' ', ',', '\t', '\n', 0};

    for (size_t i = 0; sep[i] != 0; i++)
        if (to_test == sep[i])
            return 1;
    return 0;
}

static void add_sep_force(vec_str_t *acc, const char *str, size_t start, size_t i)
{
    vec_str_add(acc, str_init(i - start, str + start));
}


static void add_sep(vec_str_t *acc, const char *str, size_t start, size_t i)
{
    char elim[] = {' ', '\t', '\n', 0};
    size_t nelim_count = 0;
    size_t len = i - start;
    int is_elim;

    if (start == i)
        return;
    for (size_t i = 0; elim[i] != 0; i++) {
        is_elim = 0;
        for (size_t j = 0; j < len; j++)
            is_elim |= str[start + j] == elim[i];
        nelim_count += !is_elim;
    }
    if (nelim_count == 0)
        return;
    add_sep_force(acc, str, start, i);
}

vec_str_t str_sep(asm_t *a, const char *src)
{
    vec_str_t res = vec_str_init();
    size_t start = 0;
    size_t i;
    size_t is_quote = 0;

    for (i = 0; src[i] != '\0'; i++) {
        if (src[i] == '"') {
            is_quote = !is_quote;
            if (!is_quote)
                add_sep_force(&res, src, start, i);
            start = i + 1;
            continue;
        }
        if (is_quote)
            continue;
        if (is_char_sep(src[i])) {
            add_sep(&res, src, start, i);
            start = i;
        }
    }
    if (is_quote)
        error_line_exit(a->line, "Uncomplete string", NULL);
    add_sep(&res, src, start, i);
    return res;
}
