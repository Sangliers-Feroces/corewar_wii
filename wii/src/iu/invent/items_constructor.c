/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** items_constructor
*/

#include "headers.h"

static void invent_set_items(void)
{
    _iu.invent.items_list[ITEM_SWORD_1] = (item_data_t){"Steel sword",
    TYPE_CAC, IUTEX_ITEM_SWORD1, 10, 0, 0, 0};
    _iu.invent.items_list[ITEM_SWORD_2] = (item_data_t){"Valyrian Sword",
    TYPE_CAC, IUTEX_ITEM_SWORD2, 30, 0, 0, 0};
    _iu.invent.items_list[ITEM_SWORD_3] = (item_data_t){
    "Reaper's hoax", TYPE_CAC, IUTEX_ITEM_SWORD3, 50, 0, 0, 0};
    _iu.invent.items_list[ITEM_APPLE] = (item_data_t){"Mac Crunch",
    TYPE_REST_HP, IUTEX_ITEM_APPLE, 0, 5, 0, 0};
    _iu.invent.items_list[ITEM_BOAT] = (item_data_t){"Shit Stormer",
    TYPE_VEHICULE, IUTEX_ITEM_BOAT, 0, 0, 0, 90};
    _iu.invent.items_list[ITEM_PLANE] = (item_data_t){"Highflyer", TYPE_CAC,
    IUTEX_ITEM_PLANE, 0, 0, 0, 200};
    _iu.invent.items_list[ITEM_PLANK] = (item_data_t){"Cursed Plank",
    TYPE_BAZAR, IUTEX_ITEM_PLANK, 0, 0, 0, 0};
    _iu.invent.items_list[ITEM_TILE] = (item_data_t){"Tile of DOOM",
    TYPE_BAZAR, IUTEX_ELON, 0, 0, 0, 0};
    _iu.invent.items_list[ITEM_SCALE] = (item_data_t){"Basic Scale",
    TYPE_BAZAR, IUTEX_ELON, 0, 0, 0, 0};
    _iu.invent.items_list[ITEM_FISHTOOTH] = (item_data_t){"Fish tooth",
    TYPE_BAZAR, IUTEX_ITEM_FISHTOOTH, 0, 0, 0, 0};
}

static void set_desc(void)
{
    _iu.invent.desc_name = vg_text_create(NULL, NULL);
    vg_text_set_position(&_iu.invent.desc_name, (vec2){0.05f, 0.15f});
    _iu.invent.desc_type = vg_text_create(NULL, NULL);
    vg_text_set_position(&_iu.invent.desc_type, (vec2){0.05f, 0.05f});
    _iu.invent.desc_value = vg_text_create(NULL, NULL);
    vg_text_set_position(&_iu.invent.desc_value, (vec2){0.05f, -0.05f});
    vg_text_set_size(&_iu.invent.desc_name, (vec2){0.02f, 0.03f});
    vg_text_set_size(&_iu.invent.desc_type, (vec2){0.02f, 0.03f});
    vg_text_set_size(&_iu.invent.desc_value, (vec2){0.02f, 0.03f});
}

void invent_load(void)
{
    file_read_t file = file_read_create("maps/inv");

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        _iu.invent.inventory[i].item = NO_ITEM;
        _iu.invent.inventory[i].nb = 0;
    }
    if (file.data == NULL)
        return;
    file_read(&file, &_iu.invent.inventory, 11 * sizeof(inventory_t));
    file_read_flush(&file);
}

void invent_store(void)
{
    file_write_t file = file_write_create();

    file_write(&file, &_iu.invent.inventory, 11 * sizeof(inventory_t));
    file_write_flush(&file, "maps/inv");
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        _iu.invent.inventory[i].item = NO_ITEM;
        _iu.invent.inventory[i].nb = 0;
    }
}

void invent_init(void)
{
    invent_set_items();
    _iu.invent.text_start = 0;
    _iu.invent.index_cursor = 0;
    _iu.invent.focused_item = 0;
    _iu.invent.save_focus = 0;
    _iu.invent.equiped_state = 0;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        _iu.invent.inventory[i].item = NO_ITEM;
        _iu.invent.inventory[i].nb = 0;
    }
    for (int i = 0; i < 5; i++) {
        _iu.invent.invent_items_name[i] = vg_text_create(NULL, NULL);
        vg_text_set_position(&_iu.invent.invent_items_name[i],
        (vec2){-0.08f, -0.25f - (i * 0.08f)});
        vg_text_reset_str(&_iu.invent.invent_items_name[i], "Empty", NULL);
    }
    set_desc();
    invent_stat_display_init();
}