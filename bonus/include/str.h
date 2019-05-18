/*
** EPITECH PROJECT, 2019
** str
** File description:
** str
*/

#pragma once

#include <stdio.h>
#include <unistd.h>

#define ALL_WORD 0
/* ---> Basics <--- */
int my_strlen(const char *src);
void my_fd_putstr(const char *src, int fd);
void my_fd_putchar(char c, int fd);
void my_putstr(const char *src);
void my_putchar(char c);

/* ---> Advanced <--- */
int my_strcpy(const char *src, char **pres, size_t n);
int my_strcmp(const char *s1, const char *s2, size_t n);
