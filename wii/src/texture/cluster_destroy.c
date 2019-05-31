/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

/* the texture is subdivided into rows of height 2^n */

static void free_vec_texture_cluster_row(vec_texture_cluster_row *vec)
{
    for (size_t i = 0; i < vec->count; i++) {
        for (size_t j = 0; j < vec->cluster_row[i].row_allocs.count; j++)
            free(vec->cluster_row[i].row_allocs.cluster_row[j]);
        free(vec->cluster_row[i].row_allocs.cluster_row);
    }
    free(vec->cluster_row);
}

void texture_cluster_destroy(texture_cluster cluster)
{
    texture2f_destroy(cluster.base);
    free_vec_texture_cluster_row(&cluster.rows);
}
