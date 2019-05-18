/*
** EPITECH PROJECT, 2019
** teck1
** File description:
** model_load
*/

#include "headers.h"

vec3 vec3_parse(const char *line)
{
    vec3 res;

    sscanf(line, " %f %f %f", &res.x, &res.y, &res.z);
    return res;
}

vec2 vec2_parse(const char *line)
{
    vec2 res;

    sscanf(line, " %f %f", &res.x, &res.y);
    return res;
}

void model_load_parse_v(const char *line, model_obj_parsing_t *obj)
{
    switch (line[1]) {
    case ' ':
        return vec_vec3_add(&obj->p, vec3_parse(&line[2]));
    case 't':
        return vec_vec2_add(&obj->t, vec2_parse(&line[2]));
    case 'n':
        return vec_vec3_add(&obj->n, vec3_parse(&line[2]));
    }
}

vertex_t vertex_from_obj(model_obj_parsing_t *obj, size3 ndx)
{
    vertex_t res;

    res.pos = (vec3){0.0, 0.0, 0.0};
    res.normal = (vec3){0.0, 0.0, 0.0};
    res.uv = (vec2){0.0, 0.0};
    if (ndx.x < obj->p.count)
        res.pos = obj->p.vec3[ndx.x];
    if (ndx.y < obj->t.count)
        res.uv = obj->t.vec2[ndx.y];
    if (ndx.z < obj->n.count)
        res.normal = obj->n.vec3[ndx.z];
    return res;
}
