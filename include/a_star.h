/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** A* prototype
*/

#ifndef A_STAR_H_
#define A_STAR_H_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "map.h"

typedef struct node_s {
	sfVector2i map_pos;
	sfVector2i pos;
	sfVector2i parent;
	sfVector2f real_pos;
	int count;
	int heuristique;
	int distance;
	bool dispo;
	struct node_s *next;
	struct node_s *prev;
}node_t;

typedef struct astar_s {
	node_t **nodes_map;
	node_t *closedlist;
	node_t *openlist;
	node_t *current;
	sfVector2i max;
}astar_t;

node_t **create_nodes_map(map_t *map, sfVector2f start, sfVector2f end);
node_t *create_list(void);
node_t *find_way(map_t *map, sfVector2f start, sfVector2f end);
astar_t *init_astar(map_t *map, sfVector2f start, sfVector2f end);
bool inside_open_list(astar_t *all, int i, int j, sfVector2i parent);
bool is_inside_list(node_t *list, int i, int j);
float distance_points(sfVector2i start, sfVector2i end);
void find_best_node(astar_t *all);
void find_successor(astar_t *all);
void add_closedlist(astar_t *all);
void add_openlist(astar_t *all, int i, int j, sfVector2i parent);
int compare_nodes(node_t node1, node_t node2);
void insert_node(node_t *list, node_t *node);
void destroy_astar(astar_t *all);
void find_way_back(astar_t *all, node_t *list);
node_t *find_way(map_t *map, sfVector2f start, sfVector2f end);
void destroy_list(node_t *list);


#endif /* end of include guard: A_STAR_H_ */
