/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static dvec3 get_normal_from_triangle(arr2d_dvec3_t arr,
ssize2 base, ssize2 *off)
{
    dvec3 p[3];
    ssize2 ndx;

    for (size_t i = 0; i < 3; i++) {
        ndx = ssize2_add(base, off[i]);
        p[i] = arr.dvec3[ndx.y * arr.w + ndx.x];
    }
    return dnormal3(p[0], p[1], p[2]);
}

static vec3 get_normal(terrain_send_ter_arg arg,
ssize2 ndx, ssize2 ndx_off, ssize2 *off_k)
{
    vec3 res = dvec3_vec3(
    arg.normals.dvec3[ndx_off.y * arg.normals.w + ndx_off.x]);

    if (res.x == FLT64_INF)
        res = dvec3_vec3(get_normal_from_triangle(arg.arr, ndx, off_k));
    return res;
}

static void send_ter_iter(mesh_full_t *mesh, ssize2 i,
terrain_send_ter_arg arg, dvec3 chunk_rel)
{
    ssize2 off[2][3] = {{{0, 0}, {0, 1}, {1, 0}}, {{1, 1}, {1, 0}, {0, 1}}};
    ssize2 ndx;
    ssize2 ndx_off;
    vec2 uv[3] = {{0.0f, 0.0f}, {2.0f, 0.0f}, {0.0f, 2.0f}};
    vec3 pos;
    vec3 norm;

    for (size_t k = 0; k < 2; k++) {
        for (size_t l = 0; l < 3; l++) {
            ndx = ssize2_add(arg.area.p, i);
            ndx_off = ssize2_add(ndx, off[k][l]);
            pos = dvec3_vec3(
            dvec3_sub(arg.arr.dvec3[ndx_off.y * arg.arr.w + ndx_off.x],
            chunk_rel));
            norm = get_normal(arg, ndx, ndx_off, off[k]);
            mesh_add_vertex(mesh->mesh, vertex_init(pos, norm, uv[l]));
        }
    }
}

void terrain_send_ter_chunk(chunk_t *chunk, size_t lod,
terrain_send_ter_arg arg, dvec3 chunk_rel)
{
    mesh_full_t *mesh;

    mesh = entity3_create_render(chunk->terrain, lod, MATERIAL_GRASS, 0);
    for (ssize_t i = 0; i < arg.area.s.y - 1; i++)
        for (ssize_t j = 0; j < arg.area.s.x - 1; j++)
            send_ter_iter(mesh, (ssize2){j, i}, arg, chunk_rel);
}
