/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static void create_folder(const char *path)
{
    if (mkdir(path, 0755) < 0) {
        printf("Error: can't create '%s' folder.\n", path);
        exit(84);
    }
}

static void create_meta(void)
{
    const char *path = "maps/meta";
    file_write_t file_w;

    file_w = file_write_create();
    file_write_string(&file_w, "maps/world");
    file_write_flush(&file_w, path);
}

void ensure_folder_maps(void)
{
    FILE *folder = fopen("maps", "rb");

    if (folder == NULL)
        create_folder("maps");
    else
        fclose(folder);
}

void world_load_meta_map(void)
{
    const char *path = "maps/meta";
    file_read_t file;

    file = file_read_create(path);
    if (file.data == NULL) {
        create_meta();
        file = file_read_create(path);
    }
    if (file.data == NULL) {
        ensure_folder_maps();
        create_meta();
        file = file_read_create(path);
    }
    if (file.data == NULL) {
        printf("Error: can't access to maps/meta.\n");
        exit(84);
    }
    _demo->world.map_path = file_read_string(&file);
    file_read_flush(&file);
}

void world_ensure_current_map_folder(void)
{
    FILE *folder = fopen("maps", "rb");
    char *map_folder_path;

    map_folder_path = _demo->world.map_path;
    folder = fopen(map_folder_path, "rb");
    if (folder == NULL)
        create_folder(map_folder_path);
    else
        fclose(folder);
}
