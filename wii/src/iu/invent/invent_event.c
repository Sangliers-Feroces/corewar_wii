/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** invent_event
*/

#include "headers.h"

static void drop_item(void)
{
    /*f (sfKeyboard_isKeyPressed(sfKeyLControl)) {
        _iu.invent.inventory[_iu.invent.focused_item].item = NO_ITEM;
        _iu.invent.inventory[_iu.invent.focused_item].nb = 0;
        return;
    }*/
    _iu.invent.inventory[_iu.invent.focused_item].nb--;
    if (!_iu.invent.inventory[_iu.invent.focused_item].nb) {
        _iu.invent.inventory[_iu.invent.focused_item].item = NO_ITEM;
        _iu.invent.inventory[_iu.invent.focused_item].nb = 0;
    }
}

static void check_move_lateral(void)
{
    if (_demo->input.key_press[KEY_ARROW_LEFT]) {
        _iu.invent.save_focus = _iu.invent.focused_item;
        _iu.invent.focused_item = 10;
        _iu.invent.equiped_state = 1;
    }
    if (_demo->input.key_press[KEY_ARROW_RIGHT]) {
        _iu.invent.focused_item = _iu.invent.save_focus;
        _iu.invent.equiped_state = 0;
    }
}

static void invent_move_inventory(void)
{
    check_move_lateral();
    if (_iu.invent.equiped_state)
        return;
    if (_demo->input.key_press[KEY_ARROW_UP]) {
        if (_iu.invent.index_cursor == 0) {
            if (_iu.invent.text_start != 0)
                _iu.invent.text_start--;
        } else
            _iu.invent.index_cursor--;
    }
    if (_demo->input.key_press[KEY_ARROW_DOWN]) {
        if (_iu.invent.index_cursor == 4) {
            if (_iu.invent.text_start != 5)
                _iu.invent.text_start++;
        } else
            _iu.invent.index_cursor++;
    }
    _iu.invent.cursor.rect.p.y = -0.25f + (_iu.invent.index_cursor * -0.08f);
    _iu.invent.focused_item = _iu.invent.text_start + _iu.invent.index_cursor;
}

int invent_poll_event(void)
{
    if (!demo_poll_events(_demo))
        return 0;
    if (_demo->input.key_press[KEY_TAB] || _demo->input.key_press[KEY_ESC])
        return 0;
    invent_move_inventory();
    if (_demo->input.key_press[KEY_ENTER])
        invent_switch_action();
    if (_demo->input.key_press['X'])
        drop_item();
    invent_refresh_attack_added();
    return 1;
}
