/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** teleport function
*/

#include "game_info.h"

void teleport(game_t *game)
{
	sfVector2i mouse = POS_CURSOR(game);
	sfVector2f dest_map = get_tuile(game, mouse);

	if (dest_map.x == -1 && dest_map.y == -1)
		return;
	if (game->player->mv_list != NULL) {
		destroy_list(game->player->mv_list);
		game->player->mv_list = NULL;
		game->player->render_character->mouve.x = 0;
		game->player->render_character->mouve.y = 0;
	}
	if (game->map->tile[(int)dest_map.x][(int)dest_map.y].dispo == false)
		return;
	game->player->render_character->map_pos = dest_map;
	game->player->render_character->real_pos = get_real_pos(
		game->map, game->player->render_character->map_pos);
	sfRectangleShape_setPosition(
		game->player->render_character->shape,
		game->player->render_character->real_pos);
}
