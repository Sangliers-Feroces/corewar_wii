/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

static size_t align_up(size_t addr, size_t align)
{
    size_t extra = addr % align;

    if (extra == 0)
        return addr;
    else
        return addr + align - extra;
}

static void write_header(texture2f *texture, char *data, size_t size,
size_t pitch)
{
    data[0x00] = 'B';
    data[0x01] = 'M';
    *((uint32_t*)(data + 0x02)) = size;
    *((uint32_t*)(data + 0x0A)) = 60;
    *((uint32_t*)(data + 0x0E)) = 40;
    *((uint32_t*)(data + 0x12)) = texture->w;
    *((uint32_t*)(data + 0x16)) = texture->h;
    *((uint16_t*)(data + 0x1A)) = 1;
    *((uint16_t*)(data + 0x1C)) = 24;
    *((uint32_t*)(data + 0x1E)) = 0;
    *((uint32_t*)(data + 0x22)) = pitch;
    *((uint32_t*)(data + 0x26)) = 0;
    *((uint32_t*)(data + 0x2A)) = 0;
    *((uint32_t*)(data + 0x2E)) = 0;
    *((uint32_t*)(data + 0x32)) = 0;
}

static void write_data(texture2f *texture, char *dst, size_t pitch,
float aperture)
{
    uint32_t r;
    uint32_t g;
    uint32_t b;
    size_t i;

    for (size_t i_a = 0; i_a < (size_t)texture->h; i_a++) {
        i = texture->h - 1 - i_a;
        for (size_t j = 0; j < (size_t)texture->w; j++) {
            r = MIN((uint32_t)texture->pixel[i_a * texture->w + j].x
            / aperture * 255.0f, 0xFF);
            g = MIN((uint32_t)texture->pixel[i_a * texture->w + j].y
            / aperture * 255.0f, 0xFF);
            b = MIN((uint32_t)texture->pixel[i_a * texture->w + j].z
            / aperture * 255.0f, 0xFF);
            dst[i * pitch + j * 3] = b;
            dst[i * pitch + j * 3 + 1] = g;
            dst[i * pitch + j * 3 + 2] = r;
        }
    }
}

static void write_file(const char *data, size_t size, void *ptr)
{
    char path[512];
    FILE *file;

    sprintf(path, "lightmaps/%p.bmp", ptr);
    file = fopen(path, "wb+");
    if (file == NULL)
        return;
    fwrite(data, sizeof(char), size, file);
    fclose(file);
}

void texture2f_write(texture2f *texture, float aperture)
{
    size_t pitch = align_up(texture->w * 3, 4);
    size_t size = 60 + pitch * texture->h;
    char *data = (char*)malloc_safe(size);

    memset(data, 0, size);
    write_header(texture, data, size, pitch);
    write_data(texture, &data[60], pitch, aperture);
    write_file(data, size, texture);
    free(data);
}
