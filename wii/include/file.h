/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#pragma once

file_write_t file_write_create(void);
void file_write_actual(file_write_t *file, const void *src, size_t size);
void file_write(file_write_t *file, const void *src, size_t size);
void file_write_flush(file_write_t *file, const char *path);
void file_write_data_ref(file_write_t *file, file_data_ref_t ref_type);

void file_write_int(file_write_t *file, int value);
void file_write_string(file_write_t *file, const char *value);
void file_write_dvec3(file_write_t *file, dvec3 value);

file_read_t file_read_create(const char *path);
void file_read_actual(file_read_t *file, void *dst, size_t size);
void file_read(file_read_t *file, void *dst, size_t size);
void file_read_flush(file_read_t *file);
file_data_ref_t file_read_data_ref(file_read_t *file);

int file_read_int(file_read_t *file);
char* file_read_string(file_read_t *file);
dvec3 file_read_dvec3(file_read_t *file);

void file_write_size_t(file_write_t *file, size_t value);
void file_write_transform(file_write_t *file, transform_t *transform);
void file_write_render_obj(file_write_t *file, render_obj_t *render);
void file_write_entity3(file_write_t *file, entity3 *ent);

void file_write_mesh_gpu(file_write_t *file, mesh_gpu_t gpu);
void file_write_mesh(file_write_t *file, mesh_t *mesh);
void file_write_mesh_full(file_write_t *file, mesh_full_t *mesh);
void file_write_mesh_full_ref(file_write_t *file, mesh_full_ref_t mesh);

void file_write_ssize2(file_write_t *file, ssize2 value);
void file_write_arr_dvec3(file_write_t *file, arr_dvec3_t arr);
void file_write_arr2d_dvec3(file_write_t *file, arr2d_dvec3_t arr);
void file_write_chunk_border(file_write_t *file, chunk_border_t *border);
void file_write_chunk(file_write_t *file, chunk_t *chunk);

void file_write_trigger_on_hit(file_write_t *file, trigger_on_hit_t value);
void file_write_trigger(file_write_t *file, trigger_t *trigger);

size_t file_read_size_t(file_read_t *file);
void file_read_transform(file_read_t *file, transform_t *transform);
render_obj_t file_read_render_obj(file_read_t *file);
entity3* file_read_entity3(file_read_t *file, entity3 *parent);

mesh_gpu_t file_read_mesh_gpu(file_read_t *file);
mesh_t* file_read_mesh(file_read_t *file);
mesh_full_t* file_read_mesh_full(file_read_t *file);
mesh_full_ref_t file_read_mesh_full_ref(file_read_t *file, entity3 *ent);

ssize2 file_read_ssize2(file_read_t *file);
arr_dvec3_t file_read_arr_dvec3(file_read_t *file);
arr2d_dvec3_t file_read_arr2d_dvec3(file_read_t *file);
chunk_border_t file_read_chunk_border(file_read_t *file);
chunk_t* file_read_chunk(file_read_t *file);

trigger_on_hit_t file_read_trigger_on_hit(file_read_t *file);
trigger_t* file_read_trigger(file_read_t *file);

char* map_get_path(const char *file);
int chunk_is_loaded(ssize2 pos);
int chunk_try_load(ssize2 pos, chunk_t **pres);
void chunk_save(chunk_t *chunk);
