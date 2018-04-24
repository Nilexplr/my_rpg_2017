/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include "game_info.h"
#include "a_star.h"
#include <stdlib.h>

node_t *find_next_node(game_t *game, enemy_t *enemy, int i, int j)
{
	node_t *new = malloc(sizeof(node_t));
	sfVector2i current_pos = { enemy->map_pos.x + i, enemy->map_pos.y + j};
	sfVector2f map_pos = { enemy->map_pos.x + i, enemy->map_pos.y + j};
	sfVector2i player = { game->player->render_character->map_pos.x,
			game->player->render_character->map_pos.y };

	if (current_pos.y < 0 || current_pos.y > game->map->max.y)
		return (NULL);
	if (current_pos.x < 0 || current_pos.x > game->map->max.x)
		return (NULL);
	if (game->map->tile[current_pos.y][current_pos.x].dispo == false)
		return (NULL);
	new->map_pos.x = enemy->map_pos.x + i;
	new->map_pos.y = enemy->map_pos.y + j;
	new->real_pos = get_real_pos(game->map, map_pos);
	new->heuristique = distance_points(new->map_pos, player);
	return (new);
}

static node_t *next_mouve(game_t *game, enemy_t *enemy)
{
	node_t *node[4] = { find_next_node(game, enemy, -1, 0),
	find_next_node(game, enemy, 1, 0), find_next_node(game, enemy, 0, 1),
	find_next_node(game, enemy, 0, -1) };
	node_t *result = malloc(sizeof(node_t));
	int count = 0;
	int counter = 100000;

	for (int i = 0; i < 4; i++)
		if (node[i] != NULL && node[i]->heuristique < counter) {
			counter = node[i]->heuristique;
			count = i;
		}
	if (counter == 100000)
		return (NULL);
	*result = *node[count];
	for (int i = 0; i < 4; i++)
		free(node[i]);
	return(result);
}

void ia_move(game_t *game, enemy_t *enemy)
{
	node_t *best_node = next_mouve(game, enemy);

	enemy->node = best_node;
	enemy->on_activity = true;
	enemy->mouve = init_mouvement(enemy->real_pos
		, best_node->real_pos, enemy->speed);
}
