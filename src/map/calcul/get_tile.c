/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** get_tile.c
*/

#include "game_info.h"
#include <stdlib.h>

int detect_tile(map_t *map, int i, int j, sfVector2i mouse)
{
	int x = inside_triangle(map->tile[j][i].shape1, mouse);
	int y = inside_triangle(map->tile[j][i].shape2, mouse);

	if (x == 1 || y == 1)
		return (1);
	return (0);
}

sfVector2f get_tuile(void *objet, sfVector2i mouse)
{
	game_t *game = objet;
	sfVector2f map_pos = game->player->render_character->map_pos;
	int counter = 0;
	int i;
	int j = map_pos.y + 30;
	sfVector2f pos = { -1, -1};

	j > Y_MAX - 2 ? j = Y_MAX - 2 : 0;
	for (; (j > map_pos.y - 30 && j > -1) && counter == 0; j--)
		for (i = (map_pos.x + 30 > X_MAX - 2 ?
		X_MAX - 2 : map_pos.x + 30);
		(i > map_pos.x - 30 && i > -1) && counter == 0; i--) {
			counter = detect_tile(game->map, i, j, mouse);
		}
	if (counter != 0) {
		pos.x = i + 1;
		pos.y = j + 1;
	}
	return (pos);
}
