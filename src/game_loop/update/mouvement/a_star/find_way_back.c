/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** find the way back
*/

#include "a_star.h"
#include <stdlib.h>

node_t *copy_node(node_t node)
{
	node_t *new = malloc(sizeof(node_t));

	if (new != NULL) {
		new->map_pos.x = node.map_pos.x;
		new->map_pos.y = node.map_pos.y;
		new->pos.x = node.pos.x;
		new->pos.y = node.pos.y;
		new->real_pos.x = node.real_pos.x;
		new->real_pos.y = node.real_pos.y;
		new->parent.x = node.parent.x;
		new->parent.y = node.parent.y;
		new->count = 0;
		new->heuristique = 0;
		new->distance = 0;
		new->dispo = true;
		new->next = NULL;
		new->prev = NULL;
	}
	return(new);
}

void find_way_back(astar_t *all, node_t *list)
{
	sfVector2i parent = all->closedlist->next->parent;

	insert_node(list, copy_node(*all->closedlist->next));
	insert_node(list, copy_node(all->nodes_map[parent.y][parent.x]));
	while (parent.x != 0 && parent.y != 0) {
		parent = all->nodes_map[parent.y][parent.x].parent;
		insert_node(list
			, copy_node(all->nodes_map[parent.y][parent.x]));
	}
}
