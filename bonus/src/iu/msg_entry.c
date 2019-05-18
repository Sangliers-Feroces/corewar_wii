/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** iu_draw
*/

#include "headers.h"

void msg_entry_destroy(msg_entry_t to_destroy)
{
    free(to_destroy.to_display);
}

void vec_msg_entry_add(vec_msg_entry_t *vec, msg_entry_t to_add)
{
    size_t cur = vec->count++;

    if (vec->count > vec->allocated) {
        vec->allocated += 8;
        vec->msg = (msg_entry_t*)realloc(vec->msg,
        vec->allocated * sizeof(msg_entry_t));
    }
    vec->msg[cur] = to_add;
}

void vec_msg_entry_delete(vec_msg_entry_t *vec, size_t ndx)
{
    msg_entry_destroy(vec->msg[ndx]);
    vec->count--;
    for (size_t i = ndx; i < vec->count; i++)
        vec->msg[i] = vec->msg[i + 1];
}

void vec_msg_entry_flush(vec_msg_entry_t *vec)
{
    for (size_t i = 0; i < vec->count; i++)
        msg_entry_destroy(vec->msg[i]);
    vec->count = 0;
}

void vec_msg_entry_destroy(vec_msg_entry_t *vec)
{
    for (size_t i = 0; i < vec->count; i++)
        msg_entry_destroy(vec->msg[i]);
    free(vec->msg);
}
