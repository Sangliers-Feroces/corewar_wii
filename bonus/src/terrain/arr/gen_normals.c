/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static int get_point(arr2d_dvec3_t arr, ssize2 p, dvec3 *res)
{
    if ((p.x >= 0) && (p.x < (ssize_t)arr.w) &&
    (p.y >= 0) && (p.y < (ssize_t)arr.h)) {
        *res = arr.dvec3[p.y * arr.w + p.x];
        return 1;
    } else
        return 0;
}

static dvec3 get_normal(arr2d_dvec3_t arr, ssize2 p)
{
    dvec3 acc = {0.0, 0.0, 0.0};
    size_t count = 0;
    ssize2 around[4][3] = {{{0, 0}, {0, 1}, {1, 0}},
    {{0, 0}, {0, -1}, {-1, 0}}, {{0, 0}, {1, 0}, {0, -1}},
    {{0, 0}, {0, -1}, {1, 0}}};
    dvec3 t[3] = {acc, acc, acc};
    int do_continue;

    for (size_t i = 0; i < 4; i++) {
        do_continue = 0;
        for (size_t j = 0; j < 3; j++)
            if (!get_point(arr, ssize2_add(p, around[i][j]), &t[j]))
                do_continue = 1;
        if (do_continue)
            continue;
        acc = dvec3_add(acc, dnormal3(t[0], t[1], t[2]));
        count++;
    }
    if (count == 0)
        return dvec3_init(FLT64_INF, FLT64_INF, FLT64_INF);
    else
        return dvec3_normalize(acc);
}

arr2d_dvec3_t terrain_gen_normals(arr2d_dvec3_t arr)
{
    arr2d_dvec3_t res = arr2d_dvec3_create(arr.w, arr.h);

    for (size_t i = 0; i < res.h; i++)
        for (size_t j = 0; j < res.w; j++)
            res.dvec3[i * res.w + j] = get_normal(arr, (ssize2){j, i});
    return res;
}
