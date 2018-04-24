/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** find best node
*/

#include "a_star.h"

void find_best_node(astar_t *all)
{
	int heuristique = all->openlist->next->heuristique;

	all->current = all->openlist->next;
	for (node_t *it = all->openlist->next; it != all->openlist; it = it->next)
		if (heuristique > it->heuristique) {
			all->current = it;
			heuristique = it->heuristique;
		}
}
