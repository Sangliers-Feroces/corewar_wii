/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

mesh_t* mesh_create(int gpu_do_upload)
{
    mesh_t *res = (mesh_t*)malloc_safe(sizeof(mesh_t));

    res->vertex_count = 0;
    res->vertex_allocated = 0;
    res->vertex = NULL;
    if (gpu_do_upload)
        mesh_gpu_init(res);
    else
        res->gpu = (mesh_gpu_t){0, 0, 0, 0, NULL, 0};
    return res;
}

void mesh_destroy(mesh_t *mesh)
{
    mesh_gpu_destroy(mesh->gpu);
    free(mesh->vertex);
    free(mesh);
}
