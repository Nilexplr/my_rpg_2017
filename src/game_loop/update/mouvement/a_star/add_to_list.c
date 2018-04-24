/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** add a node to differents lists
*/

#include "a_star.h"

void add_openlist(astar_t *all, int i, int j, sfVector2i parent)
{
	node_t *node = &all->nodes_map[j][i];

	node->count = all->nodes_map[parent.y][parent.x].count + 1;
	node->distance = distance_points(node->pos, all->max);
	node->heuristique = node->count + node->distance;
	node->parent = parent;
	insert_node(all->openlist, node);
}

void add_closedlist(astar_t *all)
{
	if (all->current->next != NULL && all->current->prev != NULL) {
		all->current->prev->next = all->current->next;
		all->current->next->prev = all->current->prev;
	}
	insert_node(all->closedlist, all->current);
}
