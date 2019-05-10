/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

static int is_char_sep(char to_test)
{
    char sep[] = {'#', ':', '%', ',',
    ' ', '\t', '\n', 0};

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
    size_t len = i - start;
    int is_elim;

    if (start == i)
        return;
    for (size_t i = 0; elim[i] != 0; i++) {
        is_elim = 0;
        for (size_t j = 0; j < len; j++)
            is_elim |= str[start + j] == elim[i];
        if (is_elim)
            return;
    }
    add_sep_force(acc, str, start, i);
}

str_sep_data_t str_sep_data_init(void)
{
    str_sep_data_t res;

    res.start = 0;
    res.is_quote = 0;
    res.is_last_sep = 0;
    return res;
}

static void iter(vec_str_t *res, str_sep_data_t *data, const char *src)
{
    if (src[data->i] == '"') {
        data->is_quote = !data->is_quote;
        if (!data->is_quote)
            add_sep_force(res, src, data->start, data->i);
        data->start = data->i + 1;
        return;
    }
    if (data->is_quote)
        return;
    data->is_sep = is_char_sep(src[data->i]);
    if (data->is_sep || data->is_last_sep) {
        add_sep(res, src, data->start, data->i);
        data->start = data->i;
    }
    data->is_last_sep = data->is_sep;
}

vec_str_t str_sep(const char *src)
{
    vec_str_t res = vec_str_init();
    str_sep_data_t data = str_sep_data_init();

    for (data.i = 0; src[data.i] != '\0'; data.i++)
        iter(&res, &data, src);
    if (data.is_quote)
        error_line_exit(_line, "Uncomplete string", NULL);
    add_sep(&res, src, data.start, data.i);
    return res;
}
