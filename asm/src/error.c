/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

const char *udoc = "well that is an undocumented error.\n"
"Contact me ASAP (adrien.lenglet@epitech.eu) or just place "
"a breakpoint with GDB to understand where your ASM code died";

void error_exit(const char *err)
{
    my_putstr_fd(2, "WOAH: ");
    if (err == NULL)
        my_putstr_fd(2, udoc);
    else
        my_putstr_fd(2, err);
    my_putstr_fd(2, "\n");
    exit(84);
}

void error_mul_exit(const char *first, const char *err)
{
    my_putstr_fd(2, "WOAH: ");
    my_putstr_fd(2, first);
    my_putstr_fd(2, ": ");
    if (err == NULL)
        my_putstr_fd(2, udoc);
    else
        my_putstr_fd(2, err);
    my_putstr_fd(2, "\n");
    exit(84);
}

void err_gen_line(const char *msg, size_t line, const char *err,
const char *bonus)
{
    my_putstr_fd(2, msg);
    my_putstr_fd(2, ": Line ");
    strerr_num(line);
    my_putstr_fd(2, ": ");
    if (err == NULL)
        my_putstr_fd(2, udoc);
    else
        my_putstr_fd(2, err);
    if (bonus != NULL) {
        my_putstr_fd(2, " (");
        my_putstr_fd(2, bonus);
        my_putstr_fd(2, ")");
    }
    my_putstr_fd(2, "\n");
}

void error_line_exit(size_t line, const char *err,
const char *bonus)
{
    err_gen_line("WOAH", line, err, bonus);
    exit(84);
}

void warning_line(size_t line, const char *err,
const char *bonus)
{
    err_gen_line("Warning", line, err, bonus);
}
