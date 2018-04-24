/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** drw call functions
*/

#include "game_info.h"
#include "hud.h"

void draw_character(game_t *game)
{
	sfRenderWindow_drawRectangleShape(game->window->window,
			game->player->render_character->shape, NULL);
}

void draw_projectile(game_t *game)
{
	for (projectile_t *it = game->projectile->next; it != game->projectile
		; it = it->next) {
		sfRenderWindow_drawRectangleShape(game->window->window,
		it->rec, NULL);
		if (sfClock_getElapsedTime(it->clock).microseconds >=
		sfSeconds(LIFETIME).microseconds) {
			it = it->prev;
			destroy_projectile(it->next);
		}
	}
}

void draw_enemy(game_t *game)
{
	for (enemy_t *it = game->enemy->next; it != game->enemy; it = it->next)
		sfRenderWindow_drawRectangleShape(game->window->window,
			it->shape, NULL);
}

int draw_call(game_t *game, void *ptr)
{
	hud_t *hud = ptr;

	draw_tile(game->window->window, game->map
		, game->player->render_character->map_pos);
	draw_character(game);
	draw_projectile(game);
	draw_enemy(game);
	display_menu(game->window->window, hud, false);
}
