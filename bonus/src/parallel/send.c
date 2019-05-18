/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** because CPUs and GPUs are slowly merging
*/

#include "headers.h"

void thread_send(size_t ndx, thread_task task, uint32_t *data, size_t size)
{
    for (size_t i = 0; i < MIN(size, THREAD_DATA_SIZE); i++)
        _thread.bus[ndx].data[i] = data[i];
    _thread.bus[ndx].task = task;
    _thread.bus[ndx].is_busy = 1;
}

void thread_send_each(thread_task task, uint32_t *data, size_t size)
{
    for (size_t i = 0; i < _thread.count; i++)
        thread_send(i, task, data, size);
}

void thread_do_task(thread_bus *bus)
{
    switch (bus->task) {
    case THREAD_TASK_RAY_TRACING:
        octree_light_rtx_thread(bus, (void*)bus->data[0], bus->data[1]);
        break;
    default:
        break;
    }
}
