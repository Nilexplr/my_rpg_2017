/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** find and analyse successor functions
*/

#include "a_star.h"

void check_successor(astar_t *all, int i, int j, sfVector2i current_pos)
{
	if (i < 0 || i > all->max.x)
		return;
	if (i == current_pos.x && j == current_pos.y)
		return;
	if (all->nodes_map[j][i].dispo == false)
		return;
	if (is_inside_list(all->closedlist, i, j) == false) {
		if (inside_open_list(all, i, j, current_pos) == true)
			return;
		else
			add_openlist(all, i, j, current_pos);
	}
}

void find_successor(astar_t *all)
{
	sfVector2i current_pos = all->current->pos;

	for (int j = current_pos.y - 1;  j <= current_pos.y + 1; j++) {
		if (j < 0 || j > all->max.y)
			continue;
		for (int i = current_pos.x - 1; i <= current_pos.x + 1; i++) {
			check_successor(all, i, j, current_pos);
		}
	}
}
