/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** sanic
*/

#pragma once

#include "octree_mem.h"

rtx_triangle* octree_insert_triangle(octree **tree, rtx_triangle *triangle);

void octree_enlarge(octree **tree, rtx_triangle *triangle);

octree* octree_create(octree *root);
octree* octree_create_node(octree *root, bounds3 bounds);
void rtx_triangle_replace(demo_t *demo, octree *node, rtx_triangle *triangle);

void octree_destroy(octree **root);

void rtx_triangle_update(rtx_triangle *triangle);

bounds3 octree_get_sub_bounds(octree *tree, size_t ndx);

size_t get_triangle_upper_tree(dvec3 *triangle, bounds3 bounds);

inter_ray3 octree_intersect_ray(octree *tree, ray3 ray);
inter_ray3 rtx_triangle_intersect_ray_no_cull(rtx_triangle *triangle,
ray3 ray);
void octree_intersect_ray_laxist_iter(octree *tree, ray3 ray,
inter_ray3 *inter);
inter_ray3 octree_intersect_ray_laxist(octree *tree, ray3 ray);
inter_ray3 octree_intersect_ray_laxist_fast(octree *tree, ray3 ray);

void octree_throw_ray(octree *tree, ray3_color ray);
float octree_light_rtx(octree *tree, size_t density);
void octree_light_rtx_thread(thread_bus *bus, octree *tree, size_t density);
void octree_light_rtx_noblock(octree *tree, size_t density);

void octree_reset_lumels(octree *tree);
float octree_get_max_lumel(octree *tree);
void octree_update_lightmap(octree *tree, float max_lumel);

void refresh_vertex_buffer(demo_t *demo);

void octree_ray_bound(octree *tree, dvec3 ray, vec2 *ppos, vec2 *psize);

size_t octree_get_rtx_triangle_count(octree *tree);

void octree_flush_vec_rtx_triangle(octree *tree);
