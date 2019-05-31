/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** optiiiiiii rtx
*/

#include "headers.h"

/* barycentric coordinatates are useful to know whether a point is located  */
/* in a triangle or not.                                                    */
/* they show how close the point is from every point of the triangle,       */
/* we can use that to interpolate triangle's attributes (uv for example)    */

dvec3 barycentric3(dvec3 p, dvec3 *triangle)
{
    dvec3 v0 = dvec3_sub(triangle[1], triangle[0]);
    dvec3 v1 = dvec3_sub(triangle[2], triangle[0]);
    dvec3 v2 = dvec3_sub(p, triangle[0]);
    double dot00 = dvec3_dot(v0, v0);
    double dot01 = dvec3_dot(v0, v1);
    double dot11 = dvec3_dot(v1, v1);
    double dot20 = dvec3_dot(v2, v0);
    double dot21 = dvec3_dot(v2, v1);
    double div = dot00 * dot11 - dot01 * dot01;
    dvec3 res;

    res.y = (dot11 * dot20 - dot01 * dot21) / div;
    res.z = (dot00 * dot21 - dot01 * dot20) / div;
    res.x = 1.0 - res.y - res.z;
    return res;
}

static int is_float_in_0_1(double value)
{
    return ((value >= 0.0) && (value <= 1.0));
}

int is_point_in_triangle(dvec3 p, dvec3 *triangle)
{
    dvec3 bar = barycentric3(p, triangle);

    return (is_float_in_0_1(bar.x) && is_float_in_0_1(bar.y) &&
    is_float_in_0_1(bar.z));
}

int is_barycentric_valid(dvec3 bar)
{
    return (is_float_in_0_1(bar.x) && is_float_in_0_1(bar.y) &&
    is_float_in_0_1(bar.z));
}

int is_point_in_triangle_get_bar(dvec3 p, dvec3 *triangle, dvec3 *bar)
{
    *bar = barycentric3(p, triangle);

    return (is_float_in_0_1(bar->x) && is_float_in_0_1(bar->y) &&
    is_float_in_0_1(bar->z));
}
