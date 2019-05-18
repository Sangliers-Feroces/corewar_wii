/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** stat_display
*/

#include "headers.h"

void invent_stat_display_init(void)
{
    for (int i = 0; i < STAT_END; i++) {
        _iu.invent.stats[i] = vg_text_create(NULL, NULL);
        vg_text_set_position(&_iu.invent.stats[i],
        (vec2){-0.50f, -0.30f + (i * -0.05f)});
        vg_text_set_size(&_iu.invent.stats[i], (vec2){0.02f, 0.03f});
    }
}

static void draw_stat_ext(void)
{
    char buff_lvl[64];
    char buff_xp[64];
    entity3_tag_player_data_t *data = _demo->world.player->tag_data;

    sprintf(buff_lvl, "LEVEL: %.f", data->level);
    vg_text_reset_str(&_iu.invent.stats[STAT_LVL], buff_lvl, NULL);
    sprintf(buff_xp, "XP: %.f / %.f",
    data->xp, data->max_xp);
    vg_text_reset_str(&_iu.invent.stats[STAT_XP], buff_xp, NULL);
    for (int i = STAT_LVL; i < STAT_END; i++)
        vg_text_draw(_iu.invent.stats[i]);
}

void invent_draw_stat(void)
{
    char buff_hp[64];
    char buff_mana[64];
    char buff_attack[64];
    char buff_defense[64];
    entity3_tag_player_data_t *data = _demo->world.player->tag_data;

    sprintf(buff_hp, "HP: %.f / %.f", data->hp, data->max_hp);
    vg_text_reset_str(&_iu.invent.stats[STAT_HP], buff_hp, NULL);
    sprintf(buff_mana, "MANA: %.f / %.f",
    data->mana, data->max_mana);
    vg_text_reset_str(&_iu.invent.stats[STAT_MANA], buff_mana, NULL);
    sprintf(buff_attack, "ATTACK: %.f", _demo->player.attack_add);
    vg_text_reset_str(&_iu.invent.stats[STAT_ATTACK], buff_attack, NULL);
    sprintf(buff_defense, "DEFENSE: %.f", _demo->player.defense);
    vg_text_reset_str(&_iu.invent.stats[STAT_DEFENSE], buff_defense, NULL);
    for (int i = 0; i < STAT_LVL; i++)
        vg_text_draw(_iu.invent.stats[i]);
    draw_stat_ext();
}
