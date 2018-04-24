/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** create projectil function
*/

#include "game_info.h"
#include <stdlib.h>

projectile_t *init_list_proj(void)
{
	projectile_t *new = malloc(sizeof(projectile_t));

	if (new != NULL) {
		new->next = new;
		new->prev = new;
	}
	return (new);
}

projectile_t *init_projectile(game_t *game, sfVector2i pos)
{
	projectile_t *new = malloc(sizeof(projectile_t));
	sfVector2f size = {20, 20};
	sfVector2f origin = {10, 10};

	if (new != NULL) {
		new->rec = sfRectangleShape_create();
		new->clock = sfClock_create();
		new->pos = game->player->render_character->real_pos;
		new->end.x = pos.x;
		new->end.y = pos.y;
		new->dammage = 10;
		new->mouvement = init_mouvement(new->pos, new->end, 10);
		sfRectangleShape_setSize(new->rec, size);
		sfRectangleShape_setOutlineThickness(new->rec, 2);
		sfRectangleShape_setOutlineColor(new->rec, sfCyan);
		sfRectangleShape_setOrigin(new->rec, origin);
		sfRectangleShape_setRotation(new->rec
			, init_rotate(new->pos, new->end));
		sfRectangleShape_setPosition(new->rec, new->pos);
	}
	return (new);
}

void create_projectile(void *objt, bool from_player)
{
	game_t *game = objt;
	sfVector2i pos = POS_CURSOR(game);
	projectile_t *new = init_projectile(game, pos);

	if (new == NULL)
		return;
	game->projectile->next->prev = new;
	new->next = game->projectile->next;
	new->prev = game->projectile;
	game->projectile->next = new;
	new->from_player = from_player;
}
