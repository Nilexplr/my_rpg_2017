/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** setting_menu function do the whole menu loop and display and init
*/

#include <stdlib.h>
#include "menu.h"
#include "setting_menu.h"

// INITIALISATION OF THE SETTING MAIN MENU
menu_t *initialisation_setting_menu(game_t *game)
{
	menu_t *menu = malloc(sizeof(menu_t));

	if (menu == NULL)
		return (NULL);
	detail_init_setting_menu(menu);
	if (menu->button == NULL || menu->text == NULL ||
	menu->foreground == NULL || menu->display == NULL ||
	menu->destroy == NULL) {
		verbose_setting_menu_init_fail(game);
		return (NULL);
	}
	verbose_setting_menu_init_ok(game);
	return (menu);
}

int setting_menu(game_t *game, menu_t *main_menu)
{
	menu_t *menu = initialisation_setting_menu(game);
	int err = 1;

	if (menu == NULL)
		return (84);
	menu_faded_appear(game, menu, main_menu);
	while (menu->looping == true && menu->code == OK) {
		if (get_event_setting_menu(game, menu) == FAILURE)
			return (84);
		display_menu(game->window->window, main_menu, false);
		display_menu(game->window->window, menu, true);
	}
	menu->code == QUIT_GAME ? err = 0 : 0;
	menu->code == ERROR ? err = 84 : 0;
	menu_faded_disappear(game, menu, main_menu);
	menu->destroy(menu);
	return (err);
}
