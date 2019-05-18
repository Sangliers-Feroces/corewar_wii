/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** iu
*/

#pragma once

void iu_init(demo_t *demo);
void set_entities(void);

rect_t entity_get_size(entity2_t entity);
void iu_display(void);

void iu_entity_draw(entity2_t entity);

void entity_constructor(entity2_t *entity, entity2_param_t params);

void iu_text_init(void);
void iu_quit(void);

//int check_click_pos(sfVector2i mouse_pos, entity2_t button,
//float width_screen, float height);

void iu_display_grp(text_grp_ind_t index);

void iu_set_font(void);

void iu_display_str(char *str, rect_t start, font_list_t font,
float canvas_size);

void iu_set_vg_text(void);
void iu_refresh_bar(void);

void iu_error_msg_init(void);

vec_msg_entry_t vec_msg_entry_create(void);
msg_entry_t msg_entry_create(char *buf, double start, double life);
void msg_entry_destroy(msg_entry_t to_destroy);
void vec_msg_entry_flush(vec_msg_entry_t *vec);
void vec_msg_entry_add(vec_msg_entry_t *vec, msg_entry_t to_add);
void vec_msg_entry_delete(vec_msg_entry_t *vec, size_t ndx);
void vec_msg_entry_destroy(vec_msg_entry_t *vec);

void vec_msg_display(vec_msg_entry_t *vec);
void msg_add(char *msg, double duration);
