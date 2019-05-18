/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

mesh_gpu_t file_read_mesh_gpu(file_read_t *file)
{
    mesh_gpu_t res;

    file_read(file, &res, sizeof(mesh_gpu_t));
    return res;
}

mesh_t* file_read_mesh(file_read_t *file)
{
    mesh_gpu_t gpu = file_read_mesh_gpu(file);
    mesh_t *res = mesh_create(gpu.do_upload);

    res->vertex_count = file_read_size_t(file);
    res->vertex_allocated = res->vertex_count;
    res->vertex = (vertex_t*)malloc_safe(res->vertex_count * sizeof(vertex_t));
    file_read(file, res->vertex, res->vertex_count * sizeof(vertex_t));
    return res;
}

mesh_full_t* file_read_mesh_full(file_read_t *file)
{
    mesh_gpu_t gpu = file_read_mesh_gpu(file);
    int has_ext = file_read_int(file);
    mesh_full_t *res = mesh_full_create_adv(gpu.do_upload, has_ext, 0);

    res->mesh = file_read_mesh(file);
    res->ext_count = file_read_size_t(file);
    res->ext_allocated = res->ext_count;
    res->ext =
    (vertex_ext_t*)malloc_safe(res->ext_count * sizeof(vertex_ext_t));
    file_read(file, res->ext, res->ext_count * sizeof(vertex_ext_t));
    if (has_ext)
        mesh_full_ext_gpu_init(res);
    return res;
}

mesh_full_ref_t file_read_mesh_full_ref(file_read_t *file, entity3 *ent)
{
    mesh_full_ref_t res;
    mesh_bank_t bank;

    file_read(file, &res.ref_type, sizeof(mesh_full_ref_type_t));
    file_read(file, &bank, sizeof(mesh_bank_t));
    res.m = NULL;
    if (res.ref_type == MESH_FULL_REF_STANDALONE) {
        if (file_read_data_ref(file) != FILE_DATA_NULL)
            res.m = file_read_mesh_full(file);
    } else if ((res.ref_type >= MESH_FULL_REF_RENDER_LOD0) &&
    (res.ref_type <= MESH_FULL_REF_RENDER_LOD2)) {
        if (ent != NULL)
            res.m =
            ent->render[res.ref_type - MESH_FULL_REF_RENDER_LOD0].mesh.m;
    } else
        return mesh_full_ref_bank_init(bank);
    return res;
}
