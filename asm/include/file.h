/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#pragma once

file_write_t file_write_create(void);
void file_write_actual(file_write_t *file, const void *src, size_t size);
void file_write(file_write_t *file, const void *src, size_t size);
void file_write_flush(file_write_t *file, const char *path);
void file_write_data_ref(file_write_t *file, file_data_ref_t ref_type);

void file_write_int(file_write_t *file, int value);
void file_write_string(file_write_t *file, const char *value);
void file_write_size_t(file_write_t *file, size_t value);
void file_write_8(file_write_t *file, uint8_t value);
void file_write_16(file_write_t *file, uint16_t value);
void file_write_32(file_write_t *file, uint32_t value);

file_read_t file_read_create(const char *path);
void file_read_actual(file_read_t *file, void *dst, size_t size);
void file_read(file_read_t *file, void *dst, size_t size);
void file_read_flush(file_read_t *file);
file_data_ref_t file_read_data_ref(file_read_t *file);

int file_read_int(file_read_t *file);
char* file_read_string(file_read_t *file);
size_t file_read_size_t(file_read_t *file);



