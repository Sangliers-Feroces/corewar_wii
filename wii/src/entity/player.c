/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

entity3* entity3_get_parent(entity3 *ent, size_t depth)
{
    entity3 *res = ent;

    for (size_t i = 0; (i < depth) && (res != NULL); i++)
        res = res->root;
    return res;
}

void player_respawn(entity3 *ent)
{
    entity3_tag_player_data_t *data = ent->tag_data;

    ent->trans.pos = dvec3_init(0.0, 0.0, -5.0);
    ent->trans.rot = dvec3_init(0.0, 0.0, 0.0);
    data->xp = 0.0;
    data->hp = data->max_hp / 2.0;
    ent->trans.life = FLT64_INF;
    entity3_update_solo(ent);
    entity3_trans_update(_demo->world.camera);
}
