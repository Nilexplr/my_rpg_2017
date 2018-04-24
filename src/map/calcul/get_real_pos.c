/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** get_real_pos.c
*/

#include "map.h"

float get_middle(map_t *map, sfVector2f pos_map)
{
	int i = pos_map.y;
	int j = pos_map.x;
	float point_a = map->map3d[i][j];
	float point_b = map->map3d[i + 1][j];
	float point_c = map->map3d[i][j + 1];
	float point_d = map->map3d[i + 1][j + 1];

	return ((point_a + point_b + point_c + point_d) / 4);
}

sfVector2f get_real_pos(map_t *map, sfVector2f pos_map)
{
	sfVector2f angle = { 45, 20};
	float z = get_middle(map, pos_map);
	sfVector2f pos = project_iso_point(60 * (pos_map.x + 0.5)
		, 60 * (pos_map.y + 0.5)
		, z * 100, angle);

	pos.x += 600;
	pos.y += 100;
	return (pos);
}
