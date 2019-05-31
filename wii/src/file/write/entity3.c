/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void file_write_size_t(file_write_t *file, size_t value)
{
    file_write(file, &value, sizeof(size_t));
}

void file_write_transform(file_write_t *file, transform_t *transform)
{
    file_write(file, transform, sizeof(transform_t));
}

void file_write_render_obj(file_write_t *file, render_obj_t *render)
{
    file_write_mesh_full_ref(file, render->mesh);
    file_write(file, &render->material, sizeof(material_t));
}

void file_write_entity3(file_write_t *file, entity3 *ent)
{
    file_write_transform(file, &ent->trans);
    for (size_t i = 0; i < WORLD_LOD_COUNT; i++)
        file_write_render_obj(file, &ent->render[i]);
    file_write(file, &ent->lod_dist, sizeof(render_obj_lod_dist_t));
    file_write_int(file, ent->render_is_rec);
    file_write_mesh_full_ref(file, ent->col.mesh);
    file_write_trigger(file, ent->trigger);
    file_write(file, &ent->tag, sizeof(entity3_tag_t));
    file_write(file, ent->tag_data, _demo->world.tag[ent->tag].data_size);
    file_write_size_t(file, ent->sub.count);
    for (size_t i = 0; i < ent->sub.count; i++)
        file_write_entity3(file, ent->sub.ent[i]);
}
