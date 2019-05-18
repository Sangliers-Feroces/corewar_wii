/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

void dmat4_perspective(proj_t proj, dmat4 res)
{
    double tan_half_fov_w = tan(proj.fov_w * (M_PI / 180.0) / 2.0);

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            res[i][j] = 0.0;
    res[0][0] = 1.0 / (proj.ratio_wh * tan_half_fov_w);
    res[1][1] = 1.0 / tan_half_fov_w;
    res[2][2] = (proj.far_plane + proj.near_plane) /
    (proj.far_plane - proj.near_plane);
    res[2][3] = 1.0;
    res[3][2] = - (2.0 * proj.near_plane * proj.far_plane) /
    (proj.far_plane - proj.near_plane);
    return;
}

void dmat4_ortho(proj_t proj, dmat4 res)
{
    double w = proj.fov_w * proj.ratio_wh;
    double h = proj.fov_w;

    dmat4_identity(res);
    res[0][0] = 2.0f / (w);
    res[1][1] = 2.0f / (h);
    res[2][2] = 2.0f / (proj.far_plane - proj.near_plane);
    res[3][2] = - (proj.far_plane + proj.near_plane) /
    (proj.far_plane - proj.near_plane);
}

void dmat4_lookdir(dvec3 p, dvec3 f, dvec3 u, dmat4 res)
{
    f = dvec3_normalize(f);
    u = dvec3_normalize(u);
    dvec3 s = dvec3_normalize(dvec3_cross(u, f));

    res[0][0] = s.x;
    res[1][0] = s.y;
    res[2][0] = s.z;
    res[0][1] = u.x;
    res[1][1] = u.y;
    res[2][1] = u.z;
    res[0][2] = f.x;
    res[1][2] = f.y;
    res[2][2] = f.z;
    res[3][0] = -dvec3_dot(s, p);
    res[3][1] = -dvec3_dot(u, p);
    res[3][2] = -dvec3_dot(f, p);
}
