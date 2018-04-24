/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** decide where spawn mobs
*/

#include "game_info.h"
#include <stdlib.h>

sfVector2f get_spawn_pos(game_t *game)
{
	sfVector2f spawn = game->player->render_character->map_pos;

	spawn.x += (rand() % SPAWN + 6) * SIGN(rand() - rand());
	spawn.y += (rand() % SPAWN + 6) * SIGN(rand() - rand());
	if (spawn.y < 0 || spawn.y > game->map->max.y)
		return (get_spawn_pos(game));
	if (spawn.x < 0 || spawn.x > game->map->max.x)
		return (get_spawn_pos(game));
	if (game->map->tile[(int)spawn.y][(int)spawn.x].dispo == false)
		return (get_spawn_pos(game));
	return (spawn);
}
