/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void file_write_int(file_write_t *file, int value)
{
    file_write(file, &value, sizeof(int));
}

void file_write_string(file_write_t *file, const char *value)
{
    size_t size = strlen_slow(value) + 1;

    file_write_actual(file, &size, sizeof(size_t));
    file_write_actual(file, value, size);
}

void file_write_8(file_write_t *file, uint8_t value)
{
    file_write(file, &value, sizeof(uint8_t));
}

void file_write_16(file_write_t *file, uint16_t value)
{
    file_write(file, &value, sizeof(uint16_t));
}

void file_write_32(file_write_t *file, uint32_t value)
{
    file_write(file, &value, sizeof(uint32_t));
}
