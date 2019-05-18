/*
** EPITECH PROJECT, 2019
** str_tools
** File description:
** str_tools.c
*/

#include "str.h"

int my_strcpy(const char *src, char **pres, size_t n)
{
    size_t i;

    if (n == ALL_WORD) {
        for (i = 0; src[i] != '\0'; i++) {
            (*pres)[i] = src[i];
        }
        (*pres)[i] = '\0';
        return 1;
    }
    for (i = 0; src[i] != '\0' && i != n; i++)
        (*pres)[i] = src[i];
    (*pres)[i] = '\0';
    return 1;
}

int my_strcmp(const char *s1, const char *s2, size_t n)
{
    if (n == ALL_WORD) {
        for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
            if (s1[i] != s2[i])
                return 0;
        return 1;
    }
    for (size_t i = 0; s1[i] != '\0' && s2[i] != '\0' && i != n; i++)
            if (s1[i] != s2[i])
                return 0;
    return 1;
}
