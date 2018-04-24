/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include "inventory.h"
#include "menu.h"
#include "game_info.h"

static int player_stuffing(sfMouseButtonEvent event,
	sfRenderWindow * window, inventory_t *inv)
{
	for (int i = 0; i < NB_BEGIN_STUFF; i++) {
		check_click(event, inv->obj_in[i], inv);
	}
	return (0);
}

static int quit_inventory(sfEvent *event)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		return (QUIT_MENU);
}

int event_inventory(game_t *game_info, int choice, inventory_t *inv)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(game_info->window->window, &event)) {
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close(game_info->window->window);
			return (QUIT_GAME);
		}
		choice = quit_inventory(&event);
		if (event.type == sfEvtMouseButtonPressed) {
			choice = player_stuffing(event.mouseButton,
				game_info->window->window, inv);
		}
	}
	return (choice);
}
