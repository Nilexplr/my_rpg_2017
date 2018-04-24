/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Init the whole game structure. return NULL if error.
*/

#include <stdlib.h>
#include "game_info.h"
#include "flag_program.h"

void init_view(game_t *game)
{
	sfVector2f size_view = {DEFAULT_SIZE_X, DEFAULT_SIZE_Y};

	game->window->posView = game->player->render_character->real_pos;
	sfView_setCenter(game->window->view, game->window->posView);
	sfView_setSize(game->window->view, size_view);
}

game_t *init_game(int argc, char **argv)
{
	game_t *game = malloc(sizeof(game_t));

	if (game == NULL)
		return (NULL);
	game->prog_state = FINE;
	game->verbose = is_verbose(argc, argv);
	game->window = init_window(game->verbose);
	game->music = init_music();
	game->map = init_map(create_map_from_file(
		"./resources/savegame/open_map.txt"));
	game->player = init_player(game);
	game->destroy = destroy_game;
	game->window->view = sfView_create();
	game->enemy = init_enemy_list();
	game->projectile = init_list_proj();
	init_drop(game);
	full_up_map(game->map);
	init_view(game);
	// OPTIMIZE : NULL RETURN CHECK ALL PREVIOUS MALLOC -> OTHER FUNCTION ?
	return (game);
}
