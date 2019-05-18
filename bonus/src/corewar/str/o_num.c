/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__ls
** File description:
** integer fun
*/

#include "headers.h"

static size_t get_max_pow(size_t value, size_t base, size_t *p_exp)
{
    size_t res = 1;
    size_t exp = 0;

    while ((res * base) <= value) {
        res *= base;
        exp++;
    }
    *p_exp = exp;
    return (res);
}

void strout_num_adv(FILE *file, size_t value, size_t base, int is_caps)
{
    size_t exp;
    size_t pow = get_max_pow(value, base, &exp);
    size_t tmp;
    char buf[64];
    size_t i = 0;

    while (pow > 0) {
        tmp = (value / pow) % base;
        if (tmp < 10)
            buf[i++] = tmp + '0';
        else
            buf[i++] = tmp - 10 + 'a' - is_caps * 32;
        pow /= base;
    }
    fwrite(buf, 1, i, file);
}

void strout_num(size_t value)
{
    strout_num_adv(stdout, value, 10, 0);
}

void strerr_num(size_t value)
{
    strout_num_adv(stderr, value, 10, 0);
}

