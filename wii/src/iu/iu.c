/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** iu
*/

#include "headers.h"

/*static const iutex_path_t iutex_path [] = {
    {IUTEX_ELON, "res/ui/elon.jpg"},
    {IUTEX_PLUS, "res/ui/plus.png"},
    {IUTEX_MINUS, "res/ui/minus.png"},
    {IUTEX_MENU_MAIN, "res/ui/menu/new/menu.png"},
    {IUTEX_MENU_CONTINUE, "res/ui/menu/new/menu_continue.png"},
    {IUTEX_MENU_LOAD, "res/ui/menu/new/menu_load.png"},
    {IUTEX_MENU_LOAD_FADE, "res/ui/menu/new/menu_load_fade.png"},
    {IUTEX_MENU_NEW, "res/ui/menu/new/menu_new.png"},
    {IUTEX_MENU_SETTINGS, "res/ui/menu/new/menu_setting.png"},
    {IUTEX_MENU_HELP, "res/ui/menu/new/menu_help.png"},
    {IUTEX_MENU_QUIT, "res/ui/menu/new/menu_quit.png"},
    {IUTEX_MENU_CURSOR, "res/ui/menu/new/cursor.png"},
    {IUTEX_EDITOR_GRAB, "res/model/editor/grab.png"},
    {IUTEX_EDITOR_SELECT, "res/model/editor/select.png"},
    {IUTEX_SLIDER, "res/ui/settings/slider.png"},
    {IUTEX_INVENT_BG, "res/ui/invent/invent_bg.png"},
    {IUTEX_TEXT_CADRE, "res/ui/dialogue_cadre.png"},
    {IUTEX_FONT_MINECRAFT, "res/ui/font/minecraft.png"},
    {IUTEX_ITEM_BOAT, "res/ui/invent/item_icons/boat.png"},
    {IUTEX_ITEM_APPLE, "res/ui/invent/item_icons/apple.jpg"},
    {IUTEX_ITEM_SWORD1, "res/ui/invent/item_icons/steel_sword.png"},
    {IUTEX_ITEM_SWORD3, "res/ui/invent/item_icons/rail.jpg"},
    {IUTEX_ITEM_SWORD2, "res/ui/invent/item_icons/valy.jpg"},
    {IUTEX_ITEM_PLANE, "res/ui/invent/item_icons/plane.png"},
    {IUTEX_ITEM_PLANK , "res/ui/invent/item_icons/planks.jpg"},
    {IUTEX_ITEM_FISHTOOTH, "res/ui/invent/item_icons/tooth.png"},
    {IUTEX_ITEM_VOID, "res/ui/invent/item_icons/void.png"},
    {IUTEX_INVENT_EQUIP, "res/ui/invent/equip.png"},
    {IUTEX_PAUSE_BG, "res/ui/pause/pause_bg.png"},
    {IUTEX_PAUSE_CONTINUE, "res/ui/pause/pause_continue.png"},
    {IUTEX_PAUSE_SETTING, "res/ui/pause/pause_setting.png"},
    {IUTEX_PAUSE_MENU, "res/ui/pause/pause_menu.png"},
    {IUTEX_PAUSE_QUIT, "res/ui/pause/pause_quit.png"},
    {IUTEX_SETTINGS_BG, "res/ui/settings/settings_bg.png"},
    {IUTEX_SETTINGS_VOLUME, "res/ui/settings/volume.png"},
    {IUTEX_SETTINGS_CB_EMPTY, "res/ui/settings/cb_0.png"},
    {IUTEX_SETTINGS_CB_FULL, "res/ui/settings/cb_1.png"},
    {IUTEX_UI, "res/ui/main_ui.png"},
    {IUTEX_HP_BAR, "res/ui/hp_bar.png"},
    {IUTEX_XP_BAR, "res/ui/xp_bar.png"},
    {IUTEX_INTRO_VM_BG, "res/ui/intro/sponsors.png"},
    {IUTEX_INTRO_DEV, "res/ui/intro/dev.png"},
    {IUTEX_INTRO_ENG, "res/ui/intro/eng.png"},
    {IUTEX_INTRO_VM, "res/ui/intro/sheet.jpg"},
    {IUTEX_BLACK, "res/ui/black.png"},
    {IUTEX_HELP, "res/ui/menu/new/help.png"},
    {IUTEX_INVENT_HELP, "res/ui/invent/invent_bg_h.png"},
    {0, NULL}
};*/

static void iu_set_gl(void)
{
    /*const vec2 vertex_array_base[] =
    {{0.0f, 0.0f}, {0.0f, 1.0f}, {1.0f, 0.0f},
    {0.0f, 1.0f}, {1.0f, 1.0f}, {1.0f, 0.0f}};

    glGenVertexArrays(1, &_iu.data.vertex_array);
    glBindVertexArray(_iu.data.vertex_array);
    glGenBuffers(1, &_iu.data.vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, _iu.data.vertex_buffer);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,
    sizeof(vec2), BUFFER_OFFSET(0));
    glBufferData(GL_ARRAY_BUFFER, sizeof(vec2) * 6,
    (glvoid*)vertex_array_base, GL_STATIC_DRAW);*/
    _iu.data.is_invent = 0;
}

/*static int iu_check_texture_array(void)
{
    for (int i = 0; i < IUTEX_END; i++) {
        if (_iu.textures[i] == NULL) {
            my_fd_putstr("Can't open textures ", 2);
            putnbr(i, 10, 0);
            my_fd_putchar('\n', 2);
            return 0;
        }
    }
    return 1;
}*/

static void iu_set_texture(void)
{
    /*for (int i = 0; i < IUTEX_END; i++)
        _iu.textures[i] = NULL;
    for (int i = 0; iutex_path[i].path != NULL; i++)
        _iu.textures[iutex_path[i].index] =
        texture2_load(iutex_path[i].path);
    if (!iu_check_texture_array())
        exit(84);
    glBindTexture(GL_TEXTURE_2D, _iu.textures[IUTEX_FONT_MINECRAFT]->id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);*/
}

void iu_init(demo_t *demo)
{
    _iu.data.ratiowh = demo->cam.ratiowh;
    iu_set_gl();
    iu_set_texture();
    set_entities();
    iu_text_init();
    iu_set_font();
    iu_set_vg_text();
    invent_init();
    iu_error_msg_init();
    settings_init();
    quest_init();
    _iu.data.iu_is_display = 1;
    _iu.data.mode_dev = 0;
}

void iu_quit(void)
{
    settings_quit();
    vg_dialogue_quit();
    for (int i = 0; i < IUTEX_END; i++)
        texture2_destroy(_iu.textures[i]);
    //glDeleteVertexArrays(1, &_iu.data.vertex_array);
    //glDeleteBuffers(1, &_iu.data.vertex_buffer);
}
