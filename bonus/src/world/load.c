/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

/*static entity3* load_global_ents(int *has_created)
{
    char *path = map_get_path("ents");
    file_read_t file = file_read_create(path);
    entity3 *res;

    free(path);
    if (file.data == NULL) {
        *has_created = 1;
        return world_create_default_ents();
    }
    res = file_read_entity3(&file, NULL);
    file_read_flush(&file);
    *has_created = 0;
    return res;
}*/

/*static void ensure_path(void)
{
    if (_demo->world.map_path != NULL)
        return;
    world_load_meta_map();
    world_ensure_current_map_folder();
}*/

static void resolve_refs(void)
{
    _demo->world.player =
    entity3_seek_tag(_demo->world.ents, ENTITY3_TAG_PLAYER);
    _demo->world.camera =
    entity3_seek_tag(_demo->world.ents, ENTITY3_TAG_CAMERA);
    _demo->world.skybox =
    entity3_seek_tag(_demo->world.ents, ENTITY3_TAG_SKYBOX);
}

void world_load_map(void)
{
    int do_respawn = 1;

    /*if (_demo->world.map_path != NULL)
        return;
    ensure_path();
    invent_load();
    quest_load();*/
    _demo->world.tree = octree_create(NULL);
    _demo->world.light_dir =
    dvec3_normalize(dvec3_add(dvec3_init(-1.0, -1.0, -1.0),
    dvec3_init(0.0, 0.0, 0.2)));
    _demo->world.ents = world_create_default_ents();
    resolve_refs();
    if (do_respawn)
        player_respawn(_demo->world.player);
    //player_update_weapon();
    vec_msg_entry_flush(&_demo->buf.msgs);
}
