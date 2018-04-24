/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Add text to the play menu's text depending on the player's data
*/

#include "player.h"
#include "menu.h"
#include "old_play_menu.h"
#include "mylib.h"

void add_detail_text_old(player_info_t *info, text_t **text)
{
	sfText_setString(text[3]->text, info->name_player);
	sfText_setString(text[6]->text, my_itoa(info->level));
	sfText_setString(text[4]->text, my_itoa(info->health));
	sfText_setString(text[7]->text, my_itoa(info->exp));
	sfText_setString(text[5]->text, my_itoa(info->attack));
	sfText_setString(text[8]->text, my_itoa(info->actual_mission + 1));
}
