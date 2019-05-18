/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** std::vector
*/

#pragma once

int ray_is_in_bounds(ray3 ray, bounds3 bounds);
int ray_is_in_bounds_seg(ray3 ray, dvec3 b_min, dvec3 b_max);

rtx_triangle* rtx_triangle_create(dvec3 *triangle);
void rtx_triangle_destroy(rtx_triangle *triangle);

vec_rtx_triangle* vec_rtx_triangle_create(void);
void vec_rtx_triangle_add(vec_rtx_triangle *vec, rtx_triangle *to_add);
void vec_rtx_triangle_destroy(vec_rtx_triangle *vec);
void vec_rtx_triangle_free(vec_rtx_triangle *vec);
void vec_rtx_triangle_flush(vec_rtx_triangle *vec);
