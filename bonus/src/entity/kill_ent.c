/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static void check_level(void)
{
    entity3_tag_player_data_t *data = _demo->world.player->tag_data;
    char buf[512];

    if (data->xp >= data->max_xp) {
        data->max_hp *= 1.1;
        data->hp = data->max_hp;
        data->xp = 0.0;
        data->max_xp *= 1.1;
        data->level++;
        data->max_mana += 0.4;
        sprintf(buf, "Upgrade to level %.f !", data->level);
        msg_add(buf, 10.0);
    }
}

void player_loot_xp(double xp)
{
    entity3_tag_player_data_t *data = _demo->world.player->tag_data;
    char buf[512];

    data->xp += xp;
    sprintf(buf, "You got %.f xp.", xp);
    msg_add(buf, 4.0);
    check_level();
}

static void loot_enemy_ext(entity3 *ent)
{
    entity3_tag_enemy_data_t *enemy_data = ent->tag_data;
    char buf[512];

    switch (enemy_data->enemy_type) {
    case ENEMY_FISH:
    case ENEMY_FISH_BOSS:
        sprintf(buf, "Killed L.%.f %s", enemy_data->level, "Saumin");
        msg_add(buf, 5.0);
        player_loot_xp(enemy_data->level * 1.5);
        invent_add_items(ITEM_FISHTOOTH, 1 + (enemy_data->enemy_type ==
        ENEMY_FISH ? rand() % 3 : 74));
        break;
    case ENEMY_BASE:
        sprintf(buf, "Killed L.%.f %s", enemy_data->level, "Pykax");
        msg_add(buf, 5.0);
        player_loot_xp(enemy_data->level);
        invent_add_items(ITEM_PLANK, 1 + rand() % 3);
    default:
        break;
    }
}

static void loot_enemy(entity3 *ent)
{
    loot_enemy_ext(ent);
    check_level();
    if ((rand() % 3) == 0)
        invent_add_item(ITEM_APPLE);
}

void entity3_kill(entity3 *ent)
{
    if (ent->tag == ENTITY3_TAG_ENEMY) {
        loot_enemy(ent);
        quest_add_death_counter(ent);
    }
    entity3_destroy(ent);
}
