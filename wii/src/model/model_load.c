/*
** EPITECH PROJECT, 2019
** teck1
** File description:
** model_load
*/

#include "headers.h"

/*static size_t get_next_space_pos(const char *str, size_t i)
{
    size_t res = 0;

    for (; (str[i + res] != ' ') && (str[i + res] != '\0'); res++);
    return res;
}

static void parse_f(const char *line, model_obj_parsing_t *obj,
mesh_full_t *res)
{
    size_t i = 1;
    size_t next;

    while (line[i] == ' ') {
        next = get_next_space_pos(line, i + 1);
        vec_size3_add(&obj->f, model_load_extract_ndx(line, i + 1));
        i += next + 1;
    }
    if (obj->f.count == 0)
        return;
    for (size_t i = 1; i < obj->f.count - 1; i++) {
        mesh_full_add_vertex(res, vertex_from_obj(obj, obj->f.size3[0]));
        mesh_full_add_vertex(res, vertex_from_obj(obj, obj->f.size3[i]));
        mesh_full_add_vertex(res, vertex_from_obj(obj, obj->f.size3[i + 1]));
    }
    vec_size3_flush(&obj->f);
}

static void do_stuff_line(const char *line, model_obj_parsing_t *obj,
mesh_full_t *res, size_t *do_flush)
{
    if (line[0] == 'v') {
        if (*do_flush) {
            model_obj_parsing_flush(obj);
            *do_flush = 0;
        }
        model_load_parse_v(line, obj);
    }
    else if (line[0] == 'f') {
        parse_f(line, obj, res);
        *do_flush = 1;
    }
}*/

mesh_full_t* mesh_load_obj(const char *filepath)
{
    FILE *file = fopen(filepath, "rb");
    mesh_full_t *res;
    //size_t n = 0;
    char *line = NULL;
    model_obj_parsing_t obj = model_obj_parsing_init();
    //size_t do_flush = 0;

    if (file == NULL)
        return NULL;
    res = mesh_full_create(1, 0);
    /*while (getline(&line, &n, file) >= 0)
        do_stuff_line(line, &obj, res, &do_flush);*/
    model_obj_parsing_destroy(&obj);
    fclose(file);
    free(line);
    return (res);
}
