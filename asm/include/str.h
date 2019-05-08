/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** headaaaas
*/

#pragma once

size_t my_strlen(const char *str);
void my_putchar_fd(int fd, char to_print);
void my_putchar(char to_print);
void my_putstr_fd(int fd, const char *str);
void my_putstr(const char *str);

void strout_num_adv(FILE *file, size_t value, size_t base, int is_caps);
void strout_num(size_t value);
void strerr_num(size_t value);

void memcpy_slow(void *dst, const void *src, size_t size);
