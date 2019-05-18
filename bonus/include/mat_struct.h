/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** headers
*/

#pragma once

/* 1D ray */
typedef struct {
    double p;
    double v;
} ray1;

typedef struct {
    dvec3 p;
    dvec3 v;
} ray3;

typedef struct {
    ray3 ray;
    dvec3 color;
    size_t count;
} ray3_color;

typedef struct {
    vec2 c;
    float r;
} circle;

typedef enum {
    PROJ_TYPE_PERSPECTIVE,
    PROJ_TYPE_ORTHOGRAPHIC
} proj_type_t;

typedef struct {
    float near_plane;
    float far_plane;
    float fov_w;
    float ratio_wh;
} proj_t;

typedef struct {
    vec2 p;
    vec2 s;
} rect_t;

typedef struct {
    dmat4 model;
    dmat4 view;
    dmat4 proj;
    dmat4 rot;
    dmat4 vp;
} mvp_t;

typedef struct {
    dvec3 tl;
    dvec3 tr;
    dvec3 bl;
    dvec3 br;
} ray_viewport_t;
