/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static void add_grass_clusters(entity3 *ent, dvec3 off)
{
    entity3 *cur;
    double base_sub = CHUNK_SIZE / 16.0;
    dvec3 off2 = dvec3_init(CHUNK_SIZE / 16.0 * 0.5, 0.0,
    CHUNK_SIZE / 16.0 * 0.5);

    ent->trans.pos = off;
    ent->lod_dist = RENDER_OBJ_LOD_DIST_GRASS_CLUSTER1;
    ent->render_is_rec = 1;
    entity3_trans_update(ent);
    for (size_t i = 0; i < 16; i++)
        for (size_t j = 0; j < 16; j++) {
            cur = entity3_create(ent);
            cur->trans.pos = dvec3_sub(dvec3_add(
            dvec3_init(base_sub * j, 0.0, base_sub * i), off2), ent->trans.pos);
            cur->lod_dist = RENDER_OBJ_LOD_DIST_GRASS_CLUSTER2;
            cur->render_is_rec = 1;
            entity3_trans_update(cur);
        }
}

static void set_grass_elem(entity3 *ent, vec2 uv, dvec3 p, dvec3 norm)
{
    entity3 *sub;
    entity3 *cur;
    dvec3 off = dvec3_init(CHUNK_SIZE * 0.5, 0.0, CHUNK_SIZE * 0.5);

    sub = ent->sub.ent[MIN((size_t)(uv.y * 16), 15) * 16 +
    MIN((size_t)(uv.x * 16), 15)];
    cur = entity3_create(sub);
    cur->trans.pos = dvec3_sub(dvec3_sub(p, sub->trans.pos), off);
    cur->trans.pos.y -= fabs(norm.y) / 2.0;
    cur->trans.rot.y = randf() * M_PI;
    entity3_set_render(cur, 2,
    mesh_full_ref_bank_init(MESH_BANK_GRASS1), MATERIAL_VEG_GRASS1);
    entity3_trans_update(cur);
}

void chunk_add_grass(chunk_t *chunk, arr2d_dvec3_t arr, arr2d_dvec3_t n)
{
    entity3 *ent = chunk_add_entity_ext(chunk);
    dvec3 off = dvec3_init(CHUNK_SIZE * 0.5, 0.0, CHUNK_SIZE * 0.5);

    add_grass_clusters(ent, off);
    for (size_t i = 0; i < 2048 * 16; i++) {
        vec2 uv = {randf(), randf()};
        dvec3 p = arr2d_dvec3_sample_linear(arr, uv);
        dvec3 norm = arr2d_dvec3_sample_linear(n, uv);
        if ((p.y < -40.0) || (norm.y < 0.8) ||
        (arr2d_dvec3_sample_linear(n,
        vec2_add(uv, (vec2){0.01f, 0.01f})).y < 0.8) ||
        (arr2d_dvec3_sample_linear(n,
        vec2_add(uv, (vec2){-0.01f, -0.01f})).y < 0.8))
            continue;
        set_grass_elem(ent, uv, p, norm);
    }
}
