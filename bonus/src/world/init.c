/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static void unload_global_ents(void)
{
    char *path = map_get_path("ents");
    file_write_t file = file_write_create();

    file_write_entity3(&file, _demo->world.ents);
    file_write_flush(&file, path);
    free(path);
    entity3_destroy(_demo->world.ents);
}

void world_unload_map(void)
{
    if (_demo->world.map_path == NULL)
        return;
    printf("Saving world at '%s'.. Please wait.\n", _demo->world.map_path);
    unload_global_ents();
    while (_demo->world.chunk_count > 0)
        chunk_destroy(_demo->world.chunk[0]);
    octree_destroy(&_demo->world.tree);
    vec_trigger_destroy(&_demo->world.triggers);
    free(_demo->world.map_path);
    _demo->world.map_path = NULL;
    invent_store();
    quest_store();
    printf("Done.\n");
}

void world_init(demo_t *demo)
{
    demo->world.map_path = NULL;
    demo->world.chunk_count = 0;
    demo->world.chunk_allocated = 0;
    demo->world.chunk = NULL;
    demo->world.triggers = vec_trigger_init();
    demo->world.chunk2d_area = (srect){{0, 0}, {1, 1}};
    demo->world.chunk2d = (chunk_t**)malloc_safe(sizeof(chunk_t*));
    demo->world.chunk2d[0] = NULL;
    demo->world.tree = NULL;
    entity3_update_tag_init();
    world_trigger_init();
}

void world_quit(demo_t *demo)
{
    world_unload_map();
    free(demo->world.chunk);
    free(demo->world.chunk2d);
    free(demo->world.map_path);
}
