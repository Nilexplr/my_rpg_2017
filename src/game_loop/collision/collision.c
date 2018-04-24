/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** all the different collision
*/

#include "game_info.h"

void collision_projectile_player(game_t *game, projectile_t *it)
{
	bool collide = setup_collision(2, it->rec
		, game->player->render_character->shape);

	if (collide == true) {
		it = it->prev;
		destroy_projectile_charact(it->next
			, &game->player->info->health);
	}
}

int collision(game_t *game)
{
	for (projectile_t *it = game->projectile->next; it != game->projectile
		; it = it->next) {
		if (it->from_player == true)
			collision_projectile_enemy(game, it);
		else
			collision_projectile_player(game, it);
		}
}
