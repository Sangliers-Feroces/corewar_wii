/*
** EPITECH PROJECT, 2019
** nbr_tools
** File description:
** nbr_tools
*/

#pragma once

#include <stdlib.h>

#include "str.h"

#define CTI(x) ((x) - '0')
#define ITC(x) ((x) + '0')

int my_char_isnum(char *str);
int my_isnum(char c, int sign);
int my_pow(size_t a, size_t b);
int nbr_len(size_t c, int accept_0);

//my_getnbr
int my_getnbr(const char *src);

//putnbr
void putnbr(size_t value, int base, int caps);
