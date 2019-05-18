/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#pragma once

void world_insert_start(void);
void world_insert_end(size_t lod_collision);
void world_insert_mesh(mesh_full_t *mesh, material_t material, size_t lod);
void world_insert_arr_dvec3(arr_dvec3_t arr, material_t material, size_t lod);

void world_init(demo_t *demo);
void world_load_map(void);
void world_unload_map(void);
void world_quit(demo_t *demo);

void world_ensure_current_map_folder(void);
void world_load_meta_map(void);

chunk_t** world_chunk2d_get(ssize2 pos);
void world_chunk2d_insert(chunk_t *chunk);
chunk_t* world_chunk_get_adv(ssize2 pos, int do_load, int do_gen);
chunk_t* world_chunk_get(ssize2 pos);
ssize2 chunk_get_pos(dvec3 pos);
ssize2 chunk_get_terrain_pos(ssize2 chunk_pos);
chunk_t* world_chunk_get_by_pos(dvec3 pos);

chunk_t* chunk_create_detached(ssize2 pos);
void chunk_attach(chunk_t *chunk);
chunk_t* chunk_create_adv(ssize2 pos, int do_gen);
chunk_t* chunk_create(ssize2 pos);
void chunk_destroy(chunk_t *chunk);

chunk_lod_t chunk_lod_create(size_t lod);
void chunk_lod_destroy(chunk_lod_t *lod);

void world_render(void);

void world_update(void);

vec_chunk_vertex_t vec_chunk_vertex_create(size_t count);
void vec_chunk_vertex_destroy(vec_chunk_vertex_t vec);
vec_chunk_dvertex_t vec_chunk_dvertex_create(size_t count);
void vec_chunk_dvertex_destroy(vec_chunk_dvertex_t vec);

double chunk_get_strength(ssize2 pos);
void chunk_gen_terrain(ssize2 pos);
void chunk_detail_terrain(chunk_t *chunk);

chunk_border_t chunk_border_ter_fetch(ssize2 pos);
chunk_border_t chunk_border_fetch(ssize2 pos);
chunk_border_t chunk_border_init(void);
void chunk_border_destroy(chunk_border_t border);

void world_chunk_god(void);

void world_chunk_god_stalled(void);

void world_chunk_send_global_ent(ssize2 chunk_pos, entity3 *ent);

entity3* world_create_default_ents(void);

int world_is_chunk_active(ssize2 chunk_pos);
int world_is_pos_col_oob(dvec3 p);

void chunk_load_ext(chunk_t *chunk);
void chunk_store_ext(chunk_t *chunk);
int chunk_refresh_ext(chunk_t *chunk, ssize2 cam);
entity3* chunk_add_entity_ext(chunk_t *chunk);

inter_ray3 world_inter(ray3 ray);
inter_ray3 world_inter_laxist(ray3 ray);
inter_ray3 world_inter_laxist_fast(ray3 ray);
int physics_check_col(physics_param_t p, dvec3 pos, dvec3 *speed,
dvec3 *avg_norm);
void physics_apply_disp(int do_fast, dvec3 *p, dvec3 disp);

void chunk_spawn_at(chunk_t *chunk, dvec3 pos);
