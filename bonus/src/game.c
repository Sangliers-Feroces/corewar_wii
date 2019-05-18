/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** main
*/

#include "headers.h"

static void add_triangle(octree **tree, dvec3 *triangle)
{
    rtx_triangle *rtx = rtx_triangle_create(triangle);

    octree_insert_triangle(tree, rtx);
}

static void load_model_ext(octree **tree, float h)
{
    add_triangle(tree, (dvec3[]){{0.0f, 3.0f - h, 0.0f},
    {10.0f, 3.0f - h, 0.0f}, {0.0f, 3.0f - h, 5.0f}});
    add_triangle(tree, (dvec3[]){{0.0f, 3.0f - h, 5.0f},
    {10.0f, 3.0f - h, 0.0f}, {10.0f, 3.0f - h, 5.0f}});
    add_triangle(tree, (dvec3[]){{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 5.0f},
    {10.0f, 0.0f, 0.0f}});
    add_triangle(tree, (dvec3[]){{0.0f, 0.0f, 5.0f}, {10.0f, 0.0f, 5.0f},
    {10.0f, 0.0f, 0.0f}});
    add_triangle(tree, (dvec3[]){{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 5.0f},
    {0.0f, 3.0f - h, 5.0f}});
    add_triangle(tree, (dvec3[]){{0.0f, 3.0f - h, 5.0f}, {0.0f, 3.0f - h, 0.0f},
    {0.0f, 0.0f, 0.0f}});
    add_triangle(tree, (dvec3[]){{0.0f, 0.0f, 0.0f},
    {0.0f, 3.0f - h, 5.0f}, {0.0f, 0.0f, 5.0f}});
    add_triangle(tree, (dvec3[]){{0.0f, 3.0f - h, 5.0f},
    {0.0f, 0.0f, 0.0f}, {0.0f, 3.0f - h, 0.0f}});
    add_triangle(tree, (dvec3[]){{10.0f, 0.0f, 0.0f}, {10.0f, 0.0f, 5.0f},
    {10.0f, 3.0f - h, 5.0f}});
    add_triangle(tree, (dvec3[]){{10.0f, 3.0f - h, 5.0f},
    {10.0f, 3.0f - h, 0.0f}, {10.0f, 0.0f, 0.0f}});
}

void load_model(octree **tree)
{
    float h = 0.0f;

    add_triangle(tree, (dvec3[]){{0.0f, 0.0f, 5.0f},
    {0.0f, 3.0f - h, 5.0f}, {10.0f, 0.0f, 5.0f}});
    add_triangle(tree, (dvec3[]){{0.0f, 3.0f - h, 5.0f},
    {10.0f, 3.0f - h, 5.0f}, {10.0f, 0.0f, 5.0f}});
    add_triangle(tree, (dvec3[]){{0.0f, 0.0f, 0.0f},
    {0.0f, 1.0f, 0.0f}, {10.0f, 0.0f, 0.0f}});
    add_triangle(tree, (dvec3[]){{0.0f, 1.0f, 0.0f}, {10.0f, 1.0f, 0.0f},
    {10.0f, 0.0f, 0.0f}});
    add_triangle(tree, (dvec3[]){{0.0f, 2.0f, 0.0f},
    {0.0f, 3.0f - h, 0.0f}, {10.0f, 2.0f, 0.0f}});
    add_triangle(tree, (dvec3[]){{0.0f, 3.0f - h, 0.0f},
    {10.0f, 3.0f - h, 0.0f}, {10.0f, 2.0f, 0.0f}});
    add_triangle(tree, (dvec3[]){{0.0f, 3.0f - h, 0.0f},
    {0.0f, 3.0f - h, 5.0f}, {10.0f, 3.0f - h, 0.0f}});
    add_triangle(tree, (dvec3[]){{0.0f, 3.0f - h, 5.0f},
    {10.0f, 3.0f - h, 5.0f}, {10.0f, 3.0f - h, 0.0f}});
    load_model_ext(tree, h);
}

int main(int argc, char **argv)
{
    arg_t args = {32.0f, 8, 0.28f};
    int mode_dev = 0;

    if (argc > 1) {
        if (strcmp(argv[1], "-h") == 0) {
            display_helper();
            return 0;
        }
        else if (strcmp(argv[1], "-D") == 0)
            mode_dev = 1;
    }
    demo(args, mode_dev);
    return (EXIT_SUCCESS);
}

void display_helper(void)
{
    int len;
    int fd;
    char buff[10000];

    fd = open("readme.md", O_RDONLY);
    len = read(fd, buff, 4000);
    buff[len] = '\0';
    my_putstr(buff);
}
