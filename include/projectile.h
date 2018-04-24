/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** projectil prototype
*/

#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <math.h>
#include <SFML/Graphics.h>
#include "collision.h"
#include <stdbool.h>

#define LIFETIME 4

typedef enum type_shape_s {
	REC,
	CONV,
	CERC,
}type_shape_t;

typedef struct projectile_s {
	type_shape_t shape;
	sfClock *clock;
	sfConvexShape *convex;
	sfRectangleShape *rec;
	sfVector2f pos;
	sfVector2f end;
	sfVector2f mouvement;
	bool from_player;
	float dammage;
	struct projectile_s *next;
	struct projectile_s *prev;
}projectile_t;

float init_rotate(sfVector2f dep, sfVector2f arr);
sfVector2f init_mouvement(sfVector2f dep, sfVector2f arr, int );
void create_projectile(void *game, bool from_player);
void destroy_projectile_charact(projectile_t *obj, float *life);
projectile_t *init_list_proj(void);
void destroy_projectile(projectile_t *obj);

#endif /* !PROJECTILE_H */
