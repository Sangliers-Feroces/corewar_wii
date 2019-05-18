/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

file_read_t file_read_create(const char *path)
{
    FILE *f = fopen(path, "rb");
    file_read_t res;

    res.i = 0;
    res.size = 0;
    res.data = NULL;
    if (f == NULL)
        return res;
    fseek(f, 0, SEEK_END);
    res.size = ftell(f);
    rewind(f);
    res.data = (void*)malloc_safe(res.size);
    fread(res.data, 1, res.size, f);
    fclose(f);
    return res;
}

void file_read_actual(file_read_t *file, void *dst, size_t size)
{
    if (file->i + size > file->size) {
        printf("Corrupted save: file overflow.\n");
        exit(84);
    }
    memcpy(dst, file->data + file->i, size);
    file->i += size;
}

void file_read(file_read_t *file, void *dst, size_t size)
{
    size_t got;

    file_read_actual(file, &got, sizeof(ssize_t));
    if (got != size) {
        printf("Corrupted save: chain destroyed here.\n");
        exit(84);
    }
    file_read_actual(file, dst, size);
}

void file_read_flush(file_read_t *file)
{
    if (file->i != file->size) {
        printf("Corrupted save: file partly discarded.\n");
        exit(84);
    }
    free(file->data);
}

file_data_ref_t file_read_data_ref(file_read_t *file)
{
    file_data_ref_t res;

    file_read(file, &res, sizeof(file_data_ref_t));
    return res;
}
