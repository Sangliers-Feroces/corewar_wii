/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__ls
** File description:
** str fun
*/

#include <stdlib.h>
#include <unistd.h>

size_t my_strlen(const char *str)
{
    size_t i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

void my_putchar_fd(int fd, char to_print)
{
    write(fd, &to_print, 1);
}

void my_putchar(char to_print)
{
    my_putchar_fd(1, to_print);
}

void my_putstr_fd(int fd, const char *str)
{
    write(fd, str, my_strlen(str));
}

void my_putstr(const char *str)
{
    my_putstr_fd(1, str);
}
