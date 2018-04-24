/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** play_menu function do the whole menu loop and display and init
*/

#include <stdlib.h>
#include "game_info.h"
#include "menu.h"
#include "play_menu.h"

// INITIALISATION OF THE PLAY MAIN MENU
menu_t *initialisation_play_menu(game_t *game)
{
	menu_t *menu = malloc(sizeof(menu_t));

	if (menu == NULL)
		return (NULL);
	if (game->player->info->new_savegame == true)
		detail_init_old_play_menu(game->player, menu);
	else
		detail_init_play_menu(menu);
	if (menu->button == NULL || menu->text == NULL ||
	menu->foreground == NULL || menu->display == NULL ||
	menu->destroy == NULL) {
		verbose_play_menu_init_fail(game);
		return (NULL);
	}
	verbose_play_menu_init_ok(game);
	return (menu);
}

int play_menu(game_t *game, menu_t *main_menu)
{
	menu_t *menu = initialisation_play_menu(game);
	int err = 0;

	if (menu == NULL)
		return (84);
	menu_faded_appear(game, menu, main_menu);
	while (menu->looping == true && menu->code == OK) {
		if (get_event_play_menu(game, menu) == FAILURE)
			return (84);
		display_menu(game->window->window, main_menu, false);
		display_menu(game->window->window, menu, true);
	}
	menu->code == QUIT_GAME ? err = 0 : 0;
	menu->code == ERROR ? err = 84 : 0;
	menu->code == QUIT_MENU ? err = 1 : 0;
	menu->code == OK ? err = 2 : 0;
	menu_faded_disappear(game, menu, main_menu);
	menu->destroy(menu);
	return (err);
}
