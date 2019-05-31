/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

/*static void poll_keys(demo_t *demo)
{
    for (size_t i = 0; i < 256; i++)
        demo->input.key_last[i] = demo->input.key_state[i];
    for (size_t i = 0; i < 26; i++)
        demo->input.key_state['A' + i] = sfKeyboard_isKeyPressed(sfKeyA + i);
    demo->input.key_state[KEY_DEL] = sfKeyboard_isKeyPressed(sfKeyDelete);
    demo->input.key_state[KEY_ENTER] = sfKeyboard_isKeyPressed(sfKeyEnter);
    demo->input.key_state[KEY_TAB] = sfKeyboard_isKeyPressed(sfKeyTab);
    demo->input.key_state[KEY_ESC] = sfKeyboard_isKeyPressed(sfKeyEscape);
    demo->input.key_state[KEY_ARROW_UP] = sfKeyboard_isKeyPressed(sfKeyUp);
    demo->input.key_state[KEY_ARROW_DOWN] = sfKeyboard_isKeyPressed(sfKeyDown);
    demo->input.key_state[KEY_ARROW_LEFT]= sfKeyboard_isKeyPressed(sfKeyLeft);
    demo->input.key_state[KEY_ARROW_RIGHT] =
    sfKeyboard_isKeyPressed(sfKeyRight);
    for (size_t i = 0; i < 256; i++)
        demo->input.key_press[i] =
        (!demo->input.key_last[i]) && demo->input.key_state[i];
}*/

void demo_poll_input(demo_t *demo)
{
    demo_update_framerate(demo);
    //poll_keys(demo);
}
