/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static void set_mat(transform_t *res)
{
    dmat4_identity(res->model);
    dmat4_identity(res->model_rot);
    dmat4_identity(res->world);
    dmat4_identity(res->world_rot);
    dmat4_identity(res->world_inv);
    dmat4_identity(res->world_on_inv_calculated);
}

transform_t transform_get_default(void)
{
    transform_t res;

    res.is_static = 1;
    res.is_physics = 0;
    res.is_collision = 0;
    res.is_grounded = 0;
    res.slide_threshold = 1.0;
    res.t = 0.0;
    res.life = FLT64_INF;
    res.pos = dvec3_init(0.0, 0.0, 0.0);
    res.scale = dvec3_init(1.0, 1.0, 1.0);
    res.rot = dvec3_init(0.0, 0.0, 0.0);
    res.speed = dvec3_init(0.0, 0.0, 0.0);
    res.pos_on_model = dvec3_init(0.0, 0.0, 0.0);
    res.scale_on_model = dvec3_init(1.0, 1.0, 1.0);
    res.rot_on_model = dvec3_init(0.0, 0.0, 0.0);
    set_mat(&res);
    return res;
}
