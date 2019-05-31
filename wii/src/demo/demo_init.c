/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void snake_init(void)
{
    _demo->cam.pos = ivec3_init(0, 0, 0);
    _demo->cam.r = ivec3_init(1, 0, 0);
    _demo->cam.u = ivec3_init(0, 1, 0);
    _demo->cam.f = ivec3_init(0, 0, 1);
    _demo->cam.pos_prev = _demo->cam.pos;
    _demo->cam.r_prev = _demo->cam.r;
    _demo->cam.u_prev = _demo->cam.u;
    _demo->cam.f_prev = _demo->cam.f;
    _demo->cam.rot_anim = 0;
    _demo->cam.pos_anim = 0;
    _demo->cam.speed = 45;
    _demo->world.snake_cubes_start = 0;
    _demo->world.snake_cubes_count = 1;
    _demo->world.snake_cubes[0] = _demo->cam.pos;
}

static void init_cam(demo_t *demo)
{
    demo->cam.ratiowh = (long double)demo->win.w / (long double)demo->win.h;
    demo->cam.fovw = M_PI / 2.0f;
    demo->cam.near = 1.0L;
    demo->cam.proj = PROJ_TYPE_PERSPECTIVE;
    snake_init();
}

static vec_str_t get_champ_list(void)
{
    vec_str_t res = vec_str_init();
    const char *dpath = "/apps/corewar/champions";
    DIR *dir = opendir(dpath);

    if (dir == NULL)
        error_display("Can't open champions directory at %s on SD card", dpath);
    while (1) {
        struct dirent *ent = readdir(dir);
        if (ent == NULL)
            break;
        if ((ent->d_name[0] == '.') || (ent->d_type != DT_REG))
            continue;
        vec_str_add(&res, str_init(strlen(ent->d_name), ent->d_name));
    }
    closedir(dir);
    if (res.count == 0)
        error_display("no champion found in %s", dpath);
    return res;
}

demo_t* demo_init(void)
{
    demo_t *res;

    res = malloc_safe(sizeof(demo_t));
    _demo = res;
    fatInitDefault();
    demo_init_win(res);
    init_cam(res);
    init();
    clocks_init(res);
    _dungeons.cur_origin = (dvec3){0, 0, 0};
    tex_init(res);
    iu_init(res);
    player_init(res);
    gl_gen(res);
    shader_init(res);
    material_init(res);
    mesh_bank_init();
    world_init(res);
    demo_update_cursor_visibility(res);
    sounds_init();
    _demo->champ_names = get_champ_list();
    return (res);
}

void demo_quit(demo_t *demo)
{
    world_quit(demo);
    mesh_bank_quit();
    shader_quit(demo);
    gl_delete(demo);
    iu_quit();
    tex_quit(demo);
    quit();
    //sfRenderWindow_destroy(demo->win.window);
    //sfClock_destroy(demo->win.frametime);
    clocks_quit(demo);
    slider_free();
    sounds_quit();
    vec_str_destroy(_demo->champ_names);
    free(demo);
}
