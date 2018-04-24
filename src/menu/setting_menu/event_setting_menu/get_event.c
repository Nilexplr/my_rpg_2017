/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main function for all the events in the setting menu
*/

#include "game_info.h"
#include "menu.h"
#include "setting_menu.h"

unsigned int get_event_setting_menu(game_t *game, menu_t *menu)
{
	sfEvent event;
	sfColor color[] = COLOR_BUTTON;

	if (sfRenderWindow_pollEvent(game->window->window, &event)) {
		fly_over_button(game, menu, color, OVER_COLOR_CHANGE);
		event_button_setting_menu(game, menu, event);
		event_close(event, menu);
	}
	return (SUCCESS);
}
