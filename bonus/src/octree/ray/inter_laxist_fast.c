/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** optiiiiiii rtx
*/

#include "headers.h"

/* intersection of a ray and a bunch of triangle using the octree */
// si ça dépasse un peu, ça passe

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
    dvec3 bar;

    if (dotnv >= 0.0f)
        return;
    t = intersect_plane(triangle, ray, dotnv);
    if (t <= 0.0f)
        return;
    p = ray3_compute(ray, t);
    bar = barycentric3(p, triangle->vertex);
    if (!is_barycentric_valid_laxist(bar))
        return;
    if ((inter->triangle == NULL) || (t < inter->min_t)) {
        inter->triangle = triangle;
        inter->p = p;
        inter->bar = bar;
        inter->min_t = t;
    }
}

static void iter(octree *base, ray3 ray, dvec3 b,
inter_ray3 *inter)
{
    for (size_t i = 0; i < base->triangles->count; i++)
        intersect_ray(base->triangles->triangle[i], ray, inter);
    for (size_t i = 0; i < 8; i++) {
        if (base->sub[i] == NULL)
            continue;
        if (dvec3_is_in_bounds(ray.p, base->sub[i]->bounds) &&
        dvec3_is_in_bounds(b, base->sub[i]->bounds))
            return iter(
            base->sub[i], ray, b, inter);
    }
}

inter_ray3 octree_intersect_ray_laxist_fast(octree *tree, ray3 ray)
{
    inter_ray3 inter = {NULL, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, 1.0};

    if (tree != NULL)
        iter(tree, ray, dvec3_add(ray.p, ray.v), &inter);
    return inter;
}
