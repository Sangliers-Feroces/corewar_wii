/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

ssize2 file_read_ssize2(file_read_t *file)
{
    ssize2 res;

    file_read(file, &res, sizeof(ssize2));
    return res;
}

chunk_border_t file_read_chunk_border(file_read_t *file)
{
    chunk_border_t res;

    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 2; j++)
            for (size_t k = 0; k < CHUNK_GEN_ITER; k++)
                res.data[i][j][k] = file_read_arr_dvec3(file);
    return res;
}

entity3* entity3_seek_tag(entity3 *ent, entity3_tag_t tag)
{
    entity3 *got;

    if (ent->tag == tag)
        return ent;
    for (size_t i = 0; i < ent->sub.count; i++) {
        got = entity3_seek_tag(ent->sub.ent[i], tag);
        if (got != NULL)
            return got;
    }
    return NULL;
}

chunk_t* file_read_chunk(file_read_t *file)
{
    chunk_t *res = chunk_create_detached(file_read_ssize2(file));

    res->border = file_read_chunk_border(file);
    res->border_ter = file_read_chunk_border(file);
    res->terrain_base = file_read_arr2d_dvec3(file);
    res->enemy_count = file_read_size_t(file);
    res->enemy_count_max = file_read_size_t(file);
    entity3_destroy(res->ents);
    entity3_destroy(res->ents_global);
    res->ents = file_read_entity3(file, NULL);
    res->ents_global = file_read_entity3(file, NULL);
    res->terrain = entity3_seek_tag(res->ents, ENTITY3_TAG_TERRAIN);
    return res;
}
