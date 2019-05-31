/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void mesh_gpu_init(mesh_t *mesh)
{
    mesh->gpu.do_upload = 1;
    mesh->gpu.do_reupload = 1;
    mesh->gpu.disp_list = NULL;
    mesh->gpu.disp_list_size = 0;
    //glGenVertexArrays(1, &mesh->gpu.vertex_array);
    //glGenBuffers(1, &mesh->gpu.vertex_buffer);
    mesh_set_vertex_attrib(mesh->gpu.vertex_array, mesh->gpu.vertex_buffer);
}

void mesh_full_ext_gpu_init(mesh_full_t *mesh)
{
    mesh->gpu.do_upload = 1;
    mesh->gpu.do_reupload = 1;
    mesh->gpu.disp_list = NULL;
    mesh->gpu.disp_list_size = 0;
    //glGenVertexArrays(1, &mesh->gpu.vertex_array);
    //glGenBuffers(1, &mesh->gpu.vertex_buffer);
    mesh_ext_set_vertex_attrib(mesh->gpu.vertex_array,
    mesh->mesh->gpu.vertex_buffer, mesh->gpu.vertex_buffer);
}

void mesh_gpu_destroy(mesh_gpu_t gpu)
{
    if (gpu.do_upload) {
        free(gpu.disp_list);
        //glDeleteVertexArrays(1, &gpu.vertex_array);
        //glDeleteBuffers(1, &gpu.vertex_buffer);
    }
}
