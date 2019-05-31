/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static void world_chunk2d_realloc_x_neg(demo_t *demo, size_t offset)
{
    size_t new_w = demo->world.chunk2d_area.s.x + offset;
    chunk_t** new_chunk2d = (chunk_t**)malloc_safe(
    new_w * demo->world.chunk2d_area.s.y * sizeof(chunk_t**));

    for (ssize_t i = 0; i < demo->world.chunk2d_area.s.y; i++) {
        for (size_t j = 0; j < offset; j++)
            new_chunk2d[i * new_w + j] = NULL;
        for (ssize_t j = 0; j < demo->world.chunk2d_area.s.x ; j++)
            new_chunk2d[i * new_w + offset + j] =
            demo->world.chunk2d[i * demo->world.chunk2d_area.s.x + j];
    }
    demo->world.chunk2d_area.p.x -= offset;
    demo->world.chunk2d_area.s.x = new_w;
    free(demo->world.chunk2d);
    demo->world.chunk2d = new_chunk2d;
}

static void world_chunk2d_realloc_x_pos(demo_t *demo, size_t offset)
{
    size_t new_w = demo->world.chunk2d_area.s.x + offset;
    chunk_t** new_chunk2d = (chunk_t**)malloc_safe(
    new_w * demo->world.chunk2d_area.s.y * sizeof(chunk_t**));

    for (ssize_t i = 0; i < demo->world.chunk2d_area.s.y; i++) {
        for (ssize_t j = 0; j < demo->world.chunk2d_area.s.x ; j++)
            new_chunk2d[i * new_w + j] =
            demo->world.chunk2d[i * demo->world.chunk2d_area.s.x + j];
        for (size_t j = 0; j < offset; j++)
            new_chunk2d[i * new_w + demo->world.chunk2d_area.s.x + j] = NULL;
    }
    demo->world.chunk2d_area.s.x = new_w;
    free(demo->world.chunk2d);
    demo->world.chunk2d = new_chunk2d;
}

static void world_chunk2d_realloc_y_neg(demo_t *demo, size_t offset)
{
    size_t new_w = demo->world.chunk2d_area.s.x;
    size_t new_h = demo->world.chunk2d_area.s.y + offset;
    chunk_t** new_chunk2d = (chunk_t**)malloc_safe(
    new_w * new_h * sizeof(chunk_t**));

    for (size_t i = 0; i < offset; i++)
        for (ssize_t j = 0; j < demo->world.chunk2d_area.s.x; j++)
            new_chunk2d[i * new_w + j] = NULL;
    for (ssize_t i = 0; i < demo->world.chunk2d_area.s.y; i++)
        for (ssize_t j = 0; j < demo->world.chunk2d_area.s.x; j++)
            new_chunk2d[(offset + i) * new_w + j] =
            demo->world.chunk2d[i * demo->world.chunk2d_area.s.x + j];
    demo->world.chunk2d_area.p.y -= offset;
    demo->world.chunk2d_area.s.y = new_h;
    free(demo->world.chunk2d);
    demo->world.chunk2d = new_chunk2d;
}

static void world_chunk2d_realloc_y_pos(demo_t *demo, size_t offset)
{
    size_t new_w = demo->world.chunk2d_area.s.x;
    size_t new_h = demo->world.chunk2d_area.s.y + offset;
    chunk_t** new_chunk2d = (chunk_t**)malloc_safe(
    new_w * new_h * sizeof(chunk_t**));

    for (ssize_t i = 0; i < demo->world.chunk2d_area.s.y; i++)
        for (ssize_t j = 0; j < demo->world.chunk2d_area.s.x; j++)
            new_chunk2d[i * new_w + j] =
            demo->world.chunk2d[i * demo->world.chunk2d_area.s.x + j];
    for (size_t i = 0; i < offset; i++)
        for (ssize_t j = 0; j < demo->world.chunk2d_area.s.x; j++)
            new_chunk2d[(demo->world.chunk2d_area.s.y + i) * new_w + j] = NULL;
    demo->world.chunk2d_area.s.y = new_h;
    free(demo->world.chunk2d);
    demo->world.chunk2d = new_chunk2d;
}

void world_chunk2d_insert(chunk_t *chunk)
{
    ssize_t border;

    border = _demo->world.chunk2d_area.p.x;
    if (chunk->pos.x < border)
        world_chunk2d_realloc_x_neg(_demo, border - chunk->pos.x);
    border = _demo->world.chunk2d_area.p.x + _demo->world.chunk2d_area.s.x;
    if (chunk->pos.x >= border)
        world_chunk2d_realloc_x_pos(_demo, chunk->pos.x - border + 1);
    border = _demo->world.chunk2d_area.p.y;
    if (chunk->pos.y < border)
        world_chunk2d_realloc_y_neg(_demo, border - chunk->pos.y);
    border = _demo->world.chunk2d_area.p.y + _demo->world.chunk2d_area.s.y;
    if (chunk->pos.y >= border)
        world_chunk2d_realloc_y_pos(_demo, chunk->pos.y - border + 1);
    if (*world_chunk2d_get(chunk->pos)) {
        printf("Warning: chunk overwritten at %zd, %zd.\n",
        chunk->pos.x, chunk->pos.y);
        exit(84);
    }
    *world_chunk2d_get(chunk->pos) = chunk;
}
