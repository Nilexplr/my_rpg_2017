/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** __DESCRIPTION__
*/

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <stdbool.h>
#include <SFML/Graphics.h>

#include "menu.h"

#define NB_OBJ 2
#define SIZE_MAX_DESC 18

#define NOT_ARMOR 0
#define HELMET 1
#define ARMS 2
#define CHESTPLATE 3
#define LEGGINGS 4

#define X_POS_HELMET 940
#define X_POS_ARMS 940
#define X_POS_CHESTPLATE 940
#define X_POS_LEGGINGS 940

#define Y_POS_HELMET 190
#define Y_POS_ARMS 280
#define Y_POS_CHESTPLATE 370
#define Y_POS_LEGGINGS 460

#define X_POS_STUFF {X_POS_HELMET, X_POS_ARMS, X_POS_CHESTPLATE, X_POS_LEGGINGS}
#define Y_POS_STUFF {Y_POS_HELMET, Y_POS_ARMS, Y_POS_CHESTPLATE, Y_POS_LEGGINGS}

#define SIZE_MAX_PATH_G_O 40

#define ID_1 1
#define SPRITE_1 SPRITE_TEST
#define TYPE_1 HELMET
#define DESCRIPTION_1 "a pokeball test\0"
#define LIFE_1 "+ 1\0"
#define DEFENSE_1 "+ 1\0"
#define MANA_1 "+ 1\0"
#define ATTAQUE_1 "+ 1\0"

#define ID_2 2
#define SPRITE_2 CHESTPLATE_TEST
#define TYPE_2 CHESTPLATE
#define DESCRIPTION_2 "a chestplate test\0"
#define LIFE_2 "+ 1\0"
#define DEFENSE_2 "+ 5\0"
#define MANA_2 "+ 1\0"
#define ATTAQUE_2 "+ 1\0"

#define ID {ID_1, ID_2}
#define SPRITES_OBJ {SPRITE_1, SPRITE_2}
#define TYPES {TYPE_1, TYPE_2}
#define DESCRIPTIONS {DESCRIPTION_1, DESCRIPTION_2}
#define LIFE {LIFE_1, LIFE_2}
#define DEFENSE {DEFENSE_1, DEFENSE_2}
#define MANA {MANA_1, MANA_2}
#define ATTAQUE {ATTAQUE_1, ATTAQUE_2}

typedef struct game_object {
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f pos;
	sfIntRect rect;
	sfVector2f speed;
	bool is_triggered;
	char *name;
	text_t **text;
	int id;
} game_obj_t;

typedef struct obj_drop {
	int nb_obj_drop;
	game_obj_t **objs_drop;
} obj_drop_t;

game_obj_t *create_game_obj(const char *path, sfVector2f pos, sfIntRect rect,
	int id);
void init_drop(game_t *game);

#endif /* end of include guard: GAME_OBJECT_H */
