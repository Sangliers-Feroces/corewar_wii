/*
** EPITECH PROJECT, 2018
** (´ε｀；)
** File description:
** main
*/

#include "headers.h"

vec_asm_label_t vec_asm_label_init(void)
{
    vec_asm_label_t res;

    res.count = 0;
    res.allocated = 0;
    res.label = NULL;
    return res;
}

void vec_asm_label_destroy(vec_asm_label_t vec)
{
    for (size_t i = 0; i < vec.count; i++)
        free(vec.label[i].name);
    free(vec.label);
}

void vec_asm_label_add(vec_asm_label_t *vec, asm_label_t to_add)
{
    size_t cur = vec->count++;

    if (vec->count > vec->allocated) {
        vec->allocated += 16;
        vec->label =
        (asm_label_t*)realloc(vec->label, vec->allocated * sizeof(asm_label_t));
    }
    vec->label[cur] = to_add;
}

static int is_label_char_valid(char to_test)
{
    const char *valid = "abcdefghijklmnopqrstuvwxyz_0123456789";

    for (size_t i = 0; valid[i] != '\0'; i++)
        if (to_test == valid[i])
            return 1;
    return 0;
}

static void test_label_valid(const char *label)
{
    char token[2] = {0};

    if (strlen_slow(label) == 0)
        error_line_exit(_line, "Invalid label", "void one");
    for (size_t i = 0; label[i] != '\0'; i++)
        if (!is_label_char_valid(label[i])) {
            token[0] = label[i];
            error_line_exit(_line, "Illegal character in label", token);
        }
}

asm_label_t asm_label_create(const char *to_dup, size_t off)
{
    asm_label_t res;

    res.name = strdup_slow(to_dup);
    res.off = off;
    test_label_valid(res.name);
    return res;
}
