/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** vulkan ftw
*/

#include "headers.h"

/*static void gen_2d_texture_from_mem(gpu_serial_t serial)
{
    int32_t *buf;
    int w;
    int h;
    int rays = 500000;

    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &w);
    h = serial.size / w + 1;
    buf = malloc_safe(w * h * sizeof(int32_t));
    for (size_t i = 0; i < serial.size; i++)
        buf[i] = serial.data[i];
    buf[0] = time(NULL);
    buf[1] = rays / 2000;
    glTexImage2D(GL_TEXTURE_2D, 0, GL_R32I, w, h,
    0, GL_RED_INTEGER, GL_INT, buf);
    free(buf);
}

static void set_params_for_compute(gpu_serial_t serial, gluint mem)
{
    gen_2d_texture_from_mem(serial);
    glBindImageTexture(0, mem, 0, GL_FALSE, 0, GL_READ_ONLY, GL_R32I);
    glBindTexture(GL_TEXTURE_2D, _lightmaps.base->id);
    glBindImageTexture(1, _lightmaps.base->id, 0, GL_FALSE, 0, GL_READ_WRITE,
    GL_RGBA32F);
}

static void print_group_size(void)
{
    int workgroup_count[3];
    int workgroup_size[3];
    int workgroup_invocations;

    glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 0, &workgroup_count[0]);
    glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 1, &workgroup_count[1]);
    glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 2, &workgroup_count[2]);
    printf("Taille maximale des workgroups:\n\tx:%u\n\ty:%u\n\tz:%u\n",
    workgroup_count[0], workgroup_count[1], workgroup_count[2]);
    glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 0, &workgroup_size[0]);
    glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 1, &workgroup_size[1]);
    glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 2, &workgroup_size[2]);
    printf("Nombre maximal d'invocation locale:\n\tx:%u\n\ty:%u\n\tz:%u\n",
    workgroup_size[0], workgroup_size[1], workgroup_size[2]);
    glGetIntegerv (GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS,
    &workgroup_invocations);
    printf("Nombre maximum d'invocation de workgroups:\n\t%u\n",
    workgroup_invocations);
}

static void dispatch_work(void)
{
    glDispatchCompute(2000, 1, 1);
    glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
    glBindImageTexture(1, 0, 0, GL_FALSE, 0, GL_READ_WRITE, GL_RGBA32F);
    glBindTexture(GL_TEXTURE_2D, 0);
    glUseProgram(0);
}*/

void gpu_compute_lightmap(octree *tree, size_t rays)
{
    (void)tree;
    (void)rays;
    /*gluint shader = shader_load_compute(
    "src/gpu/shader/compute_lightmap.glsl");
    gluint mem;
    gpu_serial_t serial = octree_serialize(tree);

    (void)rays;
    print_group_size();
    glUseProgram(shader);
    glGenTextures(1, &mem);
    gl_set_texture_parameters(mem);
    set_params_for_compute(serial, mem);
    dispatch_work();
    glDeleteProgram(shader);
    glDeleteTextures(1, &mem);
    free(serial.data);
    texture2f_refresh_cpu(_lightmaps.base);
    glFinish();*/
}
