/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

#include "headers.h"

static void live(prog_t *prog)
{
    int32_t id = vm_mem_ref_read(prog->op.arg[0]);

    for (size_t i = 0; i < _vm.progs.count; i++)
        if (_vm.progs.prog[i].id == id)
            _vm.progs.prog[i].life = 0;
}

static void ld(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read(prog->op.arg[0]);

    prog->carry = (arg0_val == 0);
    vm_mem_ref_write(prog->op.arg[1], arg0_val);
}

static void st(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read(prog->op.arg[0]);

    vm_mem_ref_write(prog->op.arg[1], arg0_val);
}

static void add(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read(prog->op.arg[0]);
    int32_t arg1_val = vm_mem_ref_read(prog->op.arg[1]);

    prog->carry = (arg0_val + arg1_val) == 0;
    vm_mem_ref_write(prog->op.arg[2], (arg0_val + arg1_val));
}

static void sub(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read(prog->op.arg[0]);
    int32_t arg1_val = vm_mem_ref_read(prog->op.arg[1]);

    prog->carry = (arg0_val - arg1_val) == 0;
    vm_mem_ref_write(prog->op.arg[2], (arg0_val - arg1_val));
}

static void and(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read(prog->op.arg[0]);
    int32_t arg1_val = vm_mem_ref_read(prog->op.arg[1]);

    prog->carry = (arg0_val & arg1_val) == 0;
    vm_mem_ref_write(prog->op.arg[2], (arg0_val & arg1_val));
}

static void or(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read(prog->op.arg[0]);
    int32_t arg1_val = vm_mem_ref_read(prog->op.arg[1]);

    prog->carry = (arg0_val | arg1_val) == 0;
    vm_mem_ref_write(prog->op.arg[2], (arg0_val | arg1_val));
}

static void xor(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read(prog->op.arg[0]);
    int32_t arg1_val = vm_mem_ref_read(prog->op.arg[1]);

    prog->carry = (arg0_val ^ arg1_val) == 0;
    vm_mem_ref_write(prog->op.arg[2], (arg0_val ^ arg1_val));
}

static void zjmp(prog_t *prog)
{
    int32_t index = (vm_mem_ref_read(prog->op.arg[0]) % PTR_RANGE);

    prog->op.pc = index;
}

static void ldi(prog_t *prog)
{
    int32_t s =
    vm_mem_ref_read(prog->op.arg[0]) + vm_mem_ref_read(prog->op.arg[1]);
    int32_t res = vm_mem_ref_read(vm_mem_ref_init_rel(s));

    prog->carry = (res == 0);
    vm_mem_ref_write(prog->op.arg[2], res);
}

static void sti(prog_t *prog)
{
    int32_t s =
    vm_mem_ref_read(prog->op.arg[0]) + vm_mem_ref_read(prog->op.arg[1]);
    int32_t res = vm_mem_ref_read(vm_mem_ref_init_rel(s));

    vm_mem_ref_write(prog->op.arg[2], res);
}

static void lld(prog_t *prog)
{
    int32_t arg0_val = vm_mem_ref_read_nomod(prog->op.arg[0]);

    prog->carry = (arg0_val == 0);
    vm_mem_ref_write_nomod(prog->op.arg[1], arg0_val);
}

static void lldi(prog_t *prog)
{
    int32_t s =
    vm_mem_ref_read_nomod(prog->op.arg[0]) +
    vm_mem_ref_read_nomod(prog->op.arg[1]);
    int32_t res = vm_mem_ref_read_nomod(vm_mem_ref_init_rel(s));

    prog->carry = (res == 0);
    vm_mem_ref_write_nomod(prog->op.arg[2], res);
}

static void aff(prog_t *prog)
{
    int32_t char_ = vm_mem_ref_read(prog->op.arg[0]) % 256;

    my_putchar(char_);
}

void prog_exec_op(prog_t *prog)
{
    switch (prog->op.code) {
    case 1:
        return live(prog);
    case 2:
        return ld(prog);
    case 3:
        return st(prog);
    case 4:
        return add(prog);
    case 5:
        return sub(prog);
    case 6:
        return and(prog);
    case 7:
        return or(prog);
    case 8:
        return xor(prog);
    case 9:
        return zjmp(prog);
    case 10:
        return ldi(prog);
    case 11:
        return sti(prog);
    case 13:
        return lld(prog);
    case 14:
        return lldi(prog);
    case 16:
        return aff(prog);
    }
}
