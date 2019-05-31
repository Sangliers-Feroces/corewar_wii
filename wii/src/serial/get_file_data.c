/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** data retrieval
*/

#include "headers.h"

char* get_file_data(const char *path)
{
    FILE *file;
    char *data;
    size_t size = 65536;
    size_t got;

    file = fopen(path, "rb");
    if (file == NULL)
        return NULL;
    do {
        data = (char*)malloc_safe((size + 1) * sizeof(char));
        got = fread(data, 1, size, file);
        if (got < size)
            break;
        free(data);
        size *= 2;
        rewind(file);
    } while (1);
    fclose(file);
    data[got] = '\0';
    return data;
}
