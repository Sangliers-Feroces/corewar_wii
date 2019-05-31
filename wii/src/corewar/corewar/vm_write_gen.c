/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "headers.h"

void vm_write_uint8(size_t ptr, uint8_t value)
{
    _vm.mem[ptr % VM_SIZE] = value;
    _vm.owner[ptr % VM_SIZE] = _vm.prog_running->id;
}

void vm_write_uint16(size_t ptr, uint16_t value)
{
    for (size_t i = 0; i < 2; i++)
        vm_write_uint8(ptr + i, ((uint8_t*)&value)[i]);
}

void vm_write_uint32(size_t ptr, uint32_t value)
{
    for (size_t i = 0; i < 4; i++)
        vm_write_uint8(ptr + i, ((uint8_t*)&value)[i]);
}
