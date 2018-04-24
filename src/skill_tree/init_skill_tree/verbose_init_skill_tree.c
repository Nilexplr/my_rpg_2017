/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/
#include "game_info.h"
#include "menu.h"
#include "mylib.h"
#include "colors.h"

void verbose_skill_tree_init_fail(game_t *game)
{
	if (game->verbose == true) {
		my_putstr(LIGHT_BLUE);
		my_putstr("[INVENTORY INIT]\n");
		my_putstr(LIGHT_RED);
		my_putstr("\tInventory failed to create\n");
		my_putstr(WHITE);
	}
}

void verbose_skill_tree_init_ok(game_t *game)
{
	if (game->verbose == true) {
		my_putstr(LIGHT_BLUE);
		my_putstr("[INVENTORY INIT]\n");
		my_putstr(GREEN);
		my_putstr("\tIventory well created\n");
		my_putstr(WHITE);
	}
}
