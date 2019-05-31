/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static void add_water(chunk_t *chunk, vec2 *uv)
{
    mesh_full_t *mesh;
    vec3 base = {0.0, -42.0f, 0.0};
    vec3 sq[4];

    sq[0] = base;
    sq[1] = vec3_add(base, (vec3){CHUNK_SIZE, 0.0f, 0.0f});
    sq[2] = vec3_add(base, (vec3){0.0f, 0.0f, CHUNK_SIZE});
    sq[3] = vec3_add(base, (vec3){CHUNK_SIZE, 0.0f, CHUNK_SIZE});
    entity3 *water = chunk_add_entity(chunk);
    mesh = entity3_create_render(water, 0, MATERIAL_WATER, 0);
    mesh_add_triangle_pos_uv(mesh->mesh, (vec3[]){sq[0], sq[2], sq[1]}, uv);
    mesh_add_triangle_pos_uv(mesh->mesh, (vec3[]){sq[3], sq[1], sq[2]}, uv);
}

static void ensure_terrain(chunk_t *chunk)
{
    if (chunk->terrain == NULL) {
        chunk->terrain = chunk_add_entity(chunk);
        entity3_set_tag(chunk->terrain, ENTITY3_TAG_TERRAIN);
        chunk->terrain->lod_dist = RENDER_OBJ_LOD_DIST_FAR;
    }
}

void terrain_send_ter_to_chunk_lod_gen(chunk_t *chunk, size_t lod,
terrain_send_ter_arg arg, dvec3 chunk_rel)
{
    vec2 uv[3] = {{0.0f, 0.0f}, {1.0f, 0.0f}, {0.0f, 1.0f}};

    ensure_terrain(chunk);
    if (chunk->terrain->render[lod].mesh.m != NULL)
        return;
    terrain_send_ter_chunk(chunk, lod, arg, chunk_rel);
    if (lod == 1) {
        chunk->terrain_base = arr2d_dvec3_copy_rect(arg.arr, arg.area);
        arr2d_dvec3_sub(chunk->terrain_base, chunk_rel);
    }
    if ((lod == 1) && (chunk->terrain->col.mesh.m == NULL)) {
        entity3_update(chunk->ents);
        entity3_bind_col(chunk->terrain,
        entity3_get_lod_ref(chunk->terrain, 1));
    }
    if (lod == 0)
        add_water(chunk, uv);
}

static void send_ter_to_chunk_lod(size_t lod, ssize2 chunk_pos, ssize2 iter,
terrain_send_ter_arg arg)
{
    chunk_t *chunk = world_chunk_get_adv(chunk_pos, 0, 0);
    dvec3 chunk_rel = dvec3_init(iter.x * CHUNK_SIZE, 0.0, iter.y * CHUNK_SIZE);

    terrain_send_ter_to_chunk_lod_gen(chunk, lod, arg, chunk_rel);
}

void terrain_send_ter_to_chunks_lod(size_t lod, arr2d_dvec3_t arr,
arr2d_dvec3_t normals, ssize2 pos)
{
    ssize2 pos_first_chunk = ssize2_muls(pos, CHUNK_TERRAIN_SUB_SIZE);
    ssize_t step = (arr.w - 1) / CHUNK_TERRAIN_SUB_SIZE;

    for (size_t i = 0; i < CHUNK_TERRAIN_SUB_SIZE; i++)
        for (size_t j = 0; j < CHUNK_TERRAIN_SUB_SIZE; j++)
            send_ter_to_chunk_lod(lod, ssize2_add(pos_first_chunk,
            (ssize2){j, i}), (ssize2){j, i},
            (terrain_send_ter_arg){arr, normals,
            (srect){{j * step, i * step}, {step + 1, step + 1}}});
}
