/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** optiiiiiii rtx
*/

#include "headers.h"

/* intersection of a ray and a bunch of triangle using the octree */
/* copy-pasted code from octree_ray_inter to keep inlining        */
/* w/ static proc calls                                           */

static float intersect_plane(rtx_triangle *triangle, ray3 ray, float dotnv)
{
    return dvec3_dot(triangle->normal, dvec3_sub(triangle->vertex[0], ray.p)) /
    dotnv;
}

static void intersect_ray(rtx_triangle *triangle, ray3 ray, inter_ray3 *inter)
{
    float dotnv = dvec3_dot(triangle->normal, ray.v);
    float t;
    dvec3 p;

    if (dotnv == 0.0f)
        return;
    t = intersect_plane(triangle, ray, dotnv);
    p = ray3_compute(ray, t);
    inter->triangle = triangle;
    inter->p = p;
    inter->min_t = t;
}

inter_ray3 rtx_triangle_intersect_ray_no_cull(rtx_triangle *triangle, ray3 ray)
{
    inter_ray3 inter = {NULL, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, 0.0f};

    intersect_ray(triangle, ray, &inter);
    return inter;
}
