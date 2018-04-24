/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** destroy the whole game structre
*/

#include <stdlib.h>
#include "game_info.h"
#include "window.h"

static void destroy_window(window_t *window)
{
	sfRenderWindow_close(window->window);
	sfRenderWindow_destroy(window->window);
	free(window);
}

void destroy_game(game_t *game)
{
	destroy_window(game->window);
	free(game);
}
