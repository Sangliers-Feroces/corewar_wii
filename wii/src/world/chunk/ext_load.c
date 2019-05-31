/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static char *get_path(ssize2 pos)
{
    char file[64];

    sprintf(file, "%.16zx%.16zxx", pos.x, pos.y);
    return map_get_path(file);
}

void chunk_load_ext(chunk_t *chunk)
{
    file_read_t file;
    char *path;

    if (chunk->ents_ext != NULL)
        return;
    path = get_path(chunk->pos);
    file = file_read_create(path);
    free(path);
    if (file.data == NULL)
        chunk->ents_ext = entity3_create_pos(NULL, chunk->ents->trans.pos);
    else {
        chunk->ents_ext = file_read_entity3(&file, NULL);
        file_read_flush(&file);
    }
}

void chunk_store_ext(chunk_t *chunk)
{
    file_write_t file;
    char *path;

    if (chunk->ents_ext == NULL)
        return;
    file = file_write_create();
    file_write_entity3(&file, chunk->ents_ext);
    entity3_destroy(chunk->ents_ext);
    chunk->ents_ext = NULL;
    path = get_path(chunk->pos);
    file_write_flush(&file, path);
    free(path);
}

int chunk_refresh_ext(chunk_t *chunk, ssize2 cam)
{
    ssize_t dist = ssize2_dist_sq_man(chunk->pos, cam);
    int state = dist <= 1;

    if ((chunk->ents_ext != NULL) != state) {
        if (chunk->ents_ext == NULL)
            chunk_load_ext(chunk);
        else
            chunk_store_ext(chunk);
        return 1;
    }
    return 0;
}

entity3* chunk_add_entity_ext(chunk_t *chunk)
{
    if (chunk->ents_ext == NULL)
        chunk_load_ext(chunk);
    return entity3_create(chunk->ents_ext);
}
