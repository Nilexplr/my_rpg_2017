/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** update functions
*/

#include "game_info.h"
#include "hud.h"
#include <stdlib.h>

void update_view(game_t *game)
{
	sfVector2f player_pos = sfRectangleShape_getPosition(
		game->player->render_character->shape);
	game->window->posView.x = player_pos.x;
	game->window->posView.y = player_pos.y;
	sfView_setCenter(game->window->view, game->window->posView);
	sfRenderWindow_setView(game->window->window, game->window->view);
}

void update_player(game_t *game)
{
	sfVector2f player_pos = sfRectangleShape_getPosition(
		game->player->render_character->shape);

	if (game->player->render_character->mouve.x != 0 &&
	  game->player->render_character->mouve.y != 0) {
		sfRectangleShape_move(game->player->render_character->shape,
		game->player->render_character->mouve);
		game->player->render_character->real_pos = player_pos;
	}
	if (game->player->mv_list == NULL)
		return;
	if (player_pos.x >= game->player->mv_list->next->real_pos.x - 2
		&& player_pos.x <= game->player->mv_list->next->real_pos.x + 2
		&& player_pos.y >= game->player->mv_list->next->real_pos.y - 2
		&& player_pos.y <= game->player->mv_list->next->real_pos.y + 2)
	{
		game->player->render_character->map_pos.x = game->player->
		mv_list->next->map_pos.x;
		game->player->render_character->map_pos.y = game->player->
		mv_list->next->map_pos.y;
		destroy_node(game->player);
		game->player->render_character->mouve = mouve_to_node(
			game->player);
	}
}

void update_enemy(game_t *game)
{
	sfVector2f enemy;

	for (enemy_t *it = game->enemy->next; it != game->enemy
	; it = it->next) {
		it->type == SLAYER ? get_slayer_turn(game, it) : 0;
		it->type == DOG ? get_dog_turn(game, it) : 0;
		if (it->life < 0) {
			game->player->info->exp += it->xp;
			destroy_enemy(it);
		}
		if (it->on_activity == true) {
			sfRectangleShape_move(it->shape, it->mouve);
			enemy = sfRectangleShape_getPosition(it->shape);
			if (enemy.x >= it->node->real_pos.x - 8
			&& enemy.x <= it->node->real_pos.x + 8
			&& enemy.y >= it->node->real_pos.y - 8
			&& enemy.y <= it->node->real_pos.y + 8) {
				it->map_pos.x = it->node->map_pos.x;
				it->map_pos.y = it->node->map_pos.y;
				it->real_pos = it->node->real_pos;
				free(it->node);
				sfRectangleShape_setPosition(it->shape, it->real_pos);
				it->on_activity = false;
			}
		}
	}
}

void update_player_info(game_t *game)
{
	if (game->player->info->exp >= 10 * game->player->info->level) {
		game->player->info->level++;
		game->player->info->compet_point +=
		1 * game->player->info->level;
		game->player->info->exp = 0;
	}
}

int update(game_t *game, void *hud_ptr)
{
	hud_t *hud = hud_ptr;

	update_view(game);
	update_hud(hud, game->window, game->player);
	for (projectile_t *it = game->projectile->next; it != game->projectile
		; it = it->next)
		sfRectangleShape_move(it->rec, it->mouvement);
	update_player(game);
	update_player_info(game);
	update_enemy(game);
	return (0);
}
