/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#pragma once

#define WORLD_LOD_COUNT 3
#define WORLD_LOD_MAX (WORLD_LOD_COUNT - 1)
#define CHUNK_SIZE_TERRAIN 1024.0
#define CHUNK_SIZE 256.0
#define CHUNK_TERRAIN_SUB_SIZE ((ssize_t)(CHUNK_SIZE_TERRAIN / CHUNK_SIZE))
#define CHUNK_GEN_ITER 6
#define CHUNK_GEN_EXT_ITER 2
#define CHUNK_LOAD_DISTANCE 8

typedef struct {
    size_t lod;
    vec_rtx_triangle *geom;
    size_t vertex_count;
    gluint vertex_buffer;
    gluint vertex_array;
    int do_reupload_buf;
} chunk_lod_t;

typedef struct {
    arr_dvec3_t data[2][2][CHUNK_GEN_ITER];  // x, then z, negative, positive
} chunk_border_t;

typedef struct {
    int is_static;
    int is_physics;
    int is_collision;
    int is_grounded;
    double slide_threshold;
    double t;
    double life;
    dvec3 pos;
    dvec3 scale;
    dvec3 rot;
    dvec3 speed;
    dmat4 model;
    dmat4 model_rot;
    dvec3 pos_on_model;
    dvec3 scale_on_model;
    dvec3 rot_on_model;
    dmat4 world;
    dmat4 world_rot;
    dmat4 world_inv;
    dmat4 world_on_inv_calculated;
} transform_t;

typedef struct {
    int do_upload;
    int do_reupload;
    gluint vertex_buffer;
    gluint vertex_array;
    void *disp_list;
    u32 disp_list_size;
} mesh_gpu_t;

typedef struct {
    size_t vertex_count;
    size_t vertex_allocated;
    vertex_t *vertex;
    mesh_gpu_t gpu;
} mesh_t;

typedef struct {
    vec2 uv_ext;
    float tex_a;
    float tex_b;
    float ratio;
} vertex_ext_t;

typedef struct {
    mesh_t *mesh;
    int has_ext;
    size_t ext_count;
    size_t ext_allocated;
    vertex_ext_t *ext;
    mesh_gpu_t gpu;
} mesh_full_t;

typedef enum {
    MESH_FULL_REF_RENDER_LOD0,
    MESH_FULL_REF_RENDER_LOD1,
    MESH_FULL_REF_RENDER_LOD2,
    MESH_FULL_REF_STANDALONE,
    MESH_FULL_REF_BANK
} mesh_full_ref_type_t;

typedef enum {
    MESH_BANK_SKYBOX,
    MESH_BANK_GRASS1,
    MESH_BANK_ARM,
    MESH_BANK_SWORD_1,
    MESH_BANK_SWORD_2,
    MESH_BANK_SWORD_3,
    MESH_BANK_ENEMY_BASE,
    MESH_BANK_ENEMY_FISH,
    MESH_BANK_PARTICLE1,
    MESH_BANK_KNIGHT,
    MESH_BANK_CASA_L0,
    MESH_BANK_CASA_L1,
    MESH_BANK_CASA_L2,
    MESH_BANK_NPC1,
    MESH_BANK_PLANE,
    MESH_BANK_BOX,
    MESH_BANK_BOX_INV,
    MESH_BANK_MAX
} mesh_bank_t;

typedef struct {
    mesh_bank_t bank;
    const char *path;
} mesh_desc_t;

typedef struct {
    mesh_full_ref_type_t ref_type;
    mesh_bank_t bank;
    mesh_full_t *m;
} mesh_full_ref_t;

typedef struct {
    size_t count;
    size_t allocated;
    mesh_full_t **mesh;
} vec_mesh_full_t;

typedef struct {
    mesh_full_ref_t mesh;
    vec_rtx_triangle_ref ref;
    int is_on;
} col_ref_t;

typedef enum {
    RENDER_OBJ_LOD_DIST_FAR,
    RENDER_OBJ_LOD_DIST_NEAR,
    RENDER_OBJ_LOD_DIST_GRASS_CLUSTER1,
    RENDER_OBJ_LOD_DIST_GRASS_CLUSTER2,
    RENDER_OBJ_LOD_DIST_MAX
} render_obj_lod_dist_t;

typedef struct {
    mesh_full_ref_t mesh;
    material_t material;
} render_obj_t;

typedef struct entity3 entity3;

typedef struct {
    size_t count;
    size_t allocated;
    entity3 **ent;
} vec_entity3_t;

typedef enum {
    TRIGGER_ON_HIT_NONE,
    TRIGGER_ON_HIT_PLAYER,
    TRIGGER_ON_HIT_SWORD,
    TRIGGER_ON_HIT_MAX
} trigger_on_hit_t;

typedef void (*trigger_on_hit_fun_t)(entity3 *ent, entity3 *other);

typedef struct {
    dvec3 min;
    dvec3 max;
    trigger_on_hit_t on_hit;
    entity3 *ent;
    size_t ndx;
} trigger_t;

typedef struct {
    trigger_on_hit_t trigger;
    trigger_on_hit_fun_t on_hit;
} trigger_on_hit_desc_t;

typedef struct {
    size_t count;
    size_t allocated;
    trigger_t **trigger;
} vec_trigger_t;

typedef enum  {
    ENTITY3_TAG_NONE,
    ENTITY3_TAG_TERRAIN,
    ENTITY3_TAG_PLAYER,
    ENTITY3_TAG_CAMERA,
    ENTITY3_TAG_SWORD,
    ENTITY3_TAG_SKYBOX,
    ENTITY3_TAG_ENEMY,
    ENTITY3_TAG_SNAKE,
    ENTITY3_TAG_MAX
} entity3_tag_t;

struct entity3 {
    transform_t trans;
    render_obj_t render[WORLD_LOD_COUNT];
    render_obj_lod_dist_t lod_dist;
    int render_is_rec;
    col_ref_t col;
    trigger_t *trigger;
    entity3_tag_t tag;
    void *tag_data;
    entity3 *root;
    size_t root_ndx;
    vec_entity3_t sub;
};

typedef struct {
    ssize2 pos;
    chunk_border_t border;
    chunk_border_t border_ter;
    arr2d_dvec3_t terrain_base;
    size_t world_ndx;
    size_t enemy_count;
    size_t enemy_count_max;
    entity3 *ents;
    entity3 *ents_ext;
    entity3 *ents_global;   // used on unloaded chunks for far entities
    entity3 *terrain;
    entity3 *inserting;
    int is_stalled;
} chunk_t;

typedef struct {
    entity3_tag_t tag;
    void (*fun)(entity3 *ent);
    size_t data_size;
    void (*data_init)(void *data);
} entity3_tag_update_desc_t;

typedef struct {
    void (*update)(entity3 *ent);
    size_t data_size;
    void (*data_init)(void *data);
} entity3_tag_meta_t;

#define CUBE_SIZE 16
#define CUBE_COUNT (CUBE_SIZE * CUBE_SIZE * CUBE_SIZE)

typedef struct {
    char *map_path;
    size_t chunk_count;
    size_t chunk_allocated;
    chunk_t **chunk;        // used for rendering / world intersection
    int cube[CUBE_SIZE][CUBE_SIZE][CUBE_SIZE];
    size_t snake_cubes_start;
    size_t snake_cubes_count;
    ivec3 snake_cubes[CUBE_COUNT];
    ivec3 snake_target;
    entity3 *ents;
    entity3 *player;
    entity3 *camera;
    entity3 *skybox;
    entity3 *snake;
    dvec3 light_dir;
    vec_trigger_t triggers; // loaded triggers
    srect chunk2d_area;
    chunk_t **chunk2d;      // 2d array for fast lookup
    octree *tree;           // collision data is exclusively stored here
    entity3_tag_meta_t tag[ENTITY3_TAG_MAX];
    trigger_on_hit_fun_t trigger_on_hit[TRIGGER_ON_HIT_MAX];
} world_t;

typedef struct {
    vec3 pos;
    vec3 normal;
    vec2 uv_albedo;
    vec2 uv_lightmap;
} chunk_vertex_t;

typedef struct {
    size_t count;
    chunk_vertex_t *vertex;
} vec_chunk_vertex_t;

typedef struct {
    dvec3 pos;
    dvec3 normal;
    vec2 uv_albedo;
    vec2 uv_lightmap;
} chunk_dvertex_t;

typedef struct {
    size_t count;
    chunk_dvertex_t *dvertex;
} vec_chunk_dvertex_t;

typedef struct {
    arr2d_dvec3_t arr;
    arr2d_dvec3_t normals;
    srect area;
} terrain_send_ter_arg;

typedef enum {
    PLAYER_REG,
    PLAYER_DEF,
    PLAYER_BOOM,
    PLAYER_ATK
} player_state_t;

typedef struct {
    player_state_t state;
    double anim_state;
    int has_atk;
    double atk;
    int has_boom;
    double hp;
    double max_hp;
    double level;
    double xp;
    double max_xp;
    double mana;
    double max_mana;
    double last_damage;
} entity3_tag_player_data_t;

typedef enum {
    ENEMY_BASE,
    ENEMY_SLIME,
    ENEMY_FISH,
    ENEMY_FISH_BOSS,
    ENEMY_MAX
} enemy_type_t;

typedef struct {
    ssize2 chunk;
    double max_speed;
    double a_vel;
    dvec3 spawn;
    dvec3 target;
    int is_moving;
    int is_furious;
    double max_state;
    double min_furious;
    double hp;
    double last_damage;
    double atk;
    int is_npc;
    double level;
    enemy_type_t enemy_type;
} entity3_tag_enemy_data_t;

typedef struct {
    int do_fast;
    int do_laxist;
    double slide;
} physics_param_t;
