/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

file_write_t file_write_create(void)
{
    file_write_t res;

    res.size = 0;
    res.allocated = 0;
    res.data = NULL;
    return res;
}

void file_write_actual(file_write_t *file, const void *src, size_t size)
{
    size_t cur = file->size + size;

    if (cur > file->allocated) {
        file->allocated += MAX(1ULL << 16ULL, size);
        file->data = (void*)realloc(file->data, file->allocated);
        memset(file->data + file->size, 0, file->allocated - file->size);
    }
    memcpy(file->data + file->size, src, size);
    file->size = cur;
}

void file_write(file_write_t *file, const void *src, size_t size)
{
    file_write_actual(file, &size, sizeof(size_t));
    file_write_actual(file, src, size);
}

void file_write_flush(file_write_t *file, const char *path)
{
    FILE *f;

    if (path == NULL) {
        free(file->data);
        return;
    }
    f = fopen(path, "wb+");
    if (f == NULL) {
        free(file->data);
        return;
    }
    fwrite(file->data, 1, file->size, f);
    fclose(f);
    free(file->data);
}

void file_write_data_ref(file_write_t *file, file_data_ref_t ref_type)
{
    file_write(file, &ref_type, sizeof(file_data_ref_t));
}
