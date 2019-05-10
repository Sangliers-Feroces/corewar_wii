/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

str_sep_data_t str_sep_data_init(void)
{
    str_sep_data_t res;

    res.start = 0;
    res.is_quote = 0;
    res.is_last_sep = 0;
    return res;
}
