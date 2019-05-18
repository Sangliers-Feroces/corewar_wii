/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static void mesh_full_refresh(mesh_full_t *mesh)
{
    if (mesh->has_ext) {
        if (mesh->gpu.do_reupload) {
            /*glBindBuffer(GL_ARRAY_BUFFER, mesh->gpu.vertex_buffer);
            glBufferData(GL_ARRAY_BUFFER,
            mesh->ext_count * sizeof(vertex_ext_t), mesh->ext, GL_STATIC_DRAW);*/
            mesh->gpu.do_reupload = 0;
        }
    }
    if (mesh->mesh->gpu.do_reupload) {
        free(mesh->mesh->gpu.disp_list);
        size_t size = 64 + mesh->mesh->vertex_count * sizeof(vertex_t);
        mesh->mesh->gpu.disp_list = memalign(32, size);
		memset(mesh->mesh->gpu.disp_list, 0, size);
		DCInvalidateRange(mesh->mesh->gpu.disp_list, size);
		GX_BeginDispList(mesh->mesh->gpu.disp_list, size);
		GX_Begin(GX_TRIANGLES, GX_VTXFMT0, mesh->mesh->vertex_count);
        for (size_t i = 0; i < mesh->mesh->vertex_count; i++) {
            vec3 p = mesh->mesh->vertex[i].pos;
			GX_Position3f32(p.x, p.y, p.z);
            vec3 n = mesh->mesh->vertex[i].normal;
            GX_Normal3f32(n.x, n.y, n.z);
            vec2 uv = mesh->mesh->vertex[i].uv;
            GX_TexCoord2f32(uv.x, uv.y);
        }
		GX_End();
		mesh->mesh->gpu.disp_list_size = GX_EndDispList();
		if (mesh->mesh->gpu.disp_list_size == 0)
            error_display("Error while refresing mesh (cannot end display list).");
        //else
        //    error_display("Mesh successfully refreshed.\n");
        mesh->mesh->gpu.do_reupload = 0;
    }
}

static void render_obj_draw(render_obj_t render, dmat4 world, dmat4 world_rot)
{
    dmat4 wv;
    Mtx wv_mtx;
    Mtx wv_rot_mtx;

    dmat4_mul(_demo->cam.mvp.view, world, wv);
    dmat4_Mtx(wv, wv_mtx);
    dmat4_Mtx(world_rot, wv_rot_mtx);
    GX_LoadPosMtxImm(wv_mtx, GX_PNMTX0);
    mesh_full_refresh(render.mesh.m);
    _demo->material[render.material].entity(wv, world, world_rot);
    GX_CallDispList(render.mesh.m->mesh->gpu.disp_list, render.mesh.m->mesh->gpu.disp_list_size);
    //error_display("Dsiplaying %d, size: %u", render.material, render.mesh.m->mesh->gpu.disp_list_size);
}

static size_t get_max_lod(render_obj_lod_dist_t lod, double dist)
{
    float dist2[RENDER_OBJ_LOD_DIST_MAX] = {384.0, 64.0, CHUNK_SIZE * 1.7,
    CHUNK_SIZE * 1.7 / 8.0};
    float dist1[RENDER_OBJ_LOD_DIST_MAX] = {768.0, 128.0, CHUNK_SIZE * 1.7,
    CHUNK_SIZE * 1.7 / 8.0};

    if (dist < (dist2[lod] * dist2[lod]))
        return 2;
    else if (dist < (dist1[lod] * dist1[lod]))
        return 1;
    else
        return 0;
}

static double get_ent_dist(entity3 *ent)
{
    dvec3 p = dmat4_trans(ent->trans.world);
    dvec3 c = dmat4_trans(_demo->world.camera->trans.world);

    return dvec3_dist_sq((dvec3){p.x, 0.0, p.z},
    (dvec3){c.x, 0.0, c.z});
}

void entity3_render(entity3 *ent, dmat4 vp)
{
    size_t max_lod = get_max_lod(ent->lod_dist, get_ent_dist(ent));
    size_t chosen = ~0UL;

    if ((max_lod == 0) && ent->render_is_rec)
        return;
    for (size_t i = 0; i < ent->sub.count; i++)
        entity3_render(ent->sub.ent[i], vp);
    for (size_t i = 0; i <= max_lod; i++)
        if (ent->render[i].mesh.m != NULL)
            chosen = i;
    if (chosen == ~0UL)
        return;
    render_obj_draw(ent->render[chosen], ent->trans.world, ent->trans.world_rot);
}
