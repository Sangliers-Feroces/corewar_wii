/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "headers.h"

uint8_t vm_read_uint8(size_t ptr)
{
    return _vm.mem[ptr % VM_SIZE];
}

uint16_t vm_read_uint16(size_t ptr)
{
    uint16_t res = 0;

    for (size_t i = 0; i < 2; i++)
        ((uint8_t*)&res)[i] = vm_read_uint8(ptr + i);
    return swap16(res);
}

uint32_t vm_read_uint32(size_t ptr)
{
    uint32_t res = 0;

    for (size_t i = 0; i < 4; i++)
        ((uint8_t*)&res)[i] = vm_read_uint8(ptr + i);
    return swap32(res);
}
