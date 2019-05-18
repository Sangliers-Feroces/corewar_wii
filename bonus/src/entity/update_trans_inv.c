/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void entity3_update_trans_inv(entity3 *ent)
{
    if (memcmp(ent->trans.world, ent->trans.world_on_inv_calculated,
    sizeof(dmat4)) == 0)
        return;
    dmat4_inv(ent->trans.world, ent->trans.world_inv);
    dmat4_copy(ent->trans.world, ent->trans.world_on_inv_calculated);
}
