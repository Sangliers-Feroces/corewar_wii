/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#pragma once

#define VM_W 96
#define VM_H 64

typedef enum {
    ACTION_PAINT,
    ACTION_MOVE
} action_t;

typedef enum {
    KEY_DEL = 127,
    KEY_TAB = 9,
    KEY_ESC = 0,
    KEY_ARROW_UP = 1,
    KEY_ARROW_DOWN = 2,
    KEY_ARROW_LEFT = 3,
    KEY_ARROW_RIGHT = 4,
    KEY_ENTER = 10
} keycode_t;

typedef struct {
    float size;
    int iter;
    float strenght;
} arg_t;

typedef struct {
    int key_last[256];
    int key_state[256];
    int key_press[256];
    u16 pad, pad_prev;
    u16 pad_press;
} input_t;

typedef struct {
    uint32_t w;
    uint32_t h;
    //sfRenderWindow *window;
    double framelen;
    //sfClock *frametime;
    int has_focus;
    int fps_to_display;
    int do_reboot;
} win_t;

typedef struct {
    long double fovw;
    long double ratiowh;
    long double near;
    proj_type_t proj;
    mvp_t mvp;
    ray_viewport_t viewport;
    ivec3 pos;
    ivec3 pos_prev;
    ivec3 r;
    ivec3 u;
    ivec3 f;
    ivec3 r_prev;
    ivec3 u_prev;
    ivec3 f_prev;
    size_t rot_anim;
    size_t pos_anim;
    size_t speed;
} cam_t;

typedef struct {
    /*sfMouseButton button_last;
    sfMouseButton button_state;
    sfMouseButton button_release;
    sfMouseButton button_click;
    sfVector2i last_pos;
    sfVector2i mouse_pos;*/
    ray3 ray;
} mouse_t;

typedef struct {
    char *to_display;
    double start;
    double life;
} msg_entry_t;

typedef struct {
    size_t count;
    size_t allocated;
    msg_entry_t *msg;
} vec_msg_entry_t;

typedef struct {
    gluint hdr_framebuffer;
    gluint hdr_depthbuffer;
    gluint hdr_render_texture;
    gluint dist_texture;
    vec_render_call_t to_draw;
    int cull_state;
    vec_msg_entry_t msgs;
    void *frameBuffer[2];
    void *xfb;
    u32 fb;
    GXRModeObj *rmode;
} buf_t;

typedef enum {
    GAME_EDITOR,
    GAME_PLAYING
} game_state_t;

typedef struct {
    size_t count;
    size_t allocated;
    dvec3 *selection;
} vec_selection_t;

typedef struct {
    //sfClock *game_clock;
    double t;
} clocks_t;

typedef struct {
    //stats
    float hp;
    float curr_hp;
    float mana;
    float curr_mana;
    float defense;
    float attack;
    float attack_add;
    //
    int lvl;
    float xp;
    float next_xp_step;
    iutex_t pp;
} player_t;

typedef struct {
    player_t player;
    clocks_t clocks;
    action_t action;
    win_t win;
    cam_t cam;
    input_t input;
    world_t world;
    mouse_t mouse;
    buf_t buf;
    shader_cache_t shader[SHADER_MAX];
    material_full_t material[MATERIAL_MAX];
    texture2 *tex[TEX_MAX];
    mesh_full_t *mesh_bank[MESH_BANK_MAX];
    sound_t sounds;
    quests_t quest;
    vec_str_t champ_names;
    /*void *boxList[5]; // Storage for the display lists
    u32 boxSize[5];   // Real display list sizes*/
} demo_t;
