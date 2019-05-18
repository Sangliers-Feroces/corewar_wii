/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static void create_skybox(entity3 *root)
{
    entity3 *sky = entity3_create(root);

    //entity3_set_render(sky, 0, mesh_full_ref_bank_init(MESH_BANK_SKYBOX),
    //MATERIAL_SKYBOX);
    entity3_set_tag(sky, ENTITY3_TAG_SKYBOX);
}

static void set_sword(entity3 *cam)
{
    entity3 *sword;

    sword = entity3_create(cam);
    sword->trans.pos = dvec3_init(0.7, -0.7, 0.7);
    sword->trans.scale.x = -1.0;
    sword->trans.is_static = 0;
    entity3_trans_update(sword);
    sword = entity3_create(sword);
    sword->trans.is_static = 0;
    entity3_add_trigger(sword, trigger_create(dvec3_init(-0.5, 0.0, 0.0),
    dvec3_init(0.5, 3.0, 1.0), TRIGGER_ON_HIT_SWORD));
    entity3_set_tag(sword, ENTITY3_TAG_SWORD);
    entity3_trans_update(sword);
}

static void player_set_trans(entity3 *player)
{
    player->trans.is_static = 0;
    //player->trans.is_physics = 1;
    //player->trans.is_collision = 1;
    player->trans.slide_threshold = 0.8;
    player->trans.pos = dvec3_init(0.0, 0.0, 0.0);
    entity3_add_trigger(player, trigger_create(dvec3_init(-0.5, 0.0, -0.5),
    dvec3_init(0.5, 1.75, 0.5), TRIGGER_ON_HIT_PLAYER));
    entity3_trans_update(player);
}

entity3* world_create_default_ents(void)
{
    entity3 *res = entity3_create(NULL);
    entity3 *player;
    entity3 *cam;

    player = entity3_create(res);
    entity3_set_tag(player, ENTITY3_TAG_PLAYER);
    player_set_trans(player);
    cam = entity3_create(player);
    entity3_set_tag(cam, ENTITY3_TAG_CAMERA);
    cam->trans.is_static = 0;
    cam->trans.pos = dvec3_init(0.0, 1.75, 0.0);
    entity3_trans_update(cam);
    set_sword(cam);
    create_skybox(res);
    //invent_add_item(ITEM_SWORD_1);
    _demo->world.snake = entity3_create(res);
    entity3_set_tag(_demo->world.snake, ENTITY3_TAG_SNAKE);
    for (size_t i = 0; i < VM_H; i++)
        for (size_t j = 0; j < VM_W; j++) {
            entity3 *part = entity3_create(_demo->world.snake);
            part->trans.pos = dvec3_init(j * 2.0, 0.0, -(ssize_t)i * 2.0);
            entity3_set_render(part, 0, mesh_full_ref_bank_init(MESH_BANK_BOX), MATERIAL_GRASS);
            entity3_trans_update(part);
        }
    return res;
}
