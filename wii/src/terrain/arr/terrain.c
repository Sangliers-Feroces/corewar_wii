/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

double cos_der(double value)
{
    return 0.2 + 0.8 * ((sin(value / 3.0) + 1.0) / 2.5);
}

double chunk_get_strength(ssize2 pos)
{
    return (cos_der(pos.x) * cos_der(pos.y)) / 2.0;
}

static void split(arr2d_dvec3_t *arr, ssize2 ter_pos, chunk_border_t border,
double stren)
{
    arr2d_dvec3_t n;

    for (size_t i = 0; i < CHUNK_GEN_ITER; i++) {
        terrain_split(arr, stren);
        terrain_apply_constraints(*arr, border, i);
        terrain_send_iter_to_ter_border(*arr, i, ter_pos);
        switch (i) {
        case 4:
            n = terrain_gen_normals(*arr);
            terrain_send_ter_to_chunks_lod(0, *arr, n, ter_pos);
            arr2d_dvec3_destroy(n);
            break;
        case 5:
            n = terrain_gen_normals(*arr);
            terrain_send_ter_to_chunks_lod(1, *arr, n, ter_pos);
            arr2d_dvec3_destroy(n);
            break;
        }
    }
}

void chunk_gen_terrain(ssize2 pos)
{
    ssize2 ter_pos = chunk_get_terrain_pos(pos);
    arr2d_dvec3_t arr = arr2d_dvec3_create(2, 2);
    double stren = chunk_get_strength(ter_pos);
    dvec3 base = {0.0, (stren - 0.25) * 384.0, 0.0};
    chunk_border_t border = chunk_border_ter_fetch(ter_pos);

    arr.dvec3[0] = base;
    arr.dvec3[1] = dvec3_add(base, (dvec3){CHUNK_SIZE_TERRAIN, 0.0, 0.0});
    arr.dvec3[2] = dvec3_add(base, (dvec3){0.0, 0.0, CHUNK_SIZE_TERRAIN});
    arr.dvec3[3] = dvec3_add(base, (dvec3){CHUNK_SIZE_TERRAIN, 0.0,
    CHUNK_SIZE_TERRAIN});
    split(&arr, ter_pos, border, stren);
    chunk_border_destroy(border);
    arr2d_dvec3_destroy(arr);
}
