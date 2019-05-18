/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void entity3_set_tag(entity3 *ent, entity3_tag_t tag)
{
    if (ent->tag == tag)
        return;
    ent->tag = tag;
    if (_demo->world.tag[tag].data_size == 0) {
        ent->tag_data = NULL;
        return;
    }
    ent->tag_data = malloc_safe(_demo->world.tag[tag].data_size);
    _demo->world.tag[tag].data_init(ent->tag_data);
}
