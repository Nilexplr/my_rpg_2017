/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** create functions
*/

#include "map.h"
#include "a_star.h"
#include <stdlib.h>

node_t *create_list(void)
{
	node_t *new = malloc(sizeof(node_t));

	new->count = 0;
	new->heuristique = 0;
	new->next = new;
	new->prev = new;
	return (new);
}

node_t full_up_node(map_t *map, int i, int j)
{
	node_t new;

	new.map_pos.x = i;
	new.map_pos.y = j;
	new.real_pos.x = map->tile[j][i].middle.x;
	new.real_pos.y = map->tile[j][i].middle.y;
	new.count = 0;
	new.heuristique = 0;
	new.distance = 0;
	if (map->tile[j][i].dispo == true)
		new.dispo = true;
	else
		new.dispo = false;
	new.next = NULL;
	new.prev = NULL;
	return (new);
}

node_t **create_nodes_map(map_t *map, sfVector2f start, sfVector2f end)
{
	node_t **nodes = malloc(
		sizeof(node_t *) * (1 + fabs(start.y - end.y)));
	int signx = SIGN(end.x - start.x);
	int signy = SIGN(end.y - start.y);

	for (int j = 0; j <= fabs(start.y - end.y); j++) {
		nodes[j] = malloc(sizeof(node_t) * (1 + fabs(start.x - end.x)));
		for (int i = 0; i <= fabs(start.x - end.x); i++) {
			nodes[j][i] = full_up_node(map, start.x + (i * signx),
				start.y + (j * signy));
			nodes[j][i].pos.x = i;
			nodes[j][i].pos.y = j;
		}
	}
	return (nodes);
}

astar_t *init_astar(map_t *map, sfVector2f start, sfVector2f end)
{
	astar_t *new = malloc(sizeof(astar_t));

	if (new != NULL) {
		new->nodes_map = create_nodes_map(map, start, end);
		new->closedlist = create_list();
		new->openlist = create_list();
		new->current = &new->nodes_map[0][0];
		new->max.x = fabs(start.x - end.x);
		new->max.y = fabs(start.y - end.y);
	}
	return (new);
}
