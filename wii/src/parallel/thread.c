/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** because CPUs and GPUs are slowly merging
*/

#include "headers.h"

static size_t get_thread_count(void)
{
    char *data = get_file_data("/proc/cpuinfo");
    size_t res = 0;
    char prev = '\0';

    if (data == NULL)
        return 0;
    for (size_t i = 0; data[i] != '\0'; i++) {
        if ((data[i] == '\n') && (prev == '\n'))
            res++;
        prev = data[i];
    }
    free(data);
    return res;
}

/*static void* thread_loop(void *data)
{
    thread_bus *bus = (thread_bus*)data;

    bus->task = THREAD_TASK_IDLE;
    bus->is_busy = 0;
    while (bus->task != THREAD_TASK_KILL) {
        if (bus->task != THREAD_TASK_IDLE) {
            bus->is_busy = 1;
            thread_do_task(bus);
            bus->task = THREAD_TASK_IDLE;
            bus->is_busy = 0;
        }
        usleep(1);
    }
    bus->is_busy = 0;
    return NULL;
}*/

void thread_init(void)
{
    _thread.count = MAX(get_thread_count(), 1);
    _thread.count = 1;
    _thread.bus = (thread_bus*)malloc_safe(
    _thread.count * sizeof(thread_bus));
    /*for (size_t i = 0; i < _thread.count; i++)
        pthread_create(&_thread.bus[i].id, NULL, &thread_loop,
        &_thread.bus[i]);*/
}

void thread_quit(void)
{
    thread_wait();
    thread_send_each(THREAD_TASK_KILL, NULL, 0);
    thread_wait();
    /*for (size_t i = 0; i < _thread.count; i++)
        pthread_join(_thread.bus[i].id, NULL);*/
    free(_thread.bus);
}

void thread_wait(void)
{
    while (!thread_is_complete())
        usleep(1);
}
