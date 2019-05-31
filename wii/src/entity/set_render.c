/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

render_obj_t render_obj_get_default(void)
{
    render_obj_t res;

    res.mesh = mesh_full_ref_get_null();
    res.material = MATERIAL_MAX;
    return res;
}

void render_obj_destroy(render_obj_t render)
{
    if (render.mesh.ref_type != MESH_FULL_REF_STANDALONE)
        return;
    if (render.mesh.m == NULL)
        return;
    mesh_full_destroy(render.mesh.m);
}

void entity3_set_render(entity3 *ent, size_t lod, mesh_full_ref_t mesh,
material_t material)
{
    if (!(lod < (size_t)WORLD_LOD_COUNT)) {
        printf("Error: oob lod (got %zu).\n", lod);
        exit(84);
    }
    ent->render[lod].mesh = mesh;
    ent->render[lod].material = material;
}

mesh_full_t* entity3_create_render(entity3 *ent, size_t lod,
material_t material, int has_ext)
{
    mesh_full_t *mesh;

    if (!(lod < (size_t)WORLD_LOD_COUNT)) {
        printf("Error: oob lod (got %zu).\n", lod);
        exit(84);
    }
    if ((ent->render[lod].mesh.m != NULL) &&
    (ent->render[lod].mesh.ref_type == MESH_FULL_REF_STANDALONE))
        printf("Warning: overwriting standalone rendering geometry.\n");
    render_obj_destroy(ent->render[lod]);
    mesh = mesh_full_create(1, has_ext);
    ent->render[lod].mesh = mesh_full_ref_init(MESH_FULL_REF_STANDALONE, mesh);
    ent->render[lod].material = material;
    return mesh;
}
