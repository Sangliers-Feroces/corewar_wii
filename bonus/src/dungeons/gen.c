/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** dungeons_gen
*/

#include "headers.h"

static dvec3 g_vertex_buffer_data[][3] = {
    {{-1.0f, -1.0f, -1.0f},
    {-1.0f, -1.0f, 1.0f},
    {-1.0f, 1.0f, 1.0f}},
    {{1.0f, 1.0f, -1.0f},
    {-1.0f, -1.0f, -1.0f},
    {-1.0f, 1.0f, -1.0f}},
    {{1.0f, -1.0f, 1.0f},
    {-1.0f, -1.0f, -1.0f},
    {1.0f, -1.0f, -1.0f}},
    {{1.0f, 1.0f, -1.0f},
    {1.0f, -1.0f, -1.0f},
    {-1.0f, -1.0f, -1.0f}},
    {{-1.0f, -1.0f, -1.0f},
    {-1.0f, 1.0f, 1.0f},
    {-1.0f, 1.0f, -1.0f}},
    {{1.0f, -1.0f, 1.0f},
    {-1.0f, -1.0f, 1.0f},
    {-1.0f, -1.0f, -1.0f}},
    {{-1.0f, 1.0f, 1.0f},
    {-1.0f, -1.0f, 1.0f},
    {1.0f, -1.0f, 1.0f}},
    {{1.0f, 1.0f, 1.0f},
    {1.0f, -1.0f, -1.0f},
    {1.0f, 1.0f, -1.0f}},
    {{1.0f, -1.0f, - 1.0f},
    {1.0f, 1.0f, 1.0f},
    {1.0f, -1.0f, 1.0f}},
    {{1.0f, 1.0f, 1.0f},
    {1.0f, 1.0f, -1.0f},
    {-1.0f, 1.0f, -1.0f}},
    {{1.0f, 1.0f, 1.0f},
    {-1.0f, 1.0f, -1.0f},
    {-1.0f, 1.0f, 1.0f}},
    {{1.0f, 1.0f, 1.0f},
    {-1.0f, 1.0f, 1.0f},
    {1.0f, -1.0f, 1.0f}}
};

static dvec3 dungeon_point_scaling(dvec3 point,
int scaling_x, int scaling_y, int scaling_z)
{
    dvec3 res = (dvec3){point.x, point.y, point.z};

    if (res.x > _dungeons.cur_origin.x)
        res.x += scaling_x;
    if (res.y > _dungeons.cur_origin.y)
        res.y += scaling_y;
    if (res.z > _dungeons.cur_origin.z)
        res.z += scaling_z;
    return res;
}

static void dungeon_insert_in_world(arr_dvec3_t *rooms, int nb_rooms)
{
    world_insert_start();
    for (int i = 0; i < nb_rooms; i++)
        world_insert_arr_dvec3(rooms[i], MATERIAL_GRASS, 0);
    world_insert_end(0);
}

static arr_dvec3_t dungeons_gen_room(void)
{
    arr_dvec3_t room = arr_dvec3_create(12 * 3);

    dungeons_set_next_origin();
    for (int i = 0; i < 12; i++) {
        room.dvec3[i * 3 + 1] =
        dungeon_point_scaling(g_vertex_buffer_data[i][0], 5, 2, 3);
        room.dvec3[i * 3] =
        dungeon_point_scaling(g_vertex_buffer_data[i][1], 5, 2, 3);
        room.dvec3[i * 3 + 2] =
        dungeon_point_scaling(g_vertex_buffer_data[i][2], 5, 2, 3);
    }
    return room;
}

void dungeons_gen_all(demo_t *demo, size_t rooms_limit)
{
    arr_dvec3_t *rooms;
    int generated_rooms = get_random_int(1, rooms_limit);

    (void)demo;
    printf("generated rooms : %d\n", generated_rooms);
    rooms = (arr_dvec3_t*)malloc_safe(sizeof(arr_dvec3_t) *
    generated_rooms);
    for (int i = 0; i < generated_rooms; i++)
        rooms[i] = dungeons_gen_room();
    dungeon_insert_in_world(rooms, generated_rooms);
    for (int i = 0; i < generated_rooms; i++)
        arr_dvec3_destroy(rooms[i]);
    free(rooms);
    return;
}
