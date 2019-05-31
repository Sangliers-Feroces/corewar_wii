/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void mesh_full_add_triangle_pos_uv(mesh_full_t *mesh, const vec3 *pos,
const vec2 *uv)
{
    vec3 normal = normal3(pos[0], pos[1], pos[2]);

    for (size_t i = 0; i < 3; i++)
        mesh_add_vertex(mesh->mesh, vertex_init(pos[i], normal, uv[i]));
}

void mesh_full_add_triangle_pos(mesh_full_t *mesh, const vec3 *pos)
{
    vec3 normal = normal3(pos[0], pos[1], pos[2]);
    vec2 uv = {0.0f, 0.0f};

    for (size_t i = 0; i < 3; i++)
        mesh_add_vertex(mesh->mesh, vertex_init(pos[i], normal, uv));
}

void mesh_full_add_quad(mesh_full_t *mesh, const vec3 *pos)
{
    vec3 last;
    vec3 normal = normal3(pos[0], pos[1], pos[2]);
    vec2 uv[4] = {{0.0f, 1.0f}, {0.0f, 0.0f}, {1.0f, 1.0f}, {1.0f, 0.0f}};

    last = vec3_muls(vec3_add(pos[1], pos[2]), 0.5f);
    last = vec3_add(last, vec3_sub(last, pos[0]));
    for (size_t i = 0; i < 3; i++)
        mesh_add_vertex(mesh->mesh, vertex_init(pos[i], normal, uv[i]));
    for (size_t i = 0; i < 2; i++)
        mesh_add_vertex(mesh->mesh, vertex_init(pos[2 - i], normal, uv[2 - i]));
    mesh_add_vertex(mesh->mesh, vertex_init(last, normal, uv[3]));
}

void mesh_full_add_vertex(mesh_full_t *mesh, vertex_t vertex)
{
    mesh_add_vertex(mesh->mesh, vertex);
    mesh_full_ensure_coherence(mesh);
}

void mesh_full_add_vertex_ext(mesh_full_t *mesh, vertex_t vertex,
vertex_ext_t ext)
{
    size_t cur = mesh->ext_count++;
    vertex_ext_t *new_ext;

    if (mesh->ext_count > mesh->ext_allocated) {
        mesh->ext_allocated += 64;
        new_ext =
        (vertex_ext_t*)malloc_safe(mesh->ext_allocated * sizeof(vertex_ext_t));
        for (size_t i = 0; i < cur; i++)
            new_ext[i] = mesh->ext[i];
        free(mesh->ext);
        mesh->ext = new_ext;
    }
    mesh->ext[cur] = ext;
    if (mesh->gpu.do_upload)
        mesh->gpu.do_reupload = 1;
    mesh_full_add_vertex(mesh, vertex);
    mesh_full_ensure_coherence(mesh);
}
