/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

vec_str_t vec_str_init(void)
{
    vec_str_t res;

    res.count = 0;
    res.allocated = 0;
    res.str = NULL;
    return res;
}

void vec_str_destroy(vec_str_t vec)
{
    for (size_t i = 0; i < vec.count; i++)
        free(vec.str[i]);
    free(vec.str);
}

void vec_str_add(vec_str_t *vec, str_t to_add)
{
    size_t cur = vec->count++;

    if (vec->count > vec->allocated) {
        vec->allocated += 16;
        vec->str = (char**)realloc(vec->str, vec->allocated * sizeof(char*));
    }
    vec->str[cur] = str_to_c_str(to_add);
}

int vec_str_at(vec_str_t vec, size_t ndx, char **res)
{
    if (ndx < vec.count) {
        if (res != NULL)
            *res = vec.str[ndx];
        return 1;
    } else
        return 0;
}

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
