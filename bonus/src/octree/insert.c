/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** optiiiiiii rtx
*/

#include "headers.h"

/* triangle insertion: */
/* -1 check if the triangle fits in a subtree, if so try to go as deep as    */
/* possible (as long as the triangle fits in the node's boundaries)          */
/* -2 doesn't fit ? then maybe the triangle fits in the current node. try it.*/
/* -3 the triangle is not in the tree's boundaries, so enlarge the tree      */
/* till we grab that triangle                                                */

/* NOTE: i'm pretty sure this logic can be applied for quadtrees or */
/* any dimension tree                                               */

static void check_node_presence(octree **node, octree *root, bounds3 bounds)
{
    if ((*node) == NULL)
        *node = octree_create_node(root, bounds);
}

static int try_insert_sub(octree **tree, rtx_triangle *triangle)
{
    bounds3 sub_b;

    for (size_t i = 0; i < 8; i++) {
        sub_b = octree_get_sub_bounds(*tree, i);
        if (is_triangle_in_bounds(triangle->vertex, sub_b)) {
            check_node_presence(&((*tree)->sub[i]), *tree, sub_b);
            octree_insert_triangle(&((*tree)->sub[i]), triangle);
            return 1;
        }
    }
    return 0;
}

static int try_insert_cur(octree **tree, rtx_triangle *triangle)
{
    if (is_triangle_in_bounds(triangle->vertex, (*tree)->bounds)) {
        vec_rtx_triangle_add((*tree)->triangles, triangle);
        return 1;
    } else
        return 0;
}

static void octree_insert_triangle_actual(octree **tree,
rtx_triangle *triangle)
{
    while (1) {
        if (try_insert_sub(tree, triangle))
            return;
        else if (try_insert_cur(tree, triangle))
            return;
        octree_enlarge(tree, triangle);
    }
}

rtx_triangle* octree_insert_triangle(octree **tree, rtx_triangle *triangle)
{
    octree_insert_triangle_actual(tree, triangle);
    return triangle;
}
