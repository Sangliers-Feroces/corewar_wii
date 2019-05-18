/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** headers
*/

#pragma once

void thread_init(void);
void thread_quit(void);
void thread_wait(void);

void thread_send(size_t ndx, thread_task task, uint32_t *data, size_t size);
void thread_send_each(thread_task task, uint32_t *data, size_t size);
void thread_do_task(thread_bus *bus);

int thread_is_complete(void);
float thread_get_progress(void);
void thread_abort_task(void);
