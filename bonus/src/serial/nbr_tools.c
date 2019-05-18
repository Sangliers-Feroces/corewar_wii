/*
** EPITECH PROJECT, 2019
** nbr_tools
** File description:
** nbr_tools
*/

#include "nbr_tools.h"

int my_char_isnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!my_isnum(str[i], 1)) {
            return 0;
        }
    return 1;
}

int my_isnum(char c, int sign)
{
    if (c < '0' || c > '9') {
        if (sign == 1 && (c == '-' || c == '.'))
            return 1;
        return 0;
    }
    return 1;
}

int nbr_len(size_t c, int accept_0)
{
    size_t res = 0;

    if (c == 0 && accept_0 == 1)
        return 1;
    for (; c > 0; res++)
        c /= 10;
    return res;
}

int my_pow(size_t a, size_t b)
{
    size_t res = 1;

    for (; b > 0; b--)
        res *= a;
    return res;
}
