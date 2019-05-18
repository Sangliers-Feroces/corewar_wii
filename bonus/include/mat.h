/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** headers
*/

#pragma once

/* math-related prototypes */

vec3 normal3(vec3 a, vec3 b, vec3 c);
dvec3 dnormal3(dvec3 a, dvec3 b, dvec3 c);

vec2 vec2_add(vec2 a, vec2 b);
vec2 vec2_adds(vec2 vec, float value);
vec2 vec2_sub(vec2 a, vec2 b);
vec2 vec2_subs(vec2 vec, float value);
vec2 vec2_min(vec2 a, vec2 b);
vec2 vec2_max(vec2 a, vec2 b);
vec2 vec2_muls(vec2 vec, float value);

vec2 vec2_mul(vec2 a, vec2 b);
vec2 vec2_div(vec2 a, vec2 b);
vec2 vec2_divs(vec2 vec, float value);

float vec2_norm(vec2 vec);
float vec2_dist(vec2 a, vec2 b);
int vec2_eq(vec2 a, vec2 b);

int dvec3_is_in_bounds(dvec3 p, bounds3 bounds);
int is_triangle_in_bounds(dvec3 *triangle, bounds3 bounds);

vec3 vec3_init(float x, float y, float z);

vec3 vec3_add(vec3 a, vec3 b);
vec3 vec3_sub(vec3 a, vec3 b);
vec3 vec3_muls(vec3 vec, float value);
vec3 vec3_divs(vec3 vec, float value);
int vec3_eq(vec3 a, vec3 b);

float vec3_dot(vec3 a, vec3 b);
float vec3_norm(vec3 vec);
float vec3_dist(vec3 a, vec3 b);
vec3 vec3_cross(vec3 a, vec3 b);
vec3 vec3_normalize(vec3 vec);

double dvec3_dot(dvec3 a, dvec3 b);
double dvec3_norm(dvec3 vec);
double dvec3_dist(dvec3 a, dvec3 b);
double dvec3_dist_sq(dvec3 a, dvec3 b);
dvec3 dvec3_cross(dvec3 a, dvec3 b);
dvec3 dvec3_normalize(dvec3 vec);

dvec3 dvec3_add(dvec3 a, dvec3 b);
dvec3 dvec3_sub(dvec3 a, dvec3 b);
dvec3 dvec3_muls(dvec3 vec, double value);
dvec3 dvec3_divs(dvec3 vec, double value);
int dvec3_eq(dvec3 a, dvec3 b);

dvec3 dvec3_mul(dvec3 a, dvec3 b);

dvec3 dvec3_adds(dvec3 vec, double value);

ivec3 ivec3_add(ivec3 a, ivec3 b);
ivec3 ivec3_sub(ivec3 a, ivec3 b);
ivec3 ivec3_muls(ivec3 vec, int32_t value);
ivec3 ivec3_divs(ivec3 vec, int32_t value);
int ivec3_eq(ivec3 a, ivec3 b);
ivec3 ivec3_init(int32_t x, int32_t y, int32_t z);
dvec3 ivec3_dvec3(ivec3 src);

dvec3 ray3_compute(ray3 ray, double t);

vec4 vec4_add(vec4 a, vec4 b);
vec4 vec4_sub(vec4 a, vec4 b);
vec4 vec4_muls(vec4 vec, double value);

void mat4_identity(mat4 dst);
void mat4_copy(mat4 src, mat4 dst);
void mat4_mul(mat4 a, mat4 b, mat4 res);

void mat4_scale_trans(dvec3 pos, dvec3 scale, mat4 res);
void mat4_rot(dvec3 rot, mat4 res);
void mat4_model(dvec3 pos, dvec3 scale, dvec3 rot, mat4 res);
void mat4_view(dvec3 pos, dvec3 rot, mat4 res);
vec4 mat4_mul_vec(mat4 a, vec4 b);

void mat4_perspective(proj_t proj, mat4 res);
void mat4_ortho(proj_t proj, mat4 res);

void dmat4_identity(dmat4 dst);
void dmat4_copy(dmat4 src, dmat4 dst);
void dmat4_mul(dmat4 a, dmat4 b, dmat4 res);

void dmat4_pos(dvec3 pos, dmat4 res);
void dmat4_scale(dvec3 scale, dmat4 res);
void dmat4_rot(dvec3 rot, dmat4 res);
void dmat4_model(transform_t *t, dmat4 res, dmat4 rot);
dvec4 dmat4_mul_vec4(dmat4 a, dvec4 b);

void dmat4_perspective(proj_t proj, dmat4 res);
void dmat4_ortho(proj_t proj, dmat4 res);
void dmat4_lookdir(dvec3 p, dvec3 f, dvec3 u, dmat4 res);

void dmat4_mat4(dmat4 src, mat4 dst);
dmat4_w dmat4_dmat4_w(dmat4 src);
dvec3 dmat4_trans(dmat4 src);
void dmat4_Mtx(dmat4 src, Mtx dst);

vec2 barycentric2_get_point(vec2 *triangle, dvec3 bar);

dvec3 barycentric3(dvec3 p, dvec3 *triangle);
int is_point_in_triangle(dvec3 p, dvec3 *triangle);
int is_barycentric_valid(dvec3 bar);
int is_point_in_triangle_get_bar(dvec3 p, dvec3 *triangle, dvec3 *bar);

int is_barycentric_valid_laxist(dvec3 bar);
int is_point_in_triangle_laxist(dvec3 p, dvec3 *triangle);

vec2 circle_intersect(circle a, circle b);

dvec3 spherical_to_cartesian_z(dvec3 spherical);
dvec3 spherical_to_cartesian_z_to_x(dvec3 spherical);

int rect_is_vec2_inside(rect_t rect, vec2 vec);

dvec3 dvec3_interpolate(dvec3 a, dvec3 b, long double ratio);

void dmat4_rot_xy(dvec3 rot, dmat4 res);
dvec3 dmat4_mul_dvec3(dmat4 mat, dvec3 vec);
dvec3 dmat4_mul_vec3(dmat4 mat, vec3 vec);

void dmat4_inv(dmat4 src, dmat4 res);
void dmat4_inv_gauss_jordan(dmat4_ext res);

ssize2 ssize2_add(ssize2 a, ssize2 b);
ssize2 ssize2_sub(ssize2 a, ssize2 b);
ssize2 ssize2_abs(ssize2 value);
ssize2 ssize2_muls(ssize2 value, ssize_t mul);
ssize_t ssize2_dist_sq_man(ssize2 a, ssize2 b);

arr2d_dvec3_t arr2d_dvec3_create(size_t w, size_t h);
void arr2d_dvec3_destroy(arr2d_dvec3_t arr);
arr_dvec3_t arr_dvec3_create(size_t count);
arr2d_dvec3_t arr2d_dvec3_copy(arr2d_dvec3_t to_copy);
arr2d_dvec3_t arr2d_dvec3_copy_rect(arr2d_dvec3_t to_copy, srect area);
void arr2d_dvec3_sub(arr2d_dvec3_t arr, dvec3 value);
void arr_dvec3_destroy(arr_dvec3_t arr);

int arr2d_dvec3_is_coord_valid(arr2d_dvec3_t arr, ssize2 uv);
dvec3 arr2d_dvec3_sample(arr2d_dvec3_t arr, ssize2 uv);
dvec3 arr2d_dvec3_sample_linear(arr2d_dvec3_t arr, vec2 uv);

vec3 dvec3_vec3(dvec3 value);
dvec3 vec3_dvec3(vec3 value);
dvec3 dvec3_init(double x, double y, double z);

vec_vec3_t vec_vec3_init(void);
void vec_vec3_add(vec_vec3_t *vec, vec3 to_add);
void vec_vec3_destroy(vec_vec3_t vec);

vec_vec2_t vec_vec2_init(void);
void vec_vec2_add(vec_vec2_t *vec, vec2 to_add);
void vec_vec2_destroy(vec_vec2_t vec);

vec_size3_t vec_size3_init(void);
void vec_size3_add(vec_size3_t *vec, size3 to_add);
void vec_size3_flush(vec_size3_t *vec);
void vec_size3_destroy(vec_size3_t vec);
