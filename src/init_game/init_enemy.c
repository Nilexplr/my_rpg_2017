/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init the enemy list
*/

#include "enemy.h"
#include <stdlib.h>

enemy_t *init_enemy_list(void)
{
	enemy_t *new = malloc(sizeof(enemy_t));

	if (new != NULL) {
		new->shape = NULL;
		new->next = new;
		new->prev = new;
	}
	return (new);
}
