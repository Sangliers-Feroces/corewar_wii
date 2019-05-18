/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

entity3* entity3_create_pos(entity3 *parent, dvec3 pos)
{
    entity3 *res = (entity3*)malloc_safe(sizeof(entity3));

    res->trans = transform_get_default();
    res->trans.pos = pos;
    res->col = col_ref_get_default();
    for (size_t i = 0; i < WORLD_LOD_COUNT; i++)
        res->render[i] = render_obj_get_default();
    res->lod_dist = RENDER_OBJ_LOD_DIST_NEAR;
    res->render_is_rec = 0;
    res->trigger = NULL;
    res->tag = ENTITY3_TAG_NONE;
    res->tag_data = NULL;
    res->root = NULL;
    entity3_trans_update(res);
    res->root_ndx = ~0UL;
    res->sub = vec_entity3_create();
    if (parent != NULL)
        entity3_set_child(parent, res);
    return res;
}

entity3* entity3_create(entity3 *parent)
{
    return entity3_create_pos(parent, dvec3_init(0.0, 0.0, 0.0));
}

void entity3_destroy(entity3 *entity)
{
    while (entity->sub.count > 0)
        entity3_destroy(entity->sub.ent[0]);
    vec_entity3_destroy(entity->sub);
    entity3_set_col(entity, 0);
    for (size_t i = 0; i < WORLD_LOD_COUNT; i++)
        render_obj_destroy(entity->render[i]);
    free(entity->tag_data);
    trigger_destroy(entity->trigger);
    entity3_remove_from_parent(entity);
    free(entity);
}
