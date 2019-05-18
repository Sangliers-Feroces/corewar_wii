/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

/*static int spawn_group(chunk_t *chunk, dvec3 pos)
{
    size_t c = rand() % 4;

    if (world_get_ground_level(pos, 0.0) < 0.0)
        return 0;
    for (size_t i = 0; i < c; i++)
        chunk_spawn_at(chunk, dvec3_add(pos,
        dvec3_init((randf() - 0.5) * 8.0, 0.0, (randf() - 0.5) * 8.0)));
    return 1;
}

static void update_enemy_chunk(chunk_t *chunk)
{
    dvec3 player;
    dvec3 spawn_point;

    if (chunk->is_stalled)
        return;
    player = dmat4_trans(_demo->world.player->trans.world);
    player.y = 0.0;
    while (chunk->enemy_count < chunk->enemy_count_max) {
        spawn_point =
        dvec3_init(randf() * CHUNK_SIZE, 0.0, randf() * CHUNK_SIZE);
        if (dvec3_dist(player, spawn_point) < CHUNK_SIZE / 4.0)
            continue;
        if (!spawn_group(chunk, spawn_point))
            return;
    }
}

static void chunk_update(chunk_t *chunk)
{
    if (chunk->is_stalled)
        return;
    update_enemy_chunk(chunk);
    entity3_update(chunk->ents);
    if (chunk->ents_ext != NULL)
        entity3_update(chunk->ents_ext);
    while (chunk->ents_global->sub.count > 0)
        entity3_move(chunk->ents_global->sub.ent[0], _demo->world.ents);
}*/

/*static void update_sound(void)
{
    double water_ratio;
    dvec3 c = dmat4_trans(_demo->world.camera->trans.world);

    if (c.y > -30.0)
        water_ratio = 0.0;
    else
        water_ratio = CLAMP(-(c.y + 30.0) / 12.0, 0.0, 1.0);
    sound_refresh_gain(SOUNDS_FOREST, (1.0 - water_ratio) * 100.0);
    sound_refresh_gain(SOUNDS_WATER, water_ratio * 100.0);
    if (_demo->quest.curr_main_quest == MAIN_QUEST_BOSS)
        play_new_music_ensure(MUSICS_BOSS, 1, 100.0);
}*/

void world_update(void)
{
    /*world_chunk_god();
    for (size_t i = 0; i < _demo->world.chunk_count; i++)
        chunk_update(_demo->world.chunk[i]);*/
    entity3_global_update(_demo->world.ents);
    world_update_triggers();
    refresh_vp(_demo);
    //update_sound();
}
