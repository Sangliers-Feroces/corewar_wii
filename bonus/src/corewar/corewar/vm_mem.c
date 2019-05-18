/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "headers.h"

int32_t vm_mem_ref_read(vm_mem_ref_t ref)
{
    if (ref.type == VM_MEM_REF_VM) {
        if (ref.is_short)
            return vm_read_uint16(ref.ptr);
        else
            return vm_read_uint32(ref.ptr);
    } else
        return *((int32_t*)ref.ptr);
}

void vm_mem_ref_write(vm_mem_ref_t ref, int32_t value)
{
    if (ref.type == VM_MEM_REF_VM) {
        if (ref.is_short)
            return vm_write_uint16(ref.ptr, value);
        else
            return vm_write_uint32(ref.ptr, value);
    } else
        *((int32_t*)ref.ptr) = value;
}
