/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

size_t file_read_size_t(file_read_t *file)
{
    size_t res;

    file_read(file, &res, sizeof(size_t));
    return res;
}

void file_read_transform(file_read_t *file, transform_t *transform)
{
    file_read(file, transform, sizeof(transform_t));
}

render_obj_t file_read_render_obj(file_read_t *file)
{
    render_obj_t res;

    res.mesh = file_read_mesh_full_ref(file, NULL);
    file_read(file, &res.material, sizeof(material_t));
    return res;
}

entity3* file_read_entity3(file_read_t *file, entity3 *parent)
{
    entity3 *res = entity3_create(parent);
    size_t sub_count;
    mesh_full_ref_t col_mesh;

    file_read_transform(file, &res->trans);
    for (size_t i = 0; i < WORLD_LOD_COUNT; i++)
        res->render[i] = file_read_render_obj(file);
    file_read(file, &res->lod_dist, sizeof(render_obj_lod_dist_t));
    res->render_is_rec = file_read_int(file);
    col_mesh = file_read_mesh_full_ref(file, res);
    entity3_add_trigger(res, file_read_trigger(file));
    file_read(file, &res->tag, sizeof(entity3_tag_t));
    res->tag_data = file_read_string(file);
    sub_count = file_read_size_t(file);
    for (size_t i = 0; i < sub_count; i++)
        file_read_entity3(file, res);
    if (col_mesh.m != NULL)
        entity3_bind_col(res, col_mesh);
    return res;
}
