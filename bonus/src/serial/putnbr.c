/*
** EPITECH PROJECT, 2019
** put_nbr
** File description:
** print_int
*/

#include "nbr_tools.h"

static size_t get_max_pow(size_t value, int base)
{
    size_t res = 1;

    while ((res * base) <= value)
        res *= base;
    return res;
}

void putnbr(size_t value, int base, int caps)
{
    size_t max_pow = get_max_pow(value, base);
    size_t tmp;

    while (max_pow > 0) {
        tmp = (value / max_pow) % base;
        if (tmp < 10)
            my_putchar(ITC(tmp));
        else
            my_putchar(tmp - 10 + 'a' - caps * 32);
        max_pow /= base;
    }
}