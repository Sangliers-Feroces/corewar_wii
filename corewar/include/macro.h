/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** macros stuff !
*/

#pragma once

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define CLAMP(value, min, max) (MIN(MAX((value), (min)), (max)))

#define FLT32_INF (*((float*)(uint32_t[]){0x7F800000}))

#define INT_BITS_TO_FLOAT32(value) (*((float*)(int32_t[]){value}))
#define FLOAT32_BITS_TO_INT(value) (*((int32_t*)(float[]){value}))


#define FLT64_INF (*((double*)(uint64_t[]){0x7FF0000000000000}))

#define INT_BITS_TO_FLOAT64(value) (*((double*)(int64_t[]){value}))
#define FLOAT64_BITS_TO_INT(value) (*((int64_t*)(double[]){value}))


#define BUFFER_OFFSET(i) ((void*)i)
