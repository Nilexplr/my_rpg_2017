/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Main file of the whole game loop.
*/

#include <stdlib.h>
#include "game_info.h"
#include "event.h"
#include "hud.h"

void game_loop(game_t *game)
{
	hud_t *hud = init_hud();

	if (hud == NULL)
		return;
	while (sfRenderWindow_isOpen(game->window->window)) {
		sfRenderWindow_clear(game->window->window, sfBlack);
		event(game->window->window, game, hud);
		update(game, hud);
		collision(game);
		draw_call(game, hud);
		sfRenderWindow_display(game->window->window);
	}
}
