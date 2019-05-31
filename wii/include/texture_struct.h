/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** headers
*/

#pragma once

typedef enum {
    TEX_GRASS,
    TEX_WATER,
    TEX_VEG_GRASS1,
    TEX_RED,
    TEX_WOOD,
    TEX_NPC1,
    TEX_METAL_RUST,
    TEX_METAL_BARE,
    TEX_MAX
} tex_t;

typedef struct {
    vec2 size;
    int32_t w;
    int32_t h;
    size_t max_ndx;
    gluint id;
} texture2;

typedef struct {
    vec2 size;
    int32_t w;
    int32_t h;
    size_t max_ndx;
    vec4 *pixel;
    gluint id;
} texture2f;

typedef struct {
    size_t row;
    int32_t start;
    int32_t size;
    size_t shared_count;
    rect_t rect;
} texture_cluster_row_alloc;

typedef struct {
    size_t count;
    size_t allocated;
    texture_cluster_row_alloc **cluster_row;    // to keep references safe
} vec_texture_cluster_row_alloc;                // still a normal 1D-array

typedef struct {
    int32_t power;
    int32_t h;
    size_t to_lookup;
    vec_texture_cluster_row_alloc row_allocs;
} texture_cluster_row;

typedef struct {
    size_t count;
    size_t allocated;
    texture_cluster_row *cluster_row;
} vec_texture_cluster_row;

typedef struct {
    texture2f *base;
    int32_t to_fill_y;
    float aperture;
    vec_texture_cluster_row rows;
} texture_cluster;

typedef struct {
    size_t row;
    int32_t power;
    ivec2 size;
} texture_cluster_alloc_info;

typedef struct {
    texture2 *texture;
    vec2 uv[3];
} texture2_binding;    /* the object linked                               */

typedef struct {
    texture2f *texture;
    vec2 uv[3];
    texture_cluster_row_alloc *alloc;
} texture2f_binding;

typedef struct {
    tex_t tex;
    const char *path;
} tex_desc_t;
