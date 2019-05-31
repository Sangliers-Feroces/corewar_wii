/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#pragma once

void terrain_gen(demo_t *demo, float size, size_t iter, float strengh);

void terrain_sub_triangle(rtx_triangle *triangle, octree **dst);
void terrain_sub_triangle2(rtx_triangle *triangle, octree *root, octree **dst,
float strengh);

void terrain_apply_texture(octree *tree, texture2 *texture);

void terrain_split(arr2d_dvec3_t *arr, double stren);

void terrain_send_iter_to_ter_border(arr2d_dvec3_t arr, size_t ndx, ssize2 pos);
void terrain_send_iter_to_chunk_border(chunk_t *chunk, arr2d_dvec3_t arr,
size_t ndx);
void terrain_apply_constraints(arr2d_dvec3_t arr, chunk_border_t border,
size_t ndx);

arr2d_dvec3_t terrain_gen_normals(arr2d_dvec3_t arr);

void terrain_send_ter_to_chunk_lod_gen(chunk_t *chunk, size_t lod,
terrain_send_ter_arg arg, dvec3 chunk_rel);
void terrain_send_ter_to_chunks_lod(size_t lod, arr2d_dvec3_t arr,
arr2d_dvec3_t normals, ssize2 pos);

void terrain_send_ter_chunk(chunk_t *chunk, size_t lod,
terrain_send_ter_arg arg, dvec3 chunk_rel);

void chunk_add_grass(chunk_t *chunk, arr2d_dvec3_t arr, arr2d_dvec3_t n);

void chunk_add_village(chunk_t *chunk, arr2d_dvec3_t arr, arr2d_dvec3_t n);

void chunk_add_npc(chunk_t *chunk, dvec3 p);
