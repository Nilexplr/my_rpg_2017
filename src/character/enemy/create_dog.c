/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** create dog enemy structure
*/

#include "enemy.h"
#include <stdlib.h>

void init_dog_info(enemy_t *new)
{
	new->xp = XP_DOG;
	new->life = LIFE_DOG;
	new->type = DOG;
	new->speed = SPEED_DOG;
	new->next = NULL;
	new->prev = NULL;
}

enemy_t *create_dog(map_t *map, sfVector2f pos_map)
{
	enemy_t *new = malloc(sizeof(enemy_t));
	sfVector2f origin = { X_DOG / 2, Y_DOG / 2};
	sfVector2f size = { X_DOG, Y_DOG};

	if (new != NULL) {
		init_dog_info(new);
		new->life = LIFE_DOG;
		new->map_pos = pos_map;
		new->on_activity = false;
		new->real_pos = get_real_pos(map, pos_map);
		new->shape = sfRectangleShape_create();
		new->next = NULL;
		new->prev = NULL;
		new->type = DOG;
		new->clock = sfClock_create();
		new->node = NULL;
		sfRectangleShape_setSize(new->shape, size);
		sfRectangleShape_setOutlineThickness(new->shape, 2);
		sfRectangleShape_setOutlineColor(new->shape, sfRed);
		sfRectangleShape_setFillColor(new->shape, sfTransparent);
		sfRectangleShape_setOrigin(new->shape, origin);
		sfRectangleShape_setPosition(new->shape, new->real_pos);
	}
	return (new);
}
