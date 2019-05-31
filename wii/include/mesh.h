/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#pragma once

void mesh_gpu_init(mesh_t *mesh);
void mesh_full_ext_gpu_init(mesh_full_t *mesh);
void mesh_gpu_destroy(mesh_gpu_t gpu);

void mesh_set_vertex_attrib(gluint vertex_array, gluint vertex_buffer);
void mesh_ext_set_vertex_attrib(gluint vertex_array,
gluint vertex_buffer, gluint vertex_ext_buffer);

mesh_t* mesh_create(int gpu_do_upload);
void mesh_destroy(mesh_t *mesh);
void mesh_add_vertex(mesh_t *mesh, vertex_t vertex);
void mesh_add_triangle(mesh_t *mesh, vertex_t *triangle);
void mesh_add_triangle_pos_uv(mesh_t *mesh, vec3 *pos, vec2 *uv);
void mesh_full_add_triangle_pos_uv(mesh_full_t *mesh, const vec3 *pos,
const vec2 *uv);
void mesh_full_add_triangle_pos(mesh_full_t *mesh, const vec3 *pos);
void mesh_full_add_quad(mesh_full_t *mesh, const vec3 *pos);
mesh_full_t* mesh_full_create_adv(int gpu_do_upload, int has_ext,
int do_create_sub);
mesh_full_t* mesh_full_create(int gpu_do_upload, int has_ext);
void mesh_full_destroy(mesh_full_t *mesh);
void mesh_full_ensure_coherence(mesh_full_t *mesh);
void mesh_full_add_vertex(mesh_full_t *mesh, vertex_t vertex);
void mesh_full_add_vertex_ext(mesh_full_t *mesh, vertex_t vertex,
vertex_ext_t ext);

mesh_full_ref_t mesh_full_ref_init(mesh_full_ref_type_t ref_type,
mesh_full_t *m);
mesh_full_ref_t mesh_full_ref_bank_init(mesh_bank_t bank);
mesh_full_ref_t mesh_full_ref_get_null(void);
mesh_full_ref_t entity3_get_lod_ref(entity3 *ent, size_t lod);

vec_mesh_full_t vec_mesh_full_init(void);
void vec_mesh_full_add(vec_mesh_full_t *vec, mesh_full_t *to_add);
void vec_mesh_full_destroy(vec_mesh_full_t vec);

vertex_t vertex_init(vec3 pos, vec3 normal, vec2 uv);

void mesh_bank_init(void);
void mesh_bank_quit(void);

mesh_full_t* mesh_load_obj(const char *filepath);
