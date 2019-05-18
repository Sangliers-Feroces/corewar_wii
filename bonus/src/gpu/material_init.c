/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** vulkan ftw
*/

#include "headers.h"

const material_desc_t mat_desc[] = {
    {MATERIAL_GRASS, &material_fun_grass_world, &material_fun_grass_entity, 0},
    {MATERIAL_WATER, &material_fun_water_world, &material_fun_water_entity, 1},
    {MATERIAL_SKYBOX, &material_fun_skybox_world,
    &material_fun_skybox_entity, 1},
    {MATERIAL_VEG_GRASS1, &material_fun_veg_grass1_entity,
    &material_fun_veg_grass1_entity, 0},
    {MATERIAL_BLOOD, &material_fun_blood_entity,
    &material_fun_blood_entity, 0},
    {MATERIAL_WOOD, &material_fun_wood_entity,
    &material_fun_wood_entity, 0},
    {MATERIAL_NPC1, &material_fun_npc1_entity,
    &material_fun_npc1_entity, 0},
    {MATERIAL_METAL_RUST, &material_fun_metal_rust_entity,
    &material_fun_metal_rust_entity, 0},
    {MATERIAL_METAL_BARE, &material_fun_metal_bare_entity,
    &material_fun_metal_bare_entity, 0},
    {0, NULL, NULL, 0}
};

void material_init(demo_t *demo)
{
    for (size_t i = 0; i < MATERIAL_MAX; i++)
        demo->material[i] = (material_full_t){NULL, NULL, 0};
    for (size_t i = 0; mat_desc[i].world != NULL; i++)
        demo->material[mat_desc[i].material] =
        (material_full_t){mat_desc[i].world, mat_desc[i].entity,
        mat_desc[i].is_transparent};
    for (size_t i = 0; i < MATERIAL_MAX; i++)
        if (demo->material[i].entity == NULL) {
            printf("Error: can't load material #%zu.\n", i);
            exit(84);
        }
}
