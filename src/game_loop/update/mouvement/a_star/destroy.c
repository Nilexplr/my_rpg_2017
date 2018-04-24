/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** destroy a star
*/

#include "a_star.h"
#include "player.h"
#include <stdlib.h>

void destroy_astar(astar_t *all)
{
	sfVector2i max = all->max;

	for (int j = 0; j <= max.y; j++)
		free(all->nodes_map[j]);
	free(all->nodes_map);
	free(all->openlist);
	free(all->closedlist);
	free(all);
}

void destroy_list(node_t *list)
{
	node_t *save;

	while (list->next != list) {
		save = list->next;
		list->next = save->next;
		free(save);
	}
	free(list);
}
