/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#pragma once

#define CAM_MOVE 256.0f
#define PLAYER_MOVE 12.0f
#define PLAYER_MAX_SPEED_WALK 4.0f
#define PLAYER_MAX_SPEED 8.0f

void demo_poll_input(demo_t *demo);

int demo(arg_t, int mode_dev);
demo_t* demo_init(void);

void snake_init(void);
void snake_spawn_target(void);
int snake_is_pos_safe(ivec3 pos);

void demo_init_win(demo_t *demo);

void demo_quit(demo_t *demo);

void demo_render_geom(demo_t *demo);

arg_t get_data_from_arg(int ac, char **av);

void demo_loop(demo_t *demo);

int demo_poll_events(demo_t *demo);

void demo_refresh_mouse_pos(void);
void demo_poll_mouse_pos(demo_t *demo);

void clocks_refresh_time(void);
void clocks_init(demo_t *demo);
void clocks_quit(demo_t *demo);

void init(void);
void quit(void);

void gl_gen(demo_t *demo);
void gl_delete(demo_t *demo);

void reset_matrix(demo_t *demo);
void refresh_vp(demo_t *demo);
void send_aperture(demo_t *demo, gluint program);

void load_model(octree **tree);

void player_physics(demo_t *demo);

void demo_update_framerate(demo_t *demo);

void demo_texture_destroy(demo_t *demo);

float get_random_float(float borne_min, float borne_max);
int get_random_int(int borne_min, int borne_max);

void demo_update_cursor_visibility(demo_t *demo);
void demo_center_cursor(demo_t *demo);
void demo_refresh_cursor(void);

void player_init(demo_t *demo);
