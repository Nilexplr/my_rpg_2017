/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** draw map functions
*/

#include "map.h"

void draw_vertex_square(sfRenderWindow *window, int i, int j, map_t *map)
{
	sfVector2f **map2d = map->map2d;
	sfVertexArray *ligne1 = create_line(map2d[j][i], map2d[j][i + 1]);
	sfVertexArray *ligne2 = create_line(map2d[j][i + 1]
		, map2d[j + 1][i + 1]);
	sfVertexArray *ligne3 = create_line(map2d[j + 1][i + 1]
		, map2d[j + 1][i]);
	sfVertexArray *ligne4 = create_line(map2d[j + 1][i], map2d[j][i]);
	sfRenderWindow_drawVertexArray(window, ligne1, NULL);
	sfRenderWindow_drawVertexArray(window, ligne2, NULL);
	sfRenderWindow_drawVertexArray(window, ligne3, NULL);
	sfRenderWindow_drawVertexArray(window, ligne4, NULL);
	sfVertexArray_destroy(ligne1);
	sfVertexArray_destroy(ligne2);
	sfVertexArray_destroy(ligne3);
	sfVertexArray_destroy(ligne4);
}

void draw_tile(sfRenderWindow *window, map_t *map, sfVector2f map_pos)
{
	int y = (int)map_pos.y;
	int x = (int)map_pos.x;
	int value = 30;

	if (x < value)
		x = value;
	if (y < value)
		y = value;
	for (int j = y - value ; j < y + value && j < map->max.y - 1; j++)
		for (int i = x - value; i < x + value && i < map->max.x - 1; i++) {
			draw_vertex_square(window, i, j, map);
			sfRenderWindow_drawConvexShape(window
				, map->tile[j][i].shape1, NULL);
			sfRenderWindow_drawConvexShape(window
				, map->tile[j][i].shape2, NULL);
			sfRenderWindow_drawConvexShape(window, map->map[j][i],
					NULL);
		}
}
