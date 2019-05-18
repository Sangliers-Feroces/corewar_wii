/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** sanic
*/

#pragma once

vec_rtx_triangle_ref vec_rtx_triangle_ref_create(size_t count);
vec_rtx_triangle_ref vec_rtx_triangle_ref_get_void(void);
void vec_rtx_triangle_ref_destroy(vec_rtx_triangle_ref vec);
transform_t transform_get_default(void);
col_ref_t col_ref_get_default(void);
render_obj_t render_obj_get_default(void);
void render_obj_destroy(render_obj_t render);
vec_entity3_t vec_entity3_create(void);
size_t vec_entity3_add(vec_entity3_t *vec, entity3 *entity);
void vec_entity3_destroy(vec_entity3_t vec);
void entity3_set_child(entity3 *parent, entity3 *to_add);
entity3* entity3_create_pos(entity3 *parent, dvec3 pos);
entity3* entity3_create(entity3 *parent);
void entity3_set_col(entity3 *ent, int is_on);
void entity3_bind_col(entity3 *entity, mesh_full_ref_t collision_mesh);
void entity3_remove_from_parent(entity3 *ent);
void entity3_destroy(entity3 *entity);
entity3* chunk_add_entity(chunk_t *chunk);
entity3* world_add_entity(void);
void entity3_set_render(entity3 *ent, size_t lod, mesh_full_ref_t mesh,
material_t material);
mesh_full_t* entity3_create_render(entity3 *ent, size_t lod,
material_t material, int has_ext);

void entity3_move(entity3 *ent, entity3 *dst_parent);

void entity3_render(entity3 *ent, dmat4 vp);

vec_render_call_t vec_render_call_init(void);
void vec_render_call_add(vec_render_call_t *vec, render_call_t to_add);
void vec_render_call_flush(vec_render_call_t *vec);
void vec_render_call_destroy(vec_render_call_t vec);
void render_delay_call(render_call_t to_draw);
void render_delay_exec(void);

void entity3_trans_update(entity3 *ent);
void entity3_update_solo(entity3 *ent);
void entity3_update(entity3 *ent);
void entity3_global_update(entity3 *ent);
entity3* entity3_seek_tag(entity3 *ent, entity3_tag_t tag);

void entity3_physics(entity3 *ent);

trigger_t* trigger_create(dvec3 min, dvec3 max, trigger_on_hit_t on_hit);
void trigger_attach(trigger_t *trigger);
void trigger_detach(trigger_t *trigger);
void trigger_destroy(trigger_t *trigger);
vec_trigger_t vec_trigger_init(void);
void vec_trigger_add(vec_trigger_t *vec, trigger_t *trigger);
void vec_trigger_destroy(vec_trigger_t *vec);
void entity3_add_trigger(entity3 *ent, trigger_t *trigger);
void world_trigger_init(void);

void trigger_update(trigger_t *trigger);
void world_update_triggers(void);

void entity3_update_tag_init(void);

void entity3_tag_init_player(void *pdata);
void entity3_tag_update_player(entity3 *ent);
void entity3_tag_update_player_poll_mouse(entity3 *ent);
void entity3_tag_update_player_poll_editor(
entity3 *ent, dvec3 cam_x, dvec3 cam_z);
void entity3_tag_update_player_poll_playing(
entity3 *ent, dvec3 cam_x, dvec3 cam_z);

void entity3_update_trans_inv(entity3 *ent);

void trigger_on_hit_sword(entity3 *ent, entity3 *other);
void trigger_on_hit_player(entity3 *ent, entity3 *other);

void entity3_set_tag(entity3 *ent, entity3_tag_t tag);

void entity3_tag_update_enemy(entity3 *ent);
void entity3_tag_init_enemy(void *pdata);

void player_update(entity3 *ent, double max_speed);

double world_get_ground_level(dvec3 p, double bias);

void entity3_switch_col(entity3 *ent, int new_state);

void player_respawn(entity3 *ent);
void player_update_weapon(void);

void player_anim(entity3 *ent);
void player_state(entity3 *ent);

void world_spawn_boss(void);

int entity3_is_fish(entity3 *ent);
void player_loot_xp(double xp);

entity3* entity3_get_parent(entity3 *ent, size_t depth);
void entity3_kill(entity3 *ent);

void entity3_spawn_fish(entity3 *ent, entity3_tag_enemy_data_t *data,
double stren, int is_boss);

double double_inter(double a, double b, double ratio);
