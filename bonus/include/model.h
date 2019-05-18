/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#pragma once

model_obj_parsing_t model_obj_parsing_init(void);
void model_obj_parsing_flush(model_obj_parsing_t *obj);
void model_obj_parsing_destroy(model_obj_parsing_t *obj);

vec3 vec3_parse(const char *line);
vec2 vec2_parse(const char *line);
void model_load_parse_v(const char *line, model_obj_parsing_t *obj);
vertex_t vertex_from_obj(model_obj_parsing_t *obj, size3 ndx);

size3 model_load_extract_ndx(const char *line, size_t start);
