/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include <stdlib.h>
#include <unistd.h>

size_t my_strlen(const char *str)
{
    size_t i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

int strcmp_c(char *str1, char *str2)
{
    for (int i = 0; ;i++) {
        if (str1[i] == 0 && str2[i] == 0)
            return 1;
        if (str1[i] != str2[i])
            return 0;
    }
}

void my_putstr_fd(int fd, const char *str)
{
    write(fd, str, my_strlen(str));
}

void my_putstr(const char *str)
{
    my_putstr_fd(1, str);
}
