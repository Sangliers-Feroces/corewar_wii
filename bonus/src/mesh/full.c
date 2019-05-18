/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

mesh_full_t* mesh_full_create_adv(int gpu_do_upload, int has_ext,
int do_create_sub)
{
    mesh_full_t *res = (mesh_full_t*)malloc_safe(sizeof(mesh_full_t));

    if (do_create_sub)
        res->mesh = mesh_create(gpu_do_upload);
    else
        res->mesh = NULL;
    res->has_ext = has_ext;
    if (has_ext) {
        res->ext_count = 0;
        res->ext_allocated = 0;
        res->ext = NULL;
        if (do_create_sub)
            mesh_full_ext_gpu_init(res);
    } else {
        res->ext_count = 0;
        res->ext_allocated = 0;
        res->ext = NULL;
        res->gpu = (mesh_gpu_t){0, 0, 0, 0, NULL, 0};
    }
    return res;
}

mesh_full_t* mesh_full_create(int gpu_do_upload, int has_ext)
{
    return mesh_full_create_adv(gpu_do_upload, has_ext, 1);
}

void mesh_full_destroy(mesh_full_t *mesh)
{
    if (mesh->has_ext)
        mesh_gpu_destroy(mesh->gpu);
    mesh_destroy(mesh->mesh);
    free(mesh->ext);
    free(mesh);
}

void mesh_full_ensure_coherence(mesh_full_t *mesh)
{
    if (mesh->has_ext)
        if (mesh->ext_count != mesh->mesh->vertex_count) {
            printf(
            "Error: incoherent mesh_full: %zu vertex and %zu extensions.\n",
            mesh->mesh->vertex_count, mesh->ext_count);
            exit(84);
        }
}
