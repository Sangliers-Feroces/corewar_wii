/*
** EPITECH PROJECT, 2019
** str
** File description:
** str
*/

#include "str.h"

int my_strlen(const char *src)
{
    size_t i;

    for (i = 0; src[i] != '\0'; i++);
    return i;
}

void my_fd_putstr(const char *src, int fd)
{
    write(fd, src, my_strlen(src));
}

void my_fd_putchar(char c, int fd)
{
    write(fd, &c, 1);
}

void my_putstr(const char *src)
{
    my_fd_putstr(src, 1);
}

void my_putchar(char c)
{
    my_fd_putchar(c, 1);
}