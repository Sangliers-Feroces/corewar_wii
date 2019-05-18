/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

void dmat4_identity(dmat4 dst)
{
    dst[0][0] = 1.0;
    dst[1][0] = 0.0;
    dst[2][0] = 0.0;
    dst[3][0] = 0.0;
    dst[0][1] = 0.0;
    dst[1][1] = 1.0;
    dst[2][1] = 0.0;
    dst[3][1] = 0.0;
    dst[0][2] = 0.0;
    dst[1][2] = 0.0;
    dst[2][2] = 1.0;
    dst[3][2] = 0.0;
    dst[0][3] = 0.0;
    dst[1][3] = 0.0;
    dst[2][3] = 0.0;
    dst[3][3] = 1.0;
}

void dmat4_copy(dmat4 src, dmat4 dst)
{
    memcpy(dst, src, sizeof(dmat4));
}

static double mul_iter(dmat4 a, dmat4 b, size_t i, size_t j)
{
    double sum = 0.0;

    for (size_t k = 0; k < 4; k++)
        sum += a[k][j] * b[i][k];
    return sum;
}

void dmat4_mul(dmat4 a, dmat4 b, dmat4 res)
{
    dmat4 resbuf;

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            resbuf[i][j] = mul_iter(a, b, i, j);
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            res[i][j] = resbuf[i][j];
}

dvec4 dmat4_mul_vec4(dmat4 a, dvec4 b)
{
    dvec4 res;
    double sum;

    for (size_t i = 0; i < 4; i++) {
        sum = 0.0;
        for (size_t k = 0; k < 4; k++)
            sum += a[k][i] * ((double*)&b.x)[k];
        ((double*)&res.x)[i] = sum;
    }
    return res;
}
