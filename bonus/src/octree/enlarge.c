/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** ( ͡° ͜ʖ ͡°)
*/

#include "headers.h"

/* some functions called when a triangle can't fit in the absolute root */
/* of an octree.                                                        */
/* the point is to make the current root as a node of a bigger root.    */
/* two possibilities: the tree grows towards positive space or towards  */
/* negative space.                                                      */

static void enlarge_get_bounds(octree *new_root, bounds3 old_b, size_t ndx)
{
    new_root->bounds.size = old_b.size * 2.0f;
    if (ndx == 0) {
        new_root->bounds.min = old_b.min;
        new_root->bounds.max =
        (dvec3){new_root->bounds.min.x + new_root->bounds.size,
        new_root->bounds.min.y + new_root->bounds.size,
        new_root->bounds.min.z + new_root->bounds.size};
    } else {
        new_root->bounds.max = old_b.max;
        new_root->bounds.min =
        (dvec3){new_root->bounds.max.x - new_root->bounds.size,
        new_root->bounds.max.y - new_root->bounds.size,
        new_root->bounds.max.z - new_root->bounds.size};
    }
}

void octree_enlarge(octree **tree, rtx_triangle *triangle)
{
    octree *new_root = octree_create(NULL);
    size_t ndx;

    ndx = get_triangle_upper_tree(triangle->vertex, (*tree)->bounds);
    enlarge_get_bounds(new_root, (*tree)->bounds, ndx);
    (*tree)->root = new_root;
    new_root->sub[ndx] = *tree;
    *tree = new_root;
}
