/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

void gl_set_texture_parameters(gluint texture)
{
    (void)texture;
    /*glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);*/
}

static int allocate_texture(ivec2 *size)
{
    while (size->y > 0) {
        /*glTexImage2D(GL_PROXY_TEXTURE_2D, 0, GL_RGBA32F, size->x, size->y,
        0, GL_RGBA, GL_FLOAT, NULL);
        if (glGetError() == GL_NO_ERROR)
            break;*/
        size->y /= 2;
    }
    size->y /= 4;
    size->x /= 2;
    size->x = MIN(size->x, 16);
    size->y = MIN(size->y, 16);
    /*glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, size->x, size->y,
    0, GL_RGBA, GL_FLOAT, NULL);*/
    if (size->y == 0) {
        printf("Can't create texture cluster. (no suitable size found)\n");
        return 0;
    }
    return 1;
}

static texture2f* texture2f_create_cluster(int32_t w, int32_t h)
{
    texture2f *res = (texture2f*)malloc_safe(sizeof(texture2f));
    ivec2 size = {w, h};

    //glGenTextures(1, &res->id);
    if (res->id == 0) {
        printf("Can't create texture cluster. (GL returns 0)\n");
        return NULL;
    }
    gl_set_texture_parameters(res->id);
    if (!allocate_texture(&size))
        return NULL;
    //glBindTexture(GL_TEXTURE_2D, 0);
    res->size = (vec2){(float)size.x, (float)size.y};
    res->w = size.x;
    res->h = size.y;
    res->max_ndx = res->w * res->h;
    res->pixel = (vec4*)malloc_safe(size.x * size.y * sizeof(vec4));
    return res;
}

texture_cluster texture_cluster_create(void)
{
    texture_cluster res = {NULL, 0, 1.0f, {0, 0, NULL}};
    glint max = 0;

    //glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max);
    res.base = texture2f_create_cluster(max, max);
    return res;
}

int texture_cluster_add_row(texture_cluster *cluster, int32_t power)
{
    size_t cur = cluster->rows.count++;
    texture_cluster_row *new_row;

    if ((cluster->to_fill_y + (1 << power)) > cluster->base->h)
        return 0;
    if (cluster->rows.count > cluster->rows.allocated) {
        cluster->rows.allocated += TEXTURE_CLUSTER_ROW_ALLOC_STEP;
        new_row = (texture_cluster_row*)malloc_safe(
        cluster->rows.allocated * sizeof(texture_cluster_row));
        for (size_t i = 0; i < cur; i++)
            new_row[i] = cluster->rows.cluster_row[i];
        free(cluster->rows.cluster_row);
        cluster->rows.cluster_row = new_row;
    }
    cluster->rows.cluster_row[cur] = texture_cluster_row_init(cluster, power);
    vec_texture_cluster_row_alloc_init(
    &cluster->rows.cluster_row[cur].row_allocs, cluster->base->w);
    cluster->to_fill_y += (1 << power) + 2;
    return 1;
}
