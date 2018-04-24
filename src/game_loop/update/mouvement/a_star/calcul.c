/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** calcul distance between 2 points
*/

#include "map.h"
#include "a_star.h"

float distance_points(sfVector2i start, sfVector2i end)
{
	return (sqrt(pow((start.x - end.x),2) + pow((start.y - end.y), 2)));
}

bool is_inside_list(node_t *list, int i, int j)
{
	for (node_t *it = list->next; it != list; it = it->next)
		if (it->pos.x == i && it->pos.y == j)
			return (true);
	return (false);
}

bool inside_open_list(astar_t *all, int i, int j, sfVector2i parent)
{
	node_t node;
	node_t *save = NULL;

	node.count = all->nodes_map[parent.y][parent.x].count + 1;
	node.distance = distance_points(all->nodes_map[j][i].pos, all->max);
	node.heuristique = node.count + node.distance;
	node.parent = parent;
	for (node_t *it = all->openlist->next; it != all->openlist;
							it = it->next)
		if (it->pos.x == i && it->pos.y == j) {
			save = it;
			break;
		}
	if (save != NULL && compare_nodes(node, *save) == 1) {
		save->count = node.count;
		save->distance = node.distance;
		save->heuristique = node.heuristique;
		save->parent = node.parent;
	}
	return (save == NULL ? false : true);
}
