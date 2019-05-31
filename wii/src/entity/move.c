/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void entity3_move(entity3 *ent, entity3 *dst_parent)
{
    entity3_remove_from_parent(ent);
    entity3_set_child(dst_parent, ent);
}
