/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

void mat4_identity(mat4 dst)
{
    dst[0][0] = 1.0f;
    dst[1][0] = 0.0f;
    dst[2][0] = 0.0f;
    dst[3][0] = 0.0f;
    dst[0][1] = 0.0f;
    dst[1][1] = 1.0f;
    dst[2][1] = 0.0f;
    dst[3][1] = 0.0f;
    dst[0][2] = 0.0f;
    dst[1][2] = 0.0f;
    dst[2][2] = 1.0f;
    dst[3][2] = 0.0f;
    dst[0][3] = 0.0f;
    dst[1][3] = 0.0f;
    dst[2][3] = 0.0f;
    dst[3][3] = 1.0f;
}

void mat4_copy(mat4 src, mat4 dst)
{
    memcpy(dst, src, sizeof(mat4));
}

static float mul_iter(mat4 a, mat4 b, size_t i, size_t j)
{
    float sum = 0.0f;

    for (size_t k = 0; k < 4; k++)
        sum += a[k][j] * b[i][k];
    return sum;
}

void mat4_mul(mat4 a, mat4 b, mat4 res)
{
    mat4 resbuf;

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            resbuf[i][j] = mul_iter(a, b, i, j);
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            res[i][j] = resbuf[i][j];
}

vec4 mat4_mul_vec(mat4 a, vec4 b)
{
    vec4 res;
    float sum;

    for (size_t i = 0; i < 4; i++) {
        sum = 0.0f;
        for (size_t k = 0; k < 4; k++)
            sum += a[k][i] * ((float*)&b.x)[k];
        ((float*)&res.x)[i] = sum;
    }
    return res;
}
