/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

void dmat4_inv(dmat4 src, dmat4 res)
{
    dmat4_ext g;

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++) {
            g[j][i] = src[j][i];
            g[4 + j][i] = i == j ? 1.0 : 0.0;
        }
    dmat4_inv_gauss_jordan(g);
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            res[j][i] = g[4 + j][i];
}
