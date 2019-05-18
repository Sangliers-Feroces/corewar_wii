/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void set_buffer_attrib(void)
{
    /*glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
    sizeof(chunk_vertex_t), BUFFER_OFFSET(0));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
    sizeof(chunk_vertex_t), BUFFER_OFFSET(offsetof(chunk_vertex_t, normal)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
    sizeof(chunk_vertex_t), BUFFER_OFFSET(offsetof(chunk_vertex_t, uv_albedo)));
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE,
    sizeof(chunk_vertex_t), BUFFER_OFFSET(offsetof(chunk_vertex_t,
    uv_lightmap)));*/
}

chunk_lod_t chunk_lod_create(size_t lod)
{
    chunk_lod_t res;

    res.lod = lod;
    res.geom = vec_rtx_triangle_create();
    res.vertex_count = 0;
    /*glGenVertexArrays(1, &res.vertex_array);
    glBindVertexArray(res.vertex_array);
    glGenBuffers(1, &res.vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, res.vertex_buffer);*/
    set_buffer_attrib();
    res.do_reupload_buf = 1;
    return res;
}

void chunk_lod_destroy(chunk_lod_t *lod)
{
    vec_rtx_triangle_destroy(lod->geom);
    /*if (lod->vertex_array != 0)
        glDeleteVertexArrays(1, &lod->vertex_array);
    if (lod->vertex_buffer != 0)
        glDeleteBuffers(1, &lod->vertex_buffer);*/
}
