/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

mesh_full_ref_t mesh_full_ref_init(mesh_full_ref_type_t ref_type,
mesh_full_t *m)
{
    mesh_full_ref_t res;

    res.ref_type = ref_type;
    res.bank = MESH_BANK_MAX;
    res.m = m;
    return res;
}

mesh_full_ref_t mesh_full_ref_bank_init(mesh_bank_t bank)
{
    mesh_full_ref_t res;

    res.ref_type = MESH_FULL_REF_BANK;
    res.bank = bank;
    res.m = _demo->mesh_bank[bank];
    return res;
}

mesh_full_ref_t mesh_full_ref_get_null(void)
{
    return mesh_full_ref_init(MESH_FULL_REF_STANDALONE, NULL);
}

mesh_full_ref_t entity3_get_lod_ref(entity3 *ent, size_t lod)
{
    return mesh_full_ref_init(MESH_FULL_REF_RENDER_LOD0 + lod,
    ent->render[lod].mesh.m);
}
