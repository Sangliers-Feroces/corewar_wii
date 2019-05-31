/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

col_ref_t col_ref_get_default(void)
{
    col_ref_t res;

    res.mesh = mesh_full_ref_get_null();
    res.ref = vec_rtx_triangle_ref_get_void();
    res.is_on = 0;
    return res;
}

static void send_col_geom_to_octree(entity3 *ent)
{
    dvec3 p[3];

    ent->col.ref =
    vec_rtx_triangle_ref_create(ent->col.mesh.m->mesh->vertex_count / 3);
    for (size_t i = 0; i < ent->col.mesh.m->mesh->vertex_count / 3; i++) {
        for (size_t j = 0; j < 3; j++)
            p[j] = dmat4_mul_vec3(ent->trans.world,
            ent->col.mesh.m->mesh->vertex[i * 3 + j].pos);
        ent->col.ref.triangle[i] =
        octree_insert_triangle(&_demo->world.tree, rtx_triangle_create(p));
    }
}

void entity3_set_col(entity3 *ent, int is_on)
{
    if (!is_on) {
        if (!ent->col.is_on)
            return;
        ent->col.is_on = is_on;
        vec_rtx_triangle_ref_destroy(ent->col.ref);
        return;
    }
    if ((ent->col.is_on) || (ent->col.mesh.m == NULL))
        return;
    ent->col.is_on = is_on;
    send_col_geom_to_octree(ent);
}

void entity3_bind_col(entity3 *entity, mesh_full_ref_t collision_mesh)
{
    int state = entity->col.is_on;

    if (collision_mesh.m == NULL) {
        printf("Warning: set null collisions.\n");
        return;
    }
    if (entity->col.mesh.m != NULL)
        entity3_set_col(entity, 0);
    entity->col.mesh = collision_mesh;
    entity3_set_col(entity, state);
}
