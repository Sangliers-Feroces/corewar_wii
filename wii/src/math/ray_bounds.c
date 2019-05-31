/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** optiiiiiii rtx
*/

#include "headers.h"

/* this code checks whether a 3D ray will go or not trough a cube.      */
/* it does use 1D rays to check that, so i guess it could be used for   */
/* any dimension rays / boundaries                                      */

static int ray1d_bound_inside(ray1 r, double min, double max, dvec2 *t)
{
    if (r.v < 0.0f) {
        t->x = MAX(t->x, (max - r.p) / r.v);
        t->y = MIN(t->y, (min - r.p) / r.v);
    } else {
        t->x = MAX(t->x, (min - r.p) / r.v);
        t->y = MIN(t->y, (max - r.p) / r.v);
    }
    return 1;
}

static int ray1d_bound(ray1 r, double min, double max, dvec2 *t)
{
    if (r.v == 0.0f)
        return ((r.p >= min) && (r.p < max));
    if (r.p < min) {
        t->x = MAX(t->x, (min - r.p) / r.v);
        t->y = MIN(t->y, (max - r.p) / r.v);
        return (r.v > 0.0f);
    } else if (r.p >= max) {
        t->x = MAX(t->x, (max - r.p) / r.v);
        t->y = MIN(t->y, (min - r.p) / r.v);
        return (r.v < 0.0f);
    } else
        return ray1d_bound_inside(r, min, max, t);
}

int ray_is_in_bounds(ray3 ray, bounds3 bounds)
{
    dvec2 t = {-FLT64_INF, FLT64_INF};

    for (size_t i = 0; i < 3; i++) {
        if (!ray1d_bound((ray1){((double*)&ray.p)[i], ((double*)&ray.v)[i]},
        ((double*)&bounds.min)[i], ((double*)&bounds.max)[i], &t))
            return 0;
    }
    return (t.x <= t.y);
}

int ray_is_in_bounds_seg(ray3 ray, dvec3 b_min, dvec3 b_max)
{
    dvec2 t = {-FLT64_INF, FLT64_INF};

    for (size_t i = 0; i < 3; i++) {
        if (!ray1d_bound((ray1){((double*)&ray.p)[i], ((double*)&ray.v)[i]},
        ((double*)&b_min)[i], ((double*)&b_max)[i], &t))
            return 0;
    }
    return (t.x <= t.y) && (t.y >= 0.0) && (t.x <= 1.0);
}
