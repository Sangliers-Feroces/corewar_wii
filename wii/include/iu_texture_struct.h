/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** ui_struct
*/

#pragma once

//deprecated but needed to keep the programm running
typedef struct {
    float width;
    float lenght;
} quad_size_t;

typedef enum {
    UIRES_ELON,
    UIRES_CROSS,
    UIRES_PAINT,
    UIRES_TEXTURE,
    UIRES_LIGHTMAPS,
    UIRES_PLAY,
    UIRES_ISO,
    UIRES_CAM,
    UIRES_CADRE,
    UIRES_POURCENT,
    UIRES_RED,
    UIRES_LM_TITLE,
    UIRES_LM_LEGEND,
    UIRES_LM_PLUS,
    UIRES_LM_MINUS,
    UIRES_LM_START,
    UIRES_LM_BACK,
    UIRES_LM_ABORT,
    UIRES_DIGIT_0,
    UIRES_DIGIT_1,
    UIRES_DIGIT_2,
    UIRES_DIGIT_3,
    UIRES_DIGIT_4,
    UIRES_DIGIT_5,
    UIRES_DIGIT_6,
    UIRES_DIGIT_7,
    UIRES_DIGIT_8,
    UIRES_DIGIT_9,
    UIRES_MENU_ELON,
    UIRES_MENU_INTRO,
    UIRES_MENU_DEV,
    UIRES_MENU_ENGINE,
    UIRES_MENU_MENU,
    UIRES_MENU_PLAY,
    UIRES_MENU_QUIT,
    UIRES_MENU_CURSOR,
    UIRES_EDITOR_SELECT,
    UIRES_EDITOR_GRAB,
    UIRES_TERRAIN,
    UIRES_MAX
} uires_t;

typedef enum {
    UIBUTTON_MOVE,
    UIBUTTON_PAINT,
    UIBUTTON_TEXTURE,
    UIBUTTON_LIGHTMAPS,
    UIBUTTON_PLAY,
    UIBUTTON_ISO,
    UIBUTTON_CAM,
    UIBUTTON_CADRE,
    UIBUTTON_MAX,
    UIBUTTON_NONE
} uibutton_t;

typedef enum {
    UILMBUTTON_TITLE,
    UILMBUTTON_PLUS,
    UILMBUTTON_MINUS,
    UILMBUTTON_LEGEND,
    UILMBUTTON_START,
    UILMBUTTON_BACK,
    UILMBUTTON_ABORT,
    UILMBUTTON_LOADING,
    UILMBUTTON_CADRE,
    UILMBUTTON_POURCENT,
    UILMBUTTON_END,
    UILMBUTTON_NONE
} uilmbutton_t;

typedef struct {
    int index;
    char *path;
}  ui_texture_descriptor_t;

typedef enum {
    REL_X,
    REL_Y
} rel_type_t;

typedef struct {
    uires_t texture_index;
    vec2 pos;
    float size;
    float depth;
    rel_type_t rel;
} button_t;

typedef struct {
    int back;
    uilmbutton_t button_clicked;
    button_t object[UILMBUTTON_END];
} ui_lm_struct_t;

typedef struct {
    int value;
    button_t digit;
} digit_array_t;

typedef struct {
    int nb_digit;
    digit_array_t *digits;
} display_nbr_array_t;

typedef struct {
    int display_ui;
    int selected_texture;
    uibutton_t button_hovered;
    uibutton_t button_clicked;
    gluint ui_program;
    gluint vertex_buffer;
    texture2 *textures[UIRES_MAX];
    button_t buttons[UIBUTTON_MAX];
    float ratiowh;
    ui_lm_struct_t ui_lightmap_struct;
    display_nbr_array_t display_nbr_array;
    display_nbr_array_t loading_pourcent;
    size_t ray_density;
} ui_struct;

// end of old version
typedef enum {
    IUTEX_ELON,
    IUTEX_PLUS,
    IUTEX_MINUS,
    IUTEX_SLIDER,
    IUTEX_MENU_MAIN,
    IUTEX_MENU_CONTINUE,
    IUTEX_MENU_LOAD,
    IUTEX_MENU_LOAD_FADE,
    IUTEX_MENU_NEW,
    IUTEX_MENU_SETTINGS,
    IUTEX_MENU_HELP,
    IUTEX_MENU_QUIT,
    IUTEX_MENU_CURSOR,
    IUTEX_EDITOR_GRAB,
    IUTEX_EDITOR_SELECT,
    IUTEX_INVENT_BG,
    IUTEX_TEXT_CADRE,
    IUTEX_FONT_MINECRAFT,
    IUTEX_ITEM_BOAT,
    IUTEX_ITEM_APPLE,
    IUTEX_ITEM_SWORD1,
    IUTEX_ITEM_SWORD2,
    IUTEX_ITEM_SWORD3,
    IUTEX_ITEM_PLANE,
    IUTEX_ITEM_PLANK,
    IUTEX_ITEM_FISHTOOTH,
    IUTEX_ITEM_VOID,
    IUTEX_INVENT_EQUIP,
    IUTEX_PAUSE_BG,
    IUTEX_PAUSE_CONTINUE,
    IUTEX_PAUSE_SETTING,
    IUTEX_PAUSE_MENU,
    IUTEX_PAUSE_QUIT,
    IUTEX_SETTINGS_BG,
    IUTEX_SETTINGS_VOLUME,
    IUTEX_SETTINGS_CB_EMPTY,
    IUTEX_SETTINGS_CB_FULL,
    IUTEX_UI,
    IUTEX_XP_BAR,
    IUTEX_HP_BAR,
    IUTEX_INTRO_VM_BG,
    IUTEX_INTRO_VM,
    IUTEX_INTRO_ENG,
    IUTEX_INTRO_DEV,
    IUTEX_BLACK,
    IUTEX_HELP,
    IUTEX_INVENT_HELP,
    IUTEX_END
} iutex_t;

typedef enum {
    IUREL_X,
    IUREL_Y,
    IUREL_FULL
} rel_t;

typedef enum {
    PATTERN_CLICK_BUTTON,
    PATTERN_SLIDE_BUTTON,
    PATTERN_DRAG_AND_DROP,
    PATTERN_CLASSIC,
    PATTERN_END
} pattern_t;

struct entity2 {
    iutex_t index;
    rect_t rect;
    float depth;
    rel_t rel;
    pattern_t pattern;
    struct entity2 *slider;
    float x_min;
    float x_max;
};
typedef struct entity2 entity2_t;
