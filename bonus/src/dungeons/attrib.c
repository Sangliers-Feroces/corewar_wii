/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** dungeons_attrib
*/

#include "headers.h"

void dungeons_set_next_origin(void)
{
    int orientation = get_random_int(0, 4);

    printf("%d\n", orientation);
    switch(orientation) {
    case DUNGEONS_NEXT_POS_NORTH:
        printf("NORHT\n");
        _dungeons.cur_origin.z += 2;
        break;
    case DUNGEONS_NEXT_POS_EAST:
        printf("EAST\n");
        _dungeons.cur_origin.x += 2;
        break;
    case DUNGEONS_NEXT_POS_SOUTH:
        printf("SOUTH\n");
        _dungeons.cur_origin.z -= 2;
        break;
    case DUNGEONS_NEXT_POS_WEST:
        printf("WEST\n");
        _dungeons.cur_origin.x -= 2;
        break;
    default:
        break;
    };
}
