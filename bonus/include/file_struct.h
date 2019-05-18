/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#pragma once

typedef struct {
    size_t size;
    size_t allocated;
    void *data;
} file_write_t;

typedef struct {
    size_t i;
    size_t size;
    void *data;
} file_read_t;

typedef enum {
    FILE_DATA_NULL,
    FILE_DATA_HERE
} file_data_ref_t;
