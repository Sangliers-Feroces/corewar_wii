/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

void dmat4_rot_xy(dvec3 rot, dmat4 res)
{
    double c, s;
    dmat4 rot_x;

    dmat4_identity(res);
    c = cos(rot.x);
    s = sin(rot.x);
    res[1][1] = c;
    res[2][1] = s;
    res[1][2] = -s;
    res[2][2] = c;
    dmat4_identity(rot_x);
    c = cos(rot.y);
    s = sin(rot.y);
    rot_x[0][0] = c;
    rot_x[2][0] = -s;
    rot_x[0][2] = s;
    rot_x[2][2] = c;
    dmat4_mul(rot_x, res, res);
}

dvec3 dmat4_mul_dvec3(dmat4 mat, dvec3 vec)
{
    dvec4 used = {vec.x, vec.y, vec.z, 1.0};
    dvec4 res = dmat4_mul_vec4(mat, used);

    return (dvec3){res.x, res.y, res.z};
}

dvec3 dmat4_mul_vec3(dmat4 mat, vec3 vec)
{
    dvec4 used = {vec.x, vec.y, vec.z, 1.0};
    dvec4 res = dmat4_mul_vec4(mat, used);

    return (dvec3){res.x, res.y, res.z};
}
