/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main_menu function do the whole menu loop and display and init
*/

#include <stdlib.h>
#include "menu.h"
#include "main_menu.h"

// INITIALISATION OF THE MAIN MENU
menu_t *initialisation_main_menu(game_t *game)
{
	menu_t *menu = malloc(sizeof(menu_t));

	if (menu == NULL)
		return (NULL);
	detail_init_main_menu(menu);
	if (menu->button == NULL || menu->text == NULL ||
	menu->foreground == NULL || menu->display == NULL ||
	menu->destroy == NULL) {
		verbose_main_menu_init_fail(game);
		return (NULL);
	}
	verbose_main_menu_init_ok(game);
	return (menu);
}

int main_menu(game_t *game)
{
	menu_t *main_menu = initialisation_main_menu(game);

	if (main_menu == NULL)
		return (84);
	while (main_menu->looping == true && main_menu->code == OK) {
		if (get_event_main_menu(game, main_menu) == FAILURE)
			return (84);
		main_menu->display(game->window->window, main_menu, true);
	}
	if (main_menu->code == QUIT_GAME) {
		main_menu->destroy(main_menu);
		return (0);
	} else if (main_menu->code == ERROR) {
		return (84);
	}
	menu_faded_disappear(game, main_menu, main_menu);
	main_menu->destroy(main_menu);
	return (1);
}
