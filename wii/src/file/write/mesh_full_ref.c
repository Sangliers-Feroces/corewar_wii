/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void file_write_mesh_gpu(file_write_t *file, mesh_gpu_t gpu)
{
    file_write(file, &gpu, sizeof(mesh_gpu_t));
}

void file_write_mesh(file_write_t *file, mesh_t *mesh)
{
    file_write_mesh_gpu(file, mesh->gpu);
    file_write_size_t(file, mesh->vertex_count);
    file_write(file, mesh->vertex, mesh->vertex_count * sizeof(vertex_t));
}

void file_write_mesh_full(file_write_t *file, mesh_full_t *mesh)
{
    file_write_mesh_gpu(file, mesh->gpu);
    file_write_int(file, mesh->has_ext);
    file_write_mesh(file, mesh->mesh);
    file_write_size_t(file, mesh->ext_count);
    file_write(file, mesh->ext, mesh->ext_count * sizeof(vertex_ext_t));
}

void file_write_mesh_full_ref(file_write_t *file, mesh_full_ref_t mesh)
{
    file_write(file, &mesh.ref_type, sizeof(mesh_full_ref_type_t));
    file_write(file, &mesh.bank, sizeof(mesh_bank_t));
    if (mesh.ref_type == MESH_FULL_REF_STANDALONE) {
        if (mesh.m == NULL)
            file_write_data_ref(file, FILE_DATA_NULL);
        else {
            file_write_data_ref(file, FILE_DATA_HERE);
            file_write_mesh_full(file, mesh.m);
        }
    }
}
