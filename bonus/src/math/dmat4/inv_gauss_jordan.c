/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

static size_t find_max_line(dmat4_ext res, size_t j, size_t r)
{
    size_t k = r + 1;
    double max_val = fabs(res[j][k]);

    for (size_t i = k; i < 4; i++)
        if (fabs(res[j][i]) > max_val) {
            max_val = fabs(res[j][i]);
            k = i;
        }
    return k;
}

static void divide_line(dmat4_ext res, size_t i, double to_div)
{
    for (size_t j = 0; j < 8; j++)
        res[j][i] /= to_div;
}

static void swap_lines(dmat4_ext res, size_t a, size_t b)
{
    double tmp;

    for (size_t j = 0; j < 8; j++) {
        tmp = res[j][a];
        res[j][a] = res[j][b];
        res[j][b] = tmp;
    }
}

static void op_fun(dmat4_ext res, size_t j, size_t r)
{
    double to_mul;

    for (size_t i = 0; i < 4; i++) {
        if (i == r)
            continue;
        to_mul = res[j][i];
        for (size_t k = 0; k < 8; k++)
            res[k][i] -= res[k][r] * to_mul;
    }
}

void dmat4_inv_gauss_jordan(dmat4_ext res)
{
    size_t r = ~0UL;
    size_t k;

    for (size_t j = 0; j < 8; j++) {
        k = find_max_line(res, j, r);
        if (res[j][k] != 0.0) {
            r++;
            divide_line(res, k, res[j][k]);
            swap_lines(res, k, r);
            op_fun(res, j, r);
        }
        if (r >= 3)
            break;
    }
}
