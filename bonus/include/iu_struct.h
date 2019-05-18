/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** iu_struct
*/

#pragma once

typedef enum {
    IUBUTTON_ELON,
    IUBUTTON_CADRE,
    IUBUTTON_END
} iubutton_t;

typedef enum {
    IUINVENT_BG,
    IUINVENT_END
} iuinvent_t;

typedef enum {
    ERROR_INVENT_FULL,
    WARNING_SCREEN_MODIF,
    ERROR_MSG_END
} error_msg_t;

typedef struct {
    iutex_t index;
    int cols;
    int lines;
} font_t;

typedef struct {
    iutex_t index;
    char *path;
} iutex_path_t;

typedef struct {
    iutex_t index;
    rect_t rect;
    float depth;
} entity2_param_t;

typedef enum {
    IUENT_MAIN,
    IUENT_HP,
    IUENT_XP,
    IUENT_END
} iu_entities_t;

typedef enum {
    VM,
    BG,
    INTRO_END,
} intro_t;

typedef struct {
    int mode_dev;
    int skip_intro;
    int iu_is_display;
    int ratiowh;
    gluint vertex_array;
    gluint vertex_buffer;
    int is_invent;
    int is_focus;
    vg_text fps_display;
    vg_text error_message[ERROR_MSG_END];
} iu_data_t;

typedef struct {
    iu_data_t data;
    texture2 *textures[IUTEX_END];
    entity2_t entities[IUENT_END];
    entity2_t buttons[IUBUTTON_END];
    entity2_t invent_bg[IUINVENT_END];
    entity2_t cadre[IUCADRE_END];
    entity2_t intro[INTRO_END];
    entity2_t help;
    //texts
    font_t fonts[FONT_END];
    char *text_src[TEXT_END];
    dialogues_list_t current_dialogue;
    vg_dialogue dialogue_list[DIALOGUE_END];
    //invent
    invent_t invent;
    //pause
    pause_t pause;
    //settings
    settings_t settings;
} iu_t;
