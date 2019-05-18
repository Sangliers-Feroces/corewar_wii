/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** vg_text_struct
*/

#pragma once

typedef enum {
    DIAL_FUNC_QUIT,
    DIAL_FUCN_NO_EFFECT
} dialogue_linked_func_t;

typedef enum {
    IUCADRE_BLACK,
    IUCADRE_CHOICES,
    IUCADRE_END
} iucadre_t;

typedef enum {
    DIALOGUE_WELCOME,
    DIALOGUE_MAIN1_START,
    DIALOGUE_MAIN2_START,
    DIALOGUE_MAIN3_START,
    DIALOGUE_MAINBOSS,
    DIALOGUE_END_STORIE,
    DIALOGUE_END
} dialogues_list_t;

typedef enum {
    TEXT_TEST,
    TEXT_TEST_1,
    TEXT_TEST_2,
    TEXT_MAIN1_START1,
    TEXT_MAIN1_START2,
    TEXT_MAIN1_START3,
    TEXT_MAIN1_SCHOICE,
    TEXT_MAIN2_START1,
    TEXT_MAIN2_START2,
    TEXT_MAIN2_START3,
    TEXT_MAIN3_START1,
    TEXT_MAIN3_START2,
    TEXT_MAIN3_START3,
    TEXT_MAINBOSS,
    TEXT_END_1,
    TEXT_END_2,
    TEXT_END_CHOICE,
    TEXT_INVENT_FULL,
    TEXT_WARNING_SCREEN,
    TEXT_END
} text_index_t;

typedef struct {
    text_index_t index;
    char *src;
} text_src_t;

typedef enum {
    TEXT_GRP_IND_WELCOME,
    TEXT_IND_END
} text_grp_ind_t;

typedef enum {
    FONT_MINECRAFT,
    FONT_VM,
    FONT_END
} font_list_t;

typedef struct {
    char *str;
    char *value;
    font_list_t font_index;
    rect_t pos_size;
} vg_text;

typedef struct {
    char *str;
    void (*ptr)(void);
} dialogue_text;

typedef struct {
    char *c1;
    char *c2;
    void (*ptr1)(void);
    void (*ptr2)(void);
} choices_arg_t;

typedef struct {
    int read;
    int read_head;
    int nb_texts;
    font_list_t font_index;
    rect_t pos_size;
    dialogue_text *texts;
    iucadre_t cadre;
    //choices
    int choices;
    dialogue_text choices_display[2];
} vg_dialogue;
