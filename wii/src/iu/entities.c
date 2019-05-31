/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** iu_entities
*/

#include "headers.h"

void iu_refresh_bar(void)
{
    entity3_tag_player_data_t *data = _demo->world.player->tag_data;
    float hp_coef = data->hp / data->max_hp;
    float xp_coef = data->xp / data->max_xp;

    _iu.entities[IUENT_HP].rect.s.x = 0.753f * hp_coef;
    _iu.entities[IUENT_XP].rect.s.x = 0.753f * xp_coef;
    return;
}

void iu_error_msg_init(void)
{
    _iu.data.error_message[ERROR_INVENT_FULL] =
    vg_text_create(_iu.text_src[TEXT_INVENT_FULL], NULL);
    vg_text_set_position(&_iu.data.error_message[ERROR_INVENT_FULL],
    (vec2){-0.10, -0.05f});
    _iu.data.error_message[WARNING_SCREEN_MODIF] =
    vg_text_create(_iu.text_src[TEXT_WARNING_SCREEN], NULL);
    vg_text_set_position(&_iu.data.error_message[WARNING_SCREEN_MODIF],
    (vec2){0.03f, 0.10f});
}

static void set_intro_entities(void)
{
    entity_constructor(&_iu.intro[BG], (entity2_param_t){
    IUTEX_INTRO_VM_BG, (rect_t){{-1.0f, -1.0f}, {2.0f, 2.0f}}, -0.997});
    entity_constructor(&_iu.help, (entity2_param_t){
    IUTEX_HELP, (rect_t){{-1.0f, -1.0f}, {2.0f, 2.0f}}, 0.0f});
}

void set_entities(void)
{
    entity_constructor(&_iu.invent_bg[IUINVENT_BG], (entity2_param_t){
    IUTEX_INVENT_BG, (rect_t){{-1.0f, -1.0f}, {2.0f, 2.0f}}, -0.997});
    entity_constructor(&_iu.cadre[IUCADRE_BLACK], (entity2_param_t){
    IUTEX_TEXT_CADRE, (rect_t){{-0.5f, -1.0f}, {1.0f, 0.3f}}, -0.998});
    entity_constructor(&_iu.invent.item_image, (entity2_param_t){
    IUTEX_ITEM_VOID, (rect_t){{-0.125f, -0.06f}, {0.141f, 0.236f}}, -0.998});
    entity_constructor(&_iu.invent.cursor, (entity2_param_t){
    IUTEX_MENU_CURSOR, (rect_t){{-0.15f, -0.25f}, {0.03f, 0.04f}}, -0.998});
    entity_constructor(&_iu.invent.equiped_img, (entity2_param_t){
    IUTEX_ITEM_VOID, (rect_t){{-0.425f, 0.143f}, {0.141f, 0.236f}}, -0.998});
    entity_constructor(&_iu.entities[IUENT_MAIN], (entity2_param_t){
    IUTEX_UI, (rect_t){{-1.0f, -1.0f}, {2.0f, 2.0f}}, -0.997});
    entity_constructor(&_iu.entities[IUENT_XP], (entity2_param_t){
    IUTEX_XP_BAR, (rect_t){{-0.3875f, 0.847f}, {0.745f, 0.017f}}, -0.998});
    entity_constructor(&_iu.entities[IUENT_HP], (entity2_param_t){
    IUTEX_HP_BAR, (rect_t){{-0.395f, 0.895f}, {0.753f, 0.05f}}, -0.998});
    set_pause_entities();
    set_intro_entities();
}