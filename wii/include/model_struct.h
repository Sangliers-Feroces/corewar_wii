/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#pragma once

typedef enum {
    MODEL_EDITOR_SELECT,
    MODEL_EDITOR_X,
    MODEL_EDITOR_Y,
    MODEL_EDITOR_Z,
    MODEL_EDITOR_MAX
} model_editor_t;

typedef struct {
    vec_vec3_t p;
    vec_vec3_t n;
    vec_vec2_t t;
    vec_size3_t f;
} model_obj_parsing_t;
