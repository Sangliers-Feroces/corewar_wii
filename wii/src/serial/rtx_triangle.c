/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

/* a constructor, an std::vector method */

vec3 normal3(vec3 a, vec3 b, vec3 c)
{
    return vec3_normalize(vec3_cross(vec3_sub(b, a), vec3_sub(c, a)));
}

dvec3 dnormal3(dvec3 a, dvec3 b, dvec3 c)
{
    return dvec3_normalize(dvec3_cross(dvec3_sub(b, a), dvec3_sub(c, a)));
}

rtx_triangle* rtx_triangle_create(dvec3 *triangle)
{
    rtx_triangle *res = (rtx_triangle*)malloc_safe(sizeof(rtx_triangle));

    for (size_t i = 0; i < 3; i++)
        res->vertex[i] = triangle[i];
    res->normal = dnormal3(triangle[0], triangle[1], triangle[2]);
    res->root = NULL;
    res->root_ndx = ~0UL;
    return (res);
}

void rtx_triangle_destroy(rtx_triangle *triangle)
{
    vec_rtx_triangle *ref_vec;

    if (triangle->root != NULL) {
        ref_vec = triangle->root;
        ref_vec->triangle[triangle->root_ndx] =
        ref_vec->triangle[--ref_vec->count];
        if ((ref_vec->count > 0) &&
        (ref_vec->triangle[triangle->root_ndx]->root == ref_vec))
            ref_vec->triangle[triangle->root_ndx]->root_ndx =
            triangle->root_ndx;
        octree_flush_vec_rtx_triangle(ref_vec->node);
    }
    free(triangle);
}
