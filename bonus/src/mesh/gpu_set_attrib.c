/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void mesh_set_vertex_attrib(gluint vertex_array, gluint vertex_buffer)
{
    (void)vertex_array;
    (void)vertex_buffer;
    /*glBindVertexArray(vertex_array);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
    sizeof(vertex_t), BUFFER_OFFSET(0));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
    sizeof(vertex_t), BUFFER_OFFSET(offsetof(vertex_t, normal)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
    sizeof(vertex_t), BUFFER_OFFSET(offsetof(vertex_t, uv)));*/
}

/*static void ext_set_attrib(gluint vertex_ext_buffer)
{
    (void)vertex_ext_buffer;
    size_t stride = sizeof(vertex_t) + sizeof(vertex_ext_t);

    glBindBuffer(GL_ARRAY_BUFFER, vertex_ext_buffer);
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE,
    stride, BUFFER_OFFSET(sizeof(vertex_t)));
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 1, GL_FLOAT, GL_FALSE,
    stride, BUFFER_OFFSET(sizeof(vertex_t) + offsetof(vertex_ext_t, uv_ext)));
    glEnableVertexAttribArray(5);
    glVertexAttribPointer(5, 1, GL_FLOAT, GL_FALSE,
    stride, BUFFER_OFFSET(sizeof(vertex_t) + offsetof(vertex_ext_t, tex_a)));
    glEnableVertexAttribArray(6);
    glVertexAttribPointer(6, 1, GL_FLOAT, GL_FALSE,
    stride, BUFFER_OFFSET(sizeof(vertex_t) + offsetof(vertex_ext_t, tex_b)));
}*/

void mesh_ext_set_vertex_attrib(gluint vertex_array,
gluint vertex_buffer, gluint vertex_ext_buffer)
{
    (void)vertex_array;
    (void)vertex_buffer;
    (void)vertex_ext_buffer;
    /*size_t stride = sizeof(vertex_t) + sizeof(vertex_ext_t);

    glBindVertexArray(vertex_array);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
    stride, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
    stride, BUFFER_OFFSET(offsetof(vertex_t, normal)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
    stride, BUFFER_OFFSET(offsetof(vertex_t, uv)));
    ext_set_attrib(vertex_ext_buffer);*/
}
