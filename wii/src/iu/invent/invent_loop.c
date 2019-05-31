/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** invent_loop
*/

#include "headers.h"

static void draw_5_elems(vg_text *to_draw)
{
    for (int i = 0; i < 5; i++)
        vg_text_draw(to_draw[i]);
}

static void invent_inventory_list_draw(void)
{
    char buff_nb[5][64];

    for (int i = 0; i < 5; i++) {
        if (_iu.invent.inventory[_iu.invent.text_start + i].item == NO_ITEM)
            vg_text_reset_str(&_iu.invent.invent_items_name[i], "Empty", "");
        else if (_iu.invent.inventory[_iu.invent.text_start + i].nb == 1
        || _iu.invent.items_list[_iu.invent.inventory[
        _iu.invent.text_start + i].item].type == TYPE_CAC)
            vg_text_reset_str(&_iu.invent.invent_items_name[i],
            _iu.invent.items_list[_iu.invent.inventory[
            _iu.invent.text_start + i].item].name, NULL);
        else {
            sprintf(buff_nb[i], " x%d",
            _iu.invent.inventory[_iu.invent.text_start + i].nb);
            vg_text_reset_str(&_iu.invent.invent_items_name[i],
            _iu.invent.items_list[_iu.invent.inventory[
            _iu.invent.text_start + i].item].name, buff_nb[i]);
        }
    }
    draw_5_elems(_iu.invent.invent_items_name);
}

static void invent_draw_desc(void)
{
    char buff_name[20];
    char buff_type[20];
    char buff_value[20];

    if (_iu.invent.inventory[_iu.invent.focused_item].item == NO_ITEM)
        invent_desc_set_default();
    else {
        sprintf(buff_name, "NAME:%s",
        _iu.invent.items_list[_iu.invent.inventory
        [_iu.invent.focused_item].item].name);
        vg_text_reset_str(&_iu.invent.desc_name, buff_name, NULL);
        sprintf(buff_type, "TYPE:%s", invent_get_item_type());
        vg_text_reset_str(&_iu.invent.desc_type, buff_type, NULL);
        sprintf(buff_value, "%s%d", invent_get_item_value(),
        invent_get_item_data());
        vg_text_reset_str(&_iu.invent.desc_value, buff_value, NULL);
    }
    vg_text_draw(_iu.invent.desc_name);
    vg_text_draw(_iu.invent.desc_type);
    vg_text_draw(_iu.invent.desc_value);
}

static void draw_invent(void)
{
    world_render();
    //glUseProgram(_demo->shader[SHADER_IU].program);
    for (int i = 0; i < IUINVENT_END; i++)
        iu_entity_draw(_iu.invent_bg[i]);
    invent_inventory_list_draw();
    invent_display_icon();
    iu_entity_draw(_iu.invent.cursor);
    invent_draw_desc();
    invent_draw_stat();
}

void invent_loop(void)
{
    //glBindFramebuffer(GL_FRAMEBUFFER, 0);
    do {
        refresh_invent_help();
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        draw_invent();
        //sfRenderWindow_display(_demo->win.window);
    } while (invent_poll_event());
    _iu.data.is_invent = !_iu.data.is_invent;
    _iu.invent.index_cursor = 0;
    _iu.invent.focused_item = 0;
    player_update_weapon();
}
