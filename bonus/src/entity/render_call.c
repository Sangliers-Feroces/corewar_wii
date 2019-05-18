/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

vec_render_call_t vec_render_call_init(void)
{
    vec_render_call_t res;

    res.count = 0;
    res.allocated = 0;
    res.call = NULL;
    return res;
}

void vec_render_call_add(vec_render_call_t *vec, render_call_t to_add)
{
    size_t cur = vec->count++;

    if (vec->count > vec->allocated) {
        vec->allocated += 64;
        vec->call = realloc(vec->call, vec->allocated * sizeof(render_call_t));
    }
    vec->call[cur] = to_add;
}

void vec_render_call_flush(vec_render_call_t *vec)
{
    render_call_t cur;

    for (size_t i = 0; i < vec->count; i++) {
        cur = vec->call[i];
        _demo->material[cur.material].world(
        cur.mvp.data, cur.world.data, cur.rot.data);
        //glBindVertexArray(cur.vertex_array);
        //glDrawArrays(GL_TRIANGLES, 0, cur.count);
    }
    vec->count = 0;
}

void vec_render_call_destroy(vec_render_call_t vec)
{
    vec_render_call_flush(&vec);
    free(vec.call);
}
