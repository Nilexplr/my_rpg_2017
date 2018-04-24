/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** turn dog
*/

#include "game_info.h"
#include "time.h"
#include <stdlib.h>

void dog_attack(game_t *game, enemy_t *enemy)
{
	if (sfClock_getElapsedTime(enemy->clock).microseconds >=
	sfSeconds(3).microseconds) {
		game->player->info->health -= DOG_DAMMAGE;
		sfClock_restart(enemy->clock);
	}
}

void get_dog_turn(game_t *game, enemy_t *enemy)
{
	sfVector2f player_pos = game->player->render_character->map_pos;

	if (enemy->on_activity == true)
		return;
	if (player_pos.x <= enemy->map_pos.x + DOG_PO
	&& player_pos.x >= enemy->map_pos.x - DOG_PO
	&& player_pos.y <= enemy->map_pos.y + DOG_PO
	&& player_pos.y >= enemy->map_pos.y - DOG_PO)
		dog_attack(game, enemy);
	else
		if (player_pos.x <= enemy->map_pos.x + DOG_PM
		&& player_pos.x >= enemy->map_pos.x - DOG_PM
		&& player_pos.y <= enemy->map_pos.y + DOG_PM
		&& player_pos.y >= enemy->map_pos.y - DOG_PM)
			ia_move(game, enemy);
}
