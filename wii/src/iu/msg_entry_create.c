/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** msg_entry_create
*/

#include "headers.h"

vec_msg_entry_t vec_msg_entry_create(void)
{
    vec_msg_entry_t res;

    res.count = 0;
    res.allocated = 0;
    res.msg = NULL;
    return res;
}

msg_entry_t msg_entry_create(char *buf, double start, double life)
{
    msg_entry_t res;

    res.to_display = strdup(buf);
    res.start = start;
    res.life = life;
    return res;
}