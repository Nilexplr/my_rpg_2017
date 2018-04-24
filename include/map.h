/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** map.h
*/

#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.h>
#include <math.h>
#include <stdbool.h>
#define RADIAN(x) (x * M_PI / 180)
#define REF_MAP -10.141111
#define X_MAX 257
#define Y_MAX 257
#define SPEED_VIEW 5
#define SIGN(x) (x < 0 ? -1 : 1)
#define MAX_OBJ_IN_MAP 10

typedef struct tile_s {
	sfVector2f middle;
	bool dispo;
	sfConvexShape *shape1;
	sfConvexShape *shape2;
}tile_t;

typedef struct map_s {
	float ** map3d;
	sfVector2f **map2d;
	sfVector2f **water;
	sfConvexShape ***map;
	sfVector2f max;
	sfVector2f pos;
	struct tile_s **tile;
	sfVector2f zoom;
	sfVector2f angle;
	sfTexture *texture;
	void *obj_drop;
}map_t;

sfVector2f project_iso_point(float x, float y, float z, sfVector2f angle);
void map3d_to_2d(map_t *map);
tile_t create_tile(sfVector2f **points, int y, int x, float **map3d);
void choose_triangle(sfVector2f *point, sfConvexShape *shape1
	, sfConvexShape *shape2, float *map3d);
tile_t **create_tile_map(sfVector2f **map_2d, sfVector2f counter
	, float **map3d);
void draw_tile(sfRenderWindow *window, map_t *map, sfVector2f );
void map_2d_to_3d(map_t *map);
void draw_tile(sfRenderWindow *window, map_t *map, sfVector2f map_pos);
void draw_vertex_square(sfRenderWindow *window, int i, int j, map_t *map);
sfVertexArray *create_line(sfVector2f point1, sfVector2f point2);
void destroy_map(map_t *map);
void save_the_map(map_t *map);
float **load_the_map(void);
sfConvexShape ***create_convex_map(sfVector2f **map_2d, sfVector2f counter);

float **create_map(int, int);
// create a map of float of int line and int colum

void free_map(float **);
// free the map

float **create_map_from_file(void *);
// create a map and fill it from a file

int save_map(char const *, float **, float);
// write a serie of float in a file

map_t *init_map(float **map_3d);
// create a 2d map

int map_size(int mode);
// add or rmv value from size

void draw_map(sfRenderWindow *window, map_t *map);
// draw the map into the window

void display_map(sfRenderWindow *, map_t *);
// display the scene of map

sfVector2f **create_2d_map(float **map_3d, sfVector2f counter);

int compare_float(float nb1, float nb2, float precision);

sfVector2f get_real_pos(map_t *map, sfVector2f pos_map);

int inside_triangle(sfConvexShape *triangle, sfVector2i mouse);

sfVector2f get_tuile(void *objet, sfVector2i mouse);
void full_up_map(map_t *map);



#endif /* !MAP_H  */
