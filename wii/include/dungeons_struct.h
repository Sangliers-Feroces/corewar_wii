/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** dungeons_struct
*/

#pragma once

typedef enum {
    DUNGEONS_NEXT_POS_NORTH,
    DUNGEONS_NEXT_POS_EAST,
    DUNGEONS_NEXT_POS_SOUTH,
    DUNGEONS_NEXT_POS_WEST
} dungeons_next_pos_t;

typedef struct {
    float offset_rooms;
    gluint program;
    gluint vertex_buffer;
    dvec3 cur_origin;
    dungeons_next_pos_t next_pos;

} dungeons_t;
