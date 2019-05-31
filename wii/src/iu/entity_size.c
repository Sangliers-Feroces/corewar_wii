/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** iu_entity_size
*/

#include "headers.h"

static rect_t get_x_size(entity2_t entity)
{
    vec2 size_ac = _iu.textures[entity.index]->size;
    float ratio = _iu.textures[entity.index]->size.x /
    _iu.textures[entity.index]->size.y;

    size_ac = vec2_divs(size_ac, _iu.textures[entity.index]->size.y);
    size_ac.x /= ratio;
    size_ac.y *= _iu.data.ratiowh / ratio;
    return (rect_t){entity.rect.p, vec2_muls(size_ac, entity.rect.s.x)};
}

static rect_t get_y_size(entity2_t entity)
{
    vec2 size_ac = _iu.textures[entity.index]->size;

    size_ac = vec2_divs(size_ac, _iu.textures[entity.index]->size.y);
    size_ac.x /= _iu.data.ratiowh;
    return (rect_t){entity.rect.p, vec2_muls(size_ac, entity.rect.s.y)};
}

rect_t entity_get_size(entity2_t entity)
{
    if (entity.rel == IUREL_X)
        return get_x_size(entity);
    else if (entity.rel == IUREL_Y)
        return get_y_size(entity);
    else
        return entity.rect;
}