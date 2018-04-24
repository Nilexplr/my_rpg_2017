/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include "resources.h"
#include "game_info.h"
#include "menu.h"
#include "game_object.h"
#include <stdlib.h>

/* -------------------------------------------------------------- */
/* ------------- HERE BEGINS THE INVENTORY'S MACROS ------------- */
/* -------------------------------------------------------------- */

/* ---- BACKGROUND ---- */
#define NB_BACKGROUND 1
#define POS_BACKGROUND_1 {400, 150}
#define PATH_BACKGROUND_1 INVENTORY_TEST
#define SIZE_MAX_PATH_BACKGROUND 36
#define POS_BACKGROUND {POS_BACKGROUND_1}
#define PATH_BACKGROUND {PATH_BACKGROUND_1}
/* ---- FOREGROUND ---- */
#define NB_FOREGROUND 0
#define POS_FOREGROUND_1 {100, 100}
//#define POS_FOREGROUND_2 {200, 100}
#define COLOR_FOREGROUND_1 sfRed
//#define COLOR_FOREGROUND_2 sfRed
#define SIZE_FOREGROUND_1 {0, 0}
//#define SIZE_FOREGROUND_2 {100, 100}
#define POS_FOREGROUND {}
#define COLOR_FOREGROUND {}
#define SIZE_FOREGROUND {}
/* ---- BUTTON ---- */
#define NB_BUTTON 1
#define POS_BUTTON_1 {1700, 50}
#define COLOR_BUTTON_1 sfRed
#define SIZE_BUTTON_1 {150, 80}
#define POS_BUTTON {POS_BUTTON_1}
#define COLOR_BUTTON {COLOR_BUTTON_1}
#define SIZE_BUTTON {SIZE_BUTTON_1}
/* ---- TEXT ---- */
#define NB_TEXT 1
#define POS_TEXT_1 {1710, 60}
#define COLOR_TEXT_1 sfWhite
#define SIZE_TEXT_1 {50, 100}
#define STR_TEXT_1 "BACK"
#define SIZE_TEXT_MAX 4
#define POS_TEXT {POS_TEXT_1}
#define COLOR_TEXT {COLOR_TEXT_1}
#define SIZE_TEXT {SIZE_TEXT_1}
#define STR_TEXT {STR_TEXT_1}
#define FONT_TEXT FONT_BLACK_ITALIC

/* ------------- HERE BEGINS THE INVENTORY'S FUNCTIONS ------------- */

int inventory(game_t *game);
menu_t *initialisation_inventory(game_t *game);
void verbose_inventory_init_ok(game_t *game);
void verbose_inventory_init_fail(game_t *game);

/* ----------------------- INVENTORY_STRUCT ------------------------ */

#define NB_MAX_STUFF_INV 36
#define NB_TEXT_OBJ 5

#define NB_BEGIN_STUFF 2
#define BEGIN_STUFF {ID_1, ID_2}

typedef struct inventory {
	int nb_stuff;
	game_obj_t **obj_in;
	game_obj_t **player_stuff;
}inventory_t;

int event_inventory(game_t *game_info, int choice, inventory_t *inv);
void fly_over_sprite(game_t *game, game_obj_t *obj);
void check_click(sfMouseButtonEvent event, game_obj_t *obj, inventory_t *inv);

#endif /* end of include guard: INVENTORY_H */
