/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

inter_ray3 world_inter(ray3 ray)
{
    return octree_intersect_ray(_demo->world.tree, ray);
}

inter_ray3 world_inter_laxist(ray3 ray)
{
    return octree_intersect_ray_laxist(_demo->world.tree, ray);
}

inter_ray3 world_inter_laxist_fast(ray3 ray)
{
    return octree_intersect_ray_laxist_fast(_demo->world.tree, ray);
}

int physics_check_col(physics_param_t p, dvec3 pos, dvec3 *speed,
dvec3 *avg_norm)
{
    inter_ray3 inter = p.do_fast ? world_inter_laxist_fast(
    (ray3){pos, *speed}) : world_inter_laxist((ray3){pos, *speed});
    dvec3 p_in;
    dvec3 up = {0.0, 1.0, 0.0};
    dvec3 normal;

    if (inter.triangle == NULL)
        return 0;
    if (inter.min_t > (p.do_laxist ? 0.999 : 1.0))
        return 0;
    p_in = dvec3_add(pos, *speed);
    normal = dvec3_dot(inter.triangle->normal, up) > p.slide ?
    up : inter.triangle->normal;
    inter = rtx_triangle_intersect_ray_no_cull(inter.triangle,
    (ray3){p_in, normal});
    if (inter.triangle == NULL)
        return 0;
    *speed = dvec3_add(*speed, dvec3_muls(dvec3_sub(inter.p, p_in), 1.0));
    *avg_norm = dvec3_add(*avg_norm, normal);
    return 1;
}

void physics_apply_disp(int do_fast, dvec3 *p, dvec3 disp)
{
    inter_ray3 inter = do_fast ? world_inter_laxist_fast((ray3){*p, disp}) :
    world_inter_laxist((ray3){*p, disp});

    if ((inter.triangle == NULL) || (inter.min_t > 1.0)) {
        *p = dvec3_add(*p, disp);
        return;
    }
    *p = dvec3_add(inter.p, dvec3_muls(dvec3_normalize(disp), -0.001));
}
