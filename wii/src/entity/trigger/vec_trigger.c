/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

vec_trigger_t vec_trigger_init(void)
{
    vec_trigger_t res;

    res.count = 0;
    res.allocated = 0;
    res.trigger = NULL;
    return res;
}

void vec_trigger_add(vec_trigger_t *vec, trigger_t *trigger)
{
    size_t cur = vec->count++;

    if (vec->count > vec->allocated) {
        vec->allocated += 32;
        vec->trigger = (trigger_t**)realloc(vec->trigger,
        vec->allocated * sizeof(trigger_t*));
    }
    vec->trigger[cur] = trigger;
    trigger->ndx = cur;
}

void vec_trigger_destroy(vec_trigger_t *vec)
{
    free(vec->trigger);
    vec->trigger = NULL;
    vec->count = 0;
    vec->allocated = 0;
}

void entity3_add_trigger(entity3 *ent, trigger_t *trigger)
{
    if (trigger == NULL)
        return;
    if (ent->trigger != NULL) {
        printf("Error: this entity has already a trigger.\n");
        exit(84);
    }
    ent->trigger = trigger;
    trigger->ent = ent;
    trigger_attach(ent->trigger);
}
