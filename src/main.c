/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Main file, calling the main menu and the game loop
*/

#include <stdlib.h>
#include "game_info.h"
#include "main_menu.h"
#include "map.h"
#include "player.h"

int main(int argc, char **argv, char **envp)
{
	game_t *game = init_game(argc, argv);
	int code = 0;

	if (game == NULL)
		return (84);
	while (sfRenderWindow_isOpen(game->window->window)) {
		code = main_menu(game);
		if (code != 1)
			return (code);
		game_loop(game);
	}
	save_player(game->player);
	game->destroy(game);
	return (0);
}
