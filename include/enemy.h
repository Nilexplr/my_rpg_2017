/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** ennemy structure and prototype
*/

#ifndef ENEMY_H_
#define ENEMY_H_
#include <SFML/Graphics.h>
#include "map.h"
#include "a_star.h"

#define SPAWN 10

/* STATS ENEMY TYPE: SLAYER */
#define X_SLAYER 40
#define Y_SLAYER 80
#define LIFE_SLAYER 100
#define SLAYER_PO 7
#define SLAYER_PM 25
#define SPEED_ATK 6
#define SPEED_SLAYER 2
#define SLAYER_DAMMAGE 10

/* STATS ENEMY TYPE : DOG */
#define X_DOG 50
#define Y_DOG 90
#define LIFE_DOG 100
#define DOG_PO 1
#define DOG_PM 30
#define SPEED_DOG 4
#define DOG_DAMMAGE 10
#define XP_DOG 10

typedef enum type_enemy {
	SLAYER,
	DOG,
	GUARDIAN,
	BOSS,
}type_enemy_t;

#define XP_SLAYER 10

typedef struct enemy_s{
	type_enemy_t type;
	float life;
	bool on_activity;
	sfClock *clock;
	sfVector2f map_pos;
	sfVector2f real_pos;
	sfRectangleShape *shape;
	sfVector2f mouve;
	int speed;
	int size_y;
	struct enemy_s *next;
	struct enemy_s *prev;
	node_t *node;
	int xp;
} enemy_t;

enemy_t *create_slayer(map_t *map, sfVector2f pos_map);
enemy_t *init_enemy_list(void);
void insert_enemy_list(enemy_t *list, enemy_t *enemy);
void destroy_enemy(enemy_t *);
enemy_t *create_dog(map_t *map, sfVector2f pos_map);


#endif /* end of include guard: ENEMY_H_ */
