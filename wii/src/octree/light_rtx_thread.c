/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** optiiiiiii rtx
*/

#include "headers.h"

void octree_light_rtx_thread(thread_bus *bus, octree *tree, size_t density)
{
    (void)bus;
    (void)tree;
    (void)density;
}

void octree_light_rtx_noblock(octree *tree, size_t density)
{
    octree_reset_lumels(tree);
    thread_send_each(THREAD_TASK_RAY_TRACING,
    (uint32_t[]){(uint32_t)tree, density / _thread.count}, 2);
}
