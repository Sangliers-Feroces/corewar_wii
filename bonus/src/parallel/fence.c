/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** because CPUs and GPUs are slowly merging
*/

#include "headers.h"

int thread_is_complete(void)
{
    for (size_t i = 0; i < _thread.count; i++)
        if (_thread.bus[i].is_busy)
            return (0);
    return (1);
}

float thread_get_progress(void)
{
    size_t busy_count = 0;
    float progress = 0.0f;

    for (size_t i = 0; i < _thread.count; i++)
        if (_thread.bus[i].is_busy) {
            progress += _thread.bus[i].progress;
            busy_count++;
        }
    if (busy_count == 0)
        return (0.0f);
    return (progress / (float)busy_count);
}

void thread_abort_task(void)
{
    thread_send_each(THREAD_TASK_ABORT, NULL, 0);
}
