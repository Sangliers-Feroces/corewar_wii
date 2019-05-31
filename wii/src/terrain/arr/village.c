/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static int is_pos_valid(dvec3 pos)
{
    return (pos.x > 0.1 * CHUNK_SIZE) && (pos.y < 0.9 * CHUNK_SIZE) &&
    (pos.z > 0.1 * CHUNK_SIZE) && (pos.z < 0.9 * CHUNK_SIZE) && (pos.y > -40.0);
}

static void add_chalet(chunk_t *chunk, dvec3 p, dvec3 norm)
{
    entity3 *ent;

    (void)norm;
    if (!is_pos_valid(p))
        return;
    ent = chunk_add_entity(chunk);
    ent->trans.pos = p;
    ent->trans.rot.y = randf() * M_PI;
    entity3_set_render(ent, 1, mesh_full_ref_bank_init(MESH_BANK_CASA_L1),
    MATERIAL_WOOD);
    ent->trans.scale = dvec3_init(0.1, 0.1, 0.1);
    entity3_bind_col(ent,
    entity3_get_lod_ref(ent, MESH_FULL_REF_RENDER_LOD1));
    ent->lod_dist = RENDER_OBJ_LOD_DIST_FAR;
    entity3_trans_update(ent);
}

static void add_vill_ent_at(chunk_t *chunk, arr2d_dvec3_t arr,
arr2d_dvec3_t n, vec2 uv)
{
    size_t size = rand() % 8;
    vec2 uv_a;

    for (size_t i = 0; i < size; i++) {
        uv_a = vec2_add(uv, (vec2){randfn() / 10.0, (double)i / 30.0});
        add_chalet(chunk, arr2d_dvec3_sample_linear(arr, uv_a),
        arr2d_dvec3_sample_linear(n, uv_a));
        uv_a = vec2_add(uv, (vec2){randfn() / 10.0, (double)i / 30.0});
        chunk_add_npc(chunk, arr2d_dvec3_sample_linear(arr, uv_a));
    }
}

void chunk_add_village(chunk_t *chunk, arr2d_dvec3_t arr, arr2d_dvec3_t n)
{
    if ((rand() % 4) != 0)
        return;
    for (size_t i = 0; i < 64; i++) {
        vec2 uv = {randf(), randf()};
        dvec3 p = arr2d_dvec3_sample_linear(arr, uv);
        dvec3 norm = arr2d_dvec3_sample_linear(n, uv);
        if ((norm.y < 0.82) || (p.y < -40.0))
            continue;
        add_vill_ent_at(chunk, arr, n, uv);
        break;
    }
}
