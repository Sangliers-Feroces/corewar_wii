/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "headers.h"

int32_t vm_mem_ref_read(vm_mem_ref_t ref)
{
    switch (ref.type) {
    case VM_MEM_REF_MAIN:
        return *((int32_t*)ref.ptr);
    case VM_MEM_REF_VM_ABS:
        if (ref.is_short)
            return (int16_t)vm_read_uint16(ref.ptr);
        else
            return vm_read_uint32(ref.ptr);
    case VM_MEM_REF_VM_REL:
        if (ref.is_short)
            return (int16_t)vm_read_uint16(
            _vm.prog_running->op.pc + ref.ptr % PTR_RANGE);
        else
            return vm_read_uint32(_vm.prog_running->op.pc + ref.ptr % PTR_RANGE);
    default:
        return 0;
    }
}

void vm_mem_ref_write(vm_mem_ref_t ref, int32_t value)
{
    switch (ref.type) {
    case VM_MEM_REF_MAIN:
        *((int32_t*)ref.ptr) = value;
        break;
    case VM_MEM_REF_VM_ABS:
        if (ref.is_short)
            return vm_write_uint16(ref.ptr, value);
        else
            return vm_write_uint32(ref.ptr, value);
    case VM_MEM_REF_VM_REL:
        if (ref.is_short)
            return vm_write_uint16(
            _vm.prog_running->op.pc + ref.ptr % PTR_RANGE, value);
        else
            return vm_write_uint32(
            _vm.prog_running->op.pc + ref.ptr % PTR_RANGE, value);
    }
}

int32_t vm_mem_ref_read_nomod(vm_mem_ref_t ref)
{
    switch (ref.type) {
    case VM_MEM_REF_MAIN:
        return *((int32_t*)ref.ptr);
    case VM_MEM_REF_VM_ABS:
        if (ref.is_short)
            return (int16_t)vm_read_uint16(ref.ptr);
        else
            return vm_read_uint32(ref.ptr);
    case VM_MEM_REF_VM_REL:
        if (ref.is_short)
            return (int16_t)vm_read_uint16(_vm.prog_running->op.pc + ref.ptr);
        else
            return vm_read_uint32(_vm.prog_running->op.pc + ref.ptr);
    default:
        return 0;
    }
}

void vm_mem_ref_write_nomod(vm_mem_ref_t ref, int32_t value)
{
    switch (ref.type) {
    case VM_MEM_REF_MAIN:
        *((int32_t*)ref.ptr) = value;
        break;
    case VM_MEM_REF_VM_ABS:
        if (ref.is_short)
            return vm_write_uint16(ref.ptr, value);
        else
            return vm_write_uint32(ref.ptr, value);
    case VM_MEM_REF_VM_REL:
        if (ref.is_short)
            return vm_write_uint16(
            _vm.prog_running->op.pc + ref.ptr, value);
        else
            return vm_write_uint32(
            _vm.prog_running->op.pc + ref.ptr, value);
    }
}

vm_mem_ref_t vm_mem_ref_init_rel(int32_t offset)
{
    vm_mem_ref_t res = {VM_MEM_REF_VM_REL, offset, 0};

    return res;
}
