/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static const entity3_tag_update_desc_t desc[] = {
    {ENTITY3_TAG_PLAYER, &entity3_tag_update_player,
    sizeof(entity3_tag_player_data_t), &entity3_tag_init_player},
    {ENTITY3_TAG_ENEMY, &entity3_tag_update_enemy,
    sizeof(entity3_tag_enemy_data_t), &entity3_tag_init_enemy},
    {ENTITY3_TAG_NONE, NULL, 0, NULL}
};

void entity3_update_tag_init(void)
{
    for (size_t i = 0; i < ENTITY3_TAG_MAX; i++)
        _demo->world.tag[i] = (entity3_tag_meta_t){NULL, 0, NULL};
    for (size_t i = 0; desc[i].tag != ENTITY3_TAG_NONE; i++)
        _demo->world.tag[desc[i].tag] =
        (entity3_tag_meta_t){desc[i].fun, desc[i].data_size, desc[i].data_init};
}

void entity3_tag_init_enemy(void *pdata)
{
    entity3_tag_enemy_data_t *data = pdata;

    data->chunk = (ssize2){0, 0};
    data->max_speed = 0.0;
    data->a_vel = 4.0;
    data->spawn = dvec3_init(0.0, 0.0, 0.0);
    data->target = data->spawn;
    data->is_moving = 0;
    data->is_furious = 0;
    data->max_state = 0.0;
    data->min_furious = 4.0;
    data->hp = 100.0;
    data->last_damage = 0.0;
    data->atk = 5.0;
    data->is_npc = 0;
    data->enemy_type = ENEMY_BASE;
}

void entity3_tag_init_player(void *pdata)
{
    entity3_tag_player_data_t *data = pdata;

    data->state = PLAYER_REG;
    data->anim_state = 0.0;
    data->has_atk = 0;
    data->atk = 0.0;
    data->has_boom = 0;
    data->last_damage = 0.0;
    data->hp = 0.0;
    data->max_hp = 50.0;
    data->level = 1.0;
    data->xp = 0.0;
    data->max_xp = 10.0;
    data->mana = 0.0;
    data->max_mana = 5.0;
}
