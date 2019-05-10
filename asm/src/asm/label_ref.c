/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

asm_label_ref_t asm_label_ref_create(const char *label, size_t off,
size_t instr_base, int is_short)
{
    asm_label_ref_t res;

    res.label = strdup_slow(label);
    res.off = off;
    res.instr_base = instr_base;
    res.is_short = is_short;
    return res;
}

void asm_label_ref_destroy(asm_label_ref_t ref)
{
    free(ref.label);
}

static size_t get_off(asm_t *a, asm_label_ref_t ref)
{
    for (size_t i = 0; i < a->labels.count; i++)
        if (streq(a->labels.label[i].name, ref.label))
            return a->labels.label[i].off - ref.instr_base;
    error_mul_exit("Undefined reference to this label", ref.label);
    return ~0ULL;
}

static void resolve_ref(asm_t *a, asm_label_ref_t ref)
{
    size_t off = get_off(a, ref);
    void *addr = &((char*)a->out.data)[ref.off];

    if (ref.is_short)
        *((uint16_t*)addr) = swap16(off);
    else
        *((uint32_t*)addr) = swap32(off);
}

void asm_label_refs_resolve(asm_t *a)
{
    for (size_t i = 0; i < a->refs.count; i++)
        resolve_ref(a, a->refs.ref[i]);
}
