/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void mesh_add_vertex(mesh_t *mesh, vertex_t vertex)
{
    size_t cur = mesh->vertex_count++;
    vertex_t *new_vertex;

    if (mesh->vertex_count > mesh->vertex_allocated) {
        mesh->vertex_allocated += 64;
        new_vertex =
        (vertex_t*)malloc_safe(mesh->vertex_allocated * sizeof(vertex_t));
        for (size_t i = 0; i < cur; i++)
            new_vertex[i] = mesh->vertex[i];
        free(mesh->vertex);
        mesh->vertex = new_vertex;
    }
    mesh->vertex[cur] = vertex;
    if (mesh->gpu.do_upload)
        mesh->gpu.do_reupload = 1;
}

void mesh_add_triangle(mesh_t *mesh, vertex_t *triangle)
{
    for (size_t i = 0; i < 3; i++)
        mesh_add_vertex(mesh, triangle[i]);
}

void mesh_add_triangle_pos_uv(mesh_t *mesh, vec3 *pos, vec2 *uv)
{
    vec3 normal = normal3(pos[0], pos[1], pos[2]);

    for (size_t i = 0; i < 3; i++)
        mesh_add_vertex(mesh, vertex_init(pos[i], normal, uv[i]));
}
