/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** how_menu function do the whole menu loop and display and init
*/

#include <stdlib.h>
#include "menu.h"
#include "how_menu.h"

// INITIALISATION OF THE HOW MAIN MENU
menu_t *initialisation_how_menu(game_t *game)
{
	menu_t *menu = malloc(sizeof(menu_t));

	if (menu == NULL)
		return (NULL);
	detail_init_how_menu(menu);
	if (menu->button == NULL || menu->text == NULL ||
	menu->foreground == NULL || menu->display == NULL ||
	menu->destroy == NULL) {
		verbose_how_menu_init_fail(game);
		return (NULL);
	}
	verbose_how_menu_init_ok(game);
	return (menu);
}

int how_menu(game_t *game, menu_t *main_menu)
{
	menu_t *menu = initialisation_how_menu(game);

	if (menu == NULL)
		return (84);
	menu_faded_appear(game, menu, main_menu);
	while (menu->looping == true && menu->code == OK) {
		if (get_event_how_menu(game, menu) == FAILURE)
			return (84);
		display_menu(game->window->window, main_menu, false);
		display_menu(game->window->window, menu, true);
	}
	menu_faded_disappear(game, menu, main_menu);
	if (menu->code == QUIT_GAME) {
		menu->destroy(menu);
		return (0);
	} else if (menu->code == ERROR) {
		menu->destroy(menu);
		return (84);
	}
	menu->destroy(menu);
	return (1);
}
