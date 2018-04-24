/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** destroy enemy structure
*/

#include "enemy.h"
#include <stdlib.h>

void destroy_enemy(enemy_t *it)
{
	sfRectangleShape_destroy(it->shape);
	sfClock_destroy(it->clock);
	it->prev->next = it->next;
	it->next->prev = it->prev;
	free(it);
}
