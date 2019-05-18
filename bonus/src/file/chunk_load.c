/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

char* map_get_path(const char *file)
{
    char *dir = _demo->world.map_path;
    char *res = (char*)malloc_safe(strlen(dir) +
    strlen(file) + 2);
    size_t i = 0;

    for (size_t j = 0; dir[j] != '\0'; j++)
        res[i++] = dir[j];
    res[i++] = '/';
    for (size_t j = 0; file[j] != '\0'; j++)
        res[i++] = file[j];
    res[i++] = '\0';
    return res;
}

static char *get_path(ssize2 pos)
{
    char file[48];

    sprintf(file, "%.16zx%.16zx", pos.x, pos.y);
    return map_get_path(file);
}

int chunk_is_loaded(ssize2 pos)
{
    chunk_t **pexist;

    pexist = world_chunk2d_get(pos);
    if (pexist == NULL)
        return 0;
    if ((*pexist) == NULL)
        return 0;
    return 1;
}

int chunk_try_load(ssize2 pos, chunk_t **pres)
{
    char *path;
    file_read_t file;
    chunk_t *res;

    if (chunk_is_loaded(pos))
        return 1;
    path = get_path(pos);
    file = file_read_create(path);
    free(path);
    if (file.data == NULL)
        return 0;
    res = file_read_chunk(&file);
    if (pres != NULL)
        *pres = res;
    file_read_flush(&file);
    chunk_attach(res);
    return 1;
}

void chunk_save(chunk_t *chunk)
{
    char *path = get_path(chunk->pos);
    file_write_t file = file_write_create();

    file_write_chunk(&file, chunk);
    file_write_flush(&file, path);
    free(path);
}
