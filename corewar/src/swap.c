/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "header.h"

void swap16(void *value)
{
    int16_t buf;
    int16_t valueBuf = *((int16_t *)value);

    buf = (valueBuf&0xFF) << 8 | (valueBuf&0xFF00) >> 8;
    *((int16_t *)value) = buf;
}

void swap32(void *value)
{
    int32_t buf;
    int32_t valueBuf = *((int32_t *)value);

    buf = (valueBuf&0xFF) << 24 | (valueBuf&0xFF00) << 8 |
    (valueBuf&0xFF0000) >> 8 | (valueBuf&0xFF000000) >> 24;
    *((int32_t *)value) = buf;
}

void swap64(void *value)
{
    size_t i = 0;
    int64_t buf = 0;
    int64_t valueBuf = *((int64_t *)value);

    for (i = 0; i < 8; i++)
        buf |= ((valueBuf >> i) & 0xFF) << (7 - i);
    *((int32_t *)value) = buf;
}
