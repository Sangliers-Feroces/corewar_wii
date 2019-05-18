/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** invent_struct
*/

#pragma once

#define INVENTORY_SIZE 11

typedef enum {
    ITEM_SWORD_1,
    ITEM_SWORD_2,
    ITEM_SWORD_3,
    ITEM_APPLE,
    ITEM_BOAT,
    ITEM_PLANE,
    ITEM_PLANK,
    ITEM_TILE,
    ITEM_SCALE,
    ITEM_FISHTOOTH,
    ITEM_END,
    NO_ITEM
} items_t;

typedef enum {
    TYPE_REST_MANA,
    TYPE_REST_HP,
    TYPE_CAC,
    TYPE_BAZAR,
    TYPE_VEHICULE
} items_type_t;

typedef enum {
    STAT_HP,
    STAT_MANA,
    STAT_ATTACK,
    STAT_DEFENSE,
    STAT_LVL,
    STAT_XP,
    STAT_END
} stat_display_t;

typedef struct {
    char *name;
    items_type_t type;
    iutex_t texture;
    //if wepaons
    int attack;
    //if consumable
    int restored_hp;
    int restored_mana;
    //if vheicule
    int speed;
} item_data_t;

typedef struct {
    items_t item;
    int nb;
} inventory_t;

typedef struct {
    int equiped_state;
    int text_start;
    int index_cursor;
    int focused_item;
    int save_focus;
    //
    entity2_t equiped_img;
    entity2_t item_image;
    entity2_t cursor;
    vg_text invent_items_name[5];
    inventory_t inventory[11];
    item_data_t items_list[ITEM_END];
    //desc
    vg_text desc_name;
    vg_text desc_type;
    vg_text desc_value;
    //button's array
    vg_text stats[STAT_END];
} invent_t;
