/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

/* crazy local to world space / world to local space shenanigans        */
/* checks intersection between two triggers of any shape, in any entity */

static int is_line_in_trigger(dvec3 a, dvec3 b, trigger_t *trigger)
{
    ray3 ray;

    a = dmat4_mul_dvec3(trigger->ent->trans.world_inv, a);
    b = dmat4_mul_dvec3(trigger->ent->trans.world_inv, b);
    ray = (ray3){a, dvec3_sub(b, a)};
    return ray_is_in_bounds_seg(ray, trigger->min, trigger->max);
}

static int is_trigger_in_another(trigger_t *trigger, trigger_t *other)
{
    dvec3 p[8] = {
    {trigger->min.x, trigger->min.y, trigger->min.z},
    {trigger->max.x, trigger->min.y, trigger->min.z},
    {trigger->min.x, trigger->max.y, trigger->min.z},
    {trigger->max.x, trigger->max.y, trigger->min.z},
    {trigger->min.x, trigger->min.y, trigger->max.z},
    {trigger->max.x, trigger->min.y, trigger->max.z},
    {trigger->min.x, trigger->max.y, trigger->max.z},
    {trigger->max.x, trigger->max.y, trigger->max.z}};
    size_t to_test[12][2] = {
    {0, 1}, {2, 3}, {4, 5}, {6, 7},
    {0, 2}, {1, 3}, {4, 6}, {5, 7},
    {0, 4}, {1, 5}, {2, 6}, {3, 7}};

    for (size_t i = 0; i < 12; i++)
        if (is_line_in_trigger(
        dmat4_mul_dvec3(trigger->ent->trans.world, p[to_test[i][0]]),
        dmat4_mul_dvec3(trigger->ent->trans.world, p[to_test[i][1]]), other))
            return 1;
    return 0;
}

static int is_collision(trigger_t *trigger, trigger_t *other)
{
    entity3_update_trans_inv(trigger->ent);
    entity3_update_trans_inv(other->ent);
    return is_trigger_in_another(trigger, other) ||
    is_trigger_in_another(other, trigger);
}

void trigger_update(trigger_t *trigger)
{
    for (size_t i = 0; i < _demo->world.triggers.count; i++) {
        if (_demo->world.triggers.trigger[i] == trigger)
            continue;
        if (is_collision(trigger, _demo->world.triggers.trigger[i]))
            _demo->world.trigger_on_hit[
            _demo->world.triggers.trigger[i]->on_hit](
            _demo->world.triggers.trigger[i]->ent, trigger->ent);
    }
}

void world_update_triggers(void)
{
    return;
    for (size_t i = 0; i < _demo->world.triggers.count; i++)
        if (_demo->world.triggers.trigger[i]->on_hit != TRIGGER_ON_HIT_NONE)
            trigger_update(_demo->world.triggers.trigger[i]);
}
