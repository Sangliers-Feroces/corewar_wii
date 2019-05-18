/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** headaaaas
*/

#pragma once

size_t strlen_slow(const char *str);
void my_putchar_fd(int fd, char to_print);
void my_putchar(char to_print);
void my_putstr_fd(int fd, const char *str);
void my_putstr(const char *str);

void strout_num_adv(FILE *file, size_t value, size_t base, int is_caps);
void strout_num(size_t value);
void strerr_num(size_t value);

void memcpy_slow(void *dst, const void *src, size_t size);
void memset_slow(void *dst, uint8_t value, size_t count);
int streq(const char *a, const char *b);
char* strdup_slow(const char *to_dup);

size_t size_t_from_str(const char *src);

vec_str_t vec_str_init(void);
void vec_str_destroy(vec_str_t vec);
void vec_str_add(vec_str_t *vec, str_t to_add);
int vec_str_at(vec_str_t vec, size_t ndx, char **res);
str_t str_init(size_t size, const char *data);
char* str_to_c_str(str_t str);