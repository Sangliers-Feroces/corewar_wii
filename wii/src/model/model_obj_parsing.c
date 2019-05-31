/*
** EPITECH PROJECT, 2019
** teck1
** File description:
** model_load
*/

#include "headers.h"

model_obj_parsing_t model_obj_parsing_init(void)
{
    model_obj_parsing_t res;

    res.p = vec_vec3_init();
    res.n = vec_vec3_init();
    res.t = vec_vec2_init();
    res.f = vec_size3_init();
    return res;
}

void model_obj_parsing_flush(model_obj_parsing_t *obj)
{
    obj->p.count = 0;
    obj->n.count = 0;
    obj->t.count = 0;
    obj->f.count = 0;
}

void model_obj_parsing_destroy(model_obj_parsing_t *obj)
{
    vec_vec3_destroy(obj->p);
    vec_vec3_destroy(obj->n);
    vec_vec2_destroy(obj->t);
    vec_size3_destroy(obj->f);
}
