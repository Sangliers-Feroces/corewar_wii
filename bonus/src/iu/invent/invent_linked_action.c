/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** invent_linked_action
*/

#include "headers.h"

static int invent_add_item_adv(items_t item, int is_silent)
{
    char buf[512];

    if (!is_silent) {
        sprintf(buf, "Loot: %s", _iu.invent.items_list[item].name);
        msg_add(buf, 4.0);
    }
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (_iu.invent.inventory[i].item == item) {
            _iu.invent.inventory[i].nb++;
            return 1;
        }
    }
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (_iu.invent.inventory[i].item == NO_ITEM) {
            _iu.invent.inventory[i].item = item;
            _iu.invent.inventory[i].nb = 1;
            return 1;
        }
    }
    return 0;
}

int invent_add_items(items_t item, size_t count)
{
    char buf[512];

    if (count > 1)
        sprintf(buf, "Loot: %s x%zu", _iu.invent.items_list[item].name, count);
    else
        sprintf(buf, "Loot: %s", _iu.invent.items_list[item].name);
    msg_add(buf, 4.0);
    for (size_t i = 0; i < count; i++)
        invent_add_item_adv(item, 1);
    return 1;
}

int invent_add_item(items_t item)
{
    return invent_add_item_adv(item, 0);
}
