/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** gllol
*/

#include "headers.h"

void mat4_scale_trans(dvec3 pos, dvec3 scale, mat4 res)
{
    mat4 trans;

    mat4_identity(res);
    res[0][0] = scale.x;
    res[1][1] = scale.y;
    res[2][2] = scale.z;
    mat4_identity(trans);
    trans[3][0] = pos.x;
    trans[3][1] = pos.y;
    trans[3][2] = pos.z;
    mat4_mul(trans, res, res);
}

static void rot_yx(float x, float y, mat4 res)
{
    float cos, sin;
    mat4 rot_x;

    mat4_identity(res);
    cos = cosf(y);
    sin = sinf(y);
    res[0][0] = cos;
    res[2][0] = -sin;
    res[0][2] = sin;
    res[2][2] = cos;
    mat4_identity(rot_x);
    cos = cosf(x);
    sin = sinf(x);
    rot_x[1][1] = cos;
    rot_x[2][1] = sin;
    rot_x[1][2] = -sin;
    rot_x[2][2] = cos;
    mat4_mul(rot_x, res, res);
}

void mat4_rot(dvec3 rot, mat4 res)
{
    float cos, sin;
    mat4 rot_z;

    rot_yx(rot.x, rot.y, res);
    mat4_identity(rot_z);
    cos = cosf(rot.z);
    sin = sinf(rot.z);
    rot_z[0][0] = cos;
    rot_z[0][1] = -sin;
    rot_z[1][0] = sin;
    rot_z[1][1] = cos;
    mat4_mul(rot_z, res, res);
}

void mat4_model(dvec3 pos, dvec3 scale, dvec3 rot, mat4 res)
{
    mat4 scale_trans;

    mat4_rot(rot, res);
    mat4_scale_trans(pos, scale, scale_trans);
    mat4_mul(scale_trans, res, res);
}

void mat4_view(dvec3 pos, dvec3 rot, mat4 res)
{
    mat4 rot_mat;

    mat4_identity(res);
    res[3][0] = -pos.x;
    res[3][1] = -pos.y;
    res[3][2] = -pos.z;
    mat4_rot((dvec3){-rot.x, -rot.y, -rot.z}, rot_mat);
    mat4_mul(rot_mat, res, res);
}
