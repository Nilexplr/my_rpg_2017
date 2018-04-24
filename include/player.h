/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** character prototype and structure
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.h>
#include "collision.h"
#include "a_star.h"

#define POS_X 5
#define POS_Y 5
#define RES_X 10
#define RES_Y 10
#define MAX_USER_CHAR 12

/* --- DEFAULT VALUES --- */
#define DEFAULT_ATTACK 10
#define DEFAULT_DEFENSE 10
#define DEFAULT_SPEED 2
#define DEFAULT_CRITICAL 10
#define DEFAULT_MANA 50
#define DEFAULT_HEALTH 95
#define DEFAULT_EXP 5

typedef struct render_character_s {
	sfVector2f map_pos;
	sfVector2f real_pos;
	sfRectangleShape *shape;
	sfSprite *sprite;
	sfVector2f arr;
	sfVector2f mouve;
} render_t;

typedef enum actual_mission_s {
	INTRO,
	OPEN_WORLD,
	FINAL
} mission_actual_t;

typedef struct player_info_s {
	char name_player[MAX_USER_CHAR + 1];
	int nb_life;
	int level;
	float attack;
	float defense;
	int speed;
	int compet_point;
	int critical;
	int exp;
	int mana;
	float health;
	bool new_savegame;
	mission_actual_t actual_mission;
} player_info_t;

typedef struct player_s {
	player_info_t *info;
	render_t *render_character;
	node_t *mv_list;
	transformed_shape_t *transfo;
} player_t;

sfRectangleShape *create_player(sfVector2f pos);
player_info_t *init_player_info(void);
render_t *init_render_character(sfVector2f, sfVector2f);
void save_player(player_t *player);

/*
** move function
*/

sfVector2f  mouve_to_node(player_t *player);
void destroy_node(player_t *player);


#endif /* !PLAYER_H  */
