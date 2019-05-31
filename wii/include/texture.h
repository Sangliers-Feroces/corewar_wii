/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#pragma once

#define TEXTURE_CLUSTER_ROW_ALLOC_STEP 32
#define TEXTURE_ALLOC_MARGIN 2

texture2* texture2_create(uint32_t w, uint32_t h);
void texture2_destroy(texture2 *texture);
ivec2 texture2_get_nearest(vec2 p, vec2 size);

texture2* texture2_load(const char *path);

texture2_binding texture2_binding_create(dvec3 *triangle);
void texture2_binding_destroy(texture2_binding binding);
void texture2f_binding_free(texture2f_binding binding);

void texture2f_write(texture2f *texture, float aperture);

texture2f* texture2f_create(uint32_t w, uint32_t h);
void texture2f_destroy(texture2f *texture);

void texture2f_reset(texture2f *texture);
float texture2f_get_max_lumel(texture2f *texture);
void texture2f_write_color_bar(texture2f *texture, vec2 *uv, dvec3 bar,
dvec3 color);

vec4 texture2f_sample(texture2f *texture, vec2 uv);

void texture2f_refresh_gpu(texture2f *texture);
void texture2f_refresh_cpu(texture2f *texture);

texture2f_binding texture2f_binding_create(dvec3 *triangle);
void texture2f_binding_destroy(texture2f_binding binding);

void gl_set_texture_parameters(gluint texture);

texture_cluster texture_cluster_create(void);
void texture_cluster_destroy(texture_cluster cluster);
int texture_cluster_add_row(texture_cluster *cluster, int32_t power);
int texture_cluster_allocate(texture_cluster *cluster, ivec2 size,
texture_cluster_row_alloc **pres);

void vec_texture_cluster_row_alloc_init(vec_texture_cluster_row_alloc *vec,
int32_t w);
texture_cluster_row texture_cluster_row_init(texture_cluster *cluster,
int32_t power);
texture_cluster_row_alloc* vec_texture_cluster_row_alloc_insert(
vec_texture_cluster_row_alloc *vec, size_t pos, int32_t start, int32_t size);
int texture_cluster_row_search(texture_cluster_row *row, ivec2 size,
int32_t *pres, int32_t *start);

texture_cluster_row_alloc* texture_cluster_insert_alloc(
texture_cluster *cluster, texture_cluster_alloc_info info,
int32_t pos, int32_t start);
int texture_cluster_alloc_try_fast_lookup(texture_cluster *cluster,
ivec2 size, int32_t power, texture_cluster_row_alloc **pres);

void lightmap_init(void);
void lightmap_quit(void);
int lightmap_allocate(ivec2 size, texture_cluster_row_alloc **pres);
void lightmap_fill(rect_t rect, float value);

void tex_init(demo_t *demo);
void tex_quit(demo_t *demo);
