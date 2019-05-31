/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** headaaaas
*/

#pragma once

void error_exit(const char *err);
void error_mul_exit(const char *first, const char *err);
void err_gen_line(const char *msg, size_t line, const char *err,
const char *bonus);
void error_line_exit(size_t line, const char *err,
const char *bonus);
void warning_line(size_t line, const char *err,
const char *bonus);
