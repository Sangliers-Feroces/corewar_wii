/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** bitwise stuff
*/

#include "headers.h"

/* some functions to get subtree's boundaries even if those are not  */
/* allocated.                                                        */
/* useful to locate a new triangle deeper and deeper in the octree,  */
/* this result is also used to create subtree's attributes           */

static bounds3 move_sub_adequate(bounds3 res, size_t ndx, float sizeh)
{
    if (ndx & 0x1) {
        res.min.x += sizeh;
        res.max.x += sizeh;
    }
    if (ndx & 0x2) {
        res.min.y += sizeh;
        res.max.y += sizeh;
    }
    if (ndx & 0x4) {
        res.min.z += sizeh;
        res.max.z += sizeh;
    }
    return (res);
}

bounds3 octree_get_sub_bounds(octree *tree, size_t ndx)
{
    bounds3 b;
    bounds3 res;
    float sizeh;

    if (tree->sub[ndx] != NULL)
        return tree->sub[ndx]->bounds;
    b = tree->bounds;
    sizeh = tree->bounds.size * 0.5f;
    res = (bounds3){b.min,
    {b.max.x - sizeh, b.max.y - sizeh, b.max.z - sizeh}, sizeh};
    return move_sub_adequate(res, ndx, sizeh);
}
