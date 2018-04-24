/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main function for all the events in the play menu
*/

#include "game_info.h"
#include "menu.h"
#include "play_menu.h"
#include "player.h"

unsigned int get_event_play_menu(game_t *game, menu_t *menu)
{
	sfEvent event;
	sfColor color[] = COLOR_BUTTON;

	if (sfRenderWindow_pollEvent(game->window->window, &event)) {
		fly_over_button(game, menu, color, OVER_COLOR_CHANGE);
		event_button_play_menu(game, menu, event);
		text_box(game->player->info->name_player, event, menu->text[3],
			MAX_USER_CHAR);
		event_close(event, menu);
	}
	return (SUCCESS);
}
