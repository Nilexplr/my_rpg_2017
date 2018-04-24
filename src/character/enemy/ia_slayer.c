/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** ia for the slayer enemy
*/

#include "game_info.h"
#include "time.h"
#include <stdlib.h>

static projectile_t *init_projectile_slayer(sfVector2f start, sfVector2f end)
{
	projectile_t *new = malloc(sizeof(projectile_t));
	sfVector2f size = {20, 20};
	sfVector2f origin = {10, 10};

	if (new != NULL) {
		new->rec = sfRectangleShape_create();
		new->clock = sfClock_create();
		new->pos = start;
		new->end.x = end.x;
		new->end.y = end.y;
		new->dammage = SLAYER_DAMMAGE;
		new->from_player = false;
		new->mouvement = init_mouvement(new->pos, new->end, SPEED_ATK);
		sfRectangleShape_setSize(new->rec, size);
		sfRectangleShape_setOutlineThickness(new->rec, 2);
		sfRectangleShape_setOutlineColor(new->rec, sfRed);
		sfRectangleShape_setOrigin(new->rec, origin);
		sfRectangleShape_setRotation(new->rec
			, init_rotate(new->pos, new->end));
		sfRectangleShape_setPosition(new->rec, new->pos);
	}
	return (new);
}
static void slayer_projectile(game_t *game, sfVector2f start)
{
	sfVector2f dest = game->player->render_character->real_pos;
	projectile_t *new = init_projectile_slayer(start, dest);

	if (new == NULL)
		return;
	game->projectile->next->prev = new;
	new->next = game->projectile->next;
	new->prev = game->projectile;
	game->projectile->next = new;
}

void slayer_attack(game_t *game, enemy_t *enemy)
{
	if (sfClock_getElapsedTime(enemy->clock).microseconds >=
	sfSeconds(2).microseconds) {
		slayer_projectile(game, enemy->real_pos);
		sfClock_restart(enemy->clock);
	}
}

void get_slayer_turn(game_t *game, enemy_t *enemy)
{
	sfVector2f player_pos = game->player->render_character->map_pos;

	if (enemy->on_activity == true)
		return;
	if (player_pos.x <= enemy->map_pos.x + SLAYER_PO
	&& player_pos.x >= enemy->map_pos.x - SLAYER_PO
	&& player_pos.y <= enemy->map_pos.y + SLAYER_PO
	&& player_pos.y >= enemy->map_pos.y - SLAYER_PO)
		slayer_attack(game, enemy);
	else
		if (player_pos.x <= enemy->map_pos.x + SLAYER_PM
		&& player_pos.x >= enemy->map_pos.x - SLAYER_PM
		&& player_pos.y <= enemy->map_pos.y + SLAYER_PM
		&& player_pos.y >= enemy->map_pos.y - SLAYER_PM)
			ia_move(game, enemy);
}
