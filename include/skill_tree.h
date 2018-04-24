/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#ifndef SKILL_TREE_H
#define SKILL_TREE_H

#include "resources.h"
#include "game_info.h"
#include "menu.h"
#include "game_object.h"
#include <stdlib.h>
#include "mylib.h"

/* -------------------------------------------------------------- */
/* ------------- HERE BEGINS THE INVENTORY'S MACROS ------------- */
/* -------------------------------------------------------------- */

/* ---- BACKGROUND ---- */
#define NB_BACKGROUND 10
#define POS_BACKGROUND_1 {200, 150}
#define PATH_BACKGROUND_1 BACK_SKILL_ATT
#define POS_BACKGROUND_2 {700, 150}
#define PATH_BACKGROUND_2 BACK_SKILL_DEF
#define POS_BACKGROUND_3 {1400, 500}
#define PATH_BACKGROUND_3 LIFE_ICONE
#define POS_BACKGROUND_4 {1600, 500}
#define PATH_BACKGROUND_4 DEFENSE_ICONE
#define POS_BACKGROUND_5 {1400, 700}
#define PATH_BACKGROUND_5 MANA_ICONE
#define POS_BACKGROUND_6 {1600, 700}
#define PATH_BACKGROUND_6 ATTAQUE_ICONE
#define POS_BACKGROUND_7 {1613, 713}
#define PATH_BACKGROUND_7 PLUS_ICONE
#define POS_BACKGROUND_8 {1413, 513}
#define PATH_BACKGROUND_8 PLUS_ICONE
#define POS_BACKGROUND_9 {1613, 513}
#define PATH_BACKGROUND_9 PLUS_ICONE
#define POS_BACKGROUND_10 {1413, 713}
#define PATH_BACKGROUND_10 PLUS_ICONE
#define SIZE_MAX_PATH_BACKGROUND 40
#define POS_BACKGROUND {POS_BACKGROUND_1, POS_BACKGROUND_2, POS_BACKGROUND_3,\
	POS_BACKGROUND_4, POS_BACKGROUND_5, POS_BACKGROUND_6, POS_BACKGROUND_7,\
	POS_BACKGROUND_8, POS_BACKGROUND_9, POS_BACKGROUND_10}
#define PATH_BACKGROUND {PATH_BACKGROUND_1, PATH_BACKGROUND_2,\
	PATH_BACKGROUND_3, PATH_BACKGROUND_4, PATH_BACKGROUND_5,\
	PATH_BACKGROUND_6, PATH_BACKGROUND_7, PATH_BACKGROUND_8,\
	PATH_BACKGROUND_9, PATH_BACKGROUND_10}
/* ---- FOREGROUND ---- */
#define NB_FOREGROUND 1
#define POS_FOREGROUND_1 {0, 0}
//#define POS_FOREGROUND_2 {200, 100}
#define COLOR_FOREGROUND_1 sfTransparent
//#define COLOR_FOREGROUND_2
#define SIZE_FOREGROUND_1 {0, 0}
//#define SIZE_FOREGROUND_2 {100, 100}
#define POS_FOREGROUND {POS_FOREGROUND_1}
#define COLOR_FOREGROUND {COLOR_FOREGROUND_1}
#define SIZE_FOREGROUND {SIZE_FOREGROUND_1}
/* ---- BUTTON ---- */
#define NB_BUTTON 1
#define POS_BUTTON_1 {1700, 50}
#define COLOR_BUTTON_1 sfRed
#define SIZE_BUTTON_1 {150, 80}
#define POS_BUTTON {POS_BUTTON_1}
#define COLOR_BUTTON {COLOR_BUTTON_1}
#define SIZE_BUTTON {SIZE_BUTTON_1}
/* ---- TEXT ---- */
#define NB_TEXT 10
#define POS_TEXT_1 {1710, 60}
#define COLOR_TEXT_1 sfWhite
#define SIZE_TEXT_1 {50, 100}
#define STR_TEXT_1 "BACK\0"
#define POS_TEXT_2 {1300, 200}
#define COLOR_TEXT_2 sfRed
#define SIZE_TEXT_2 {50, 50}
#define STR_TEXT_2 "YOUR LEVEL :\0"
#define POS_TEXT_3 {800, 20}
#define COLOR_TEXT_3 sfWhite
#define SIZE_TEXT_3 {100, 100}
#define STR_TEXT_3 "SKILL TREE\0"
#define POS_TEXT_4 {1600, 200}
#define COLOR_TEXT_4 sfWhite
#define SIZE_TEXT_4 {50, 50}
#define STR_TEXT_4 "level_nb\0"
#define POS_TEXT_5 {1300, 500}
#define COLOR_TEXT_5 sfWhite
#define SIZE_TEXT_5 {50, 50}
#define STR_TEXT_5 "life_nb\0"
#define POS_TEXT_6 {1700, 500}
#define COLOR_TEXT_6 sfWhite
#define SIZE_TEXT_6 {50, 50}
#define STR_TEXT_6 "defense_nb\0"
#define POS_TEXT_7 {1300, 700}
#define COLOR_TEXT_7 sfWhite
#define SIZE_TEXT_7 {50, 50}
#define STR_TEXT_7 "mana_nb\0"
#define POS_TEXT_8 {1700, 700}
#define COLOR_TEXT_8 sfWhite
#define SIZE_TEXT_8 {50, 50}
#define STR_TEXT_8 "attaque_nb\0"
#define POS_TEXT_9 {1850, 300}
#define COLOR_TEXT_9 sfWhite
#define SIZE_TEXT_9 {50, 50}
#define STR_TEXT_9 "compet_point\0"
#define POS_TEXT_10 {1300, 300}
#define COLOR_TEXT_10 sfRed
#define SIZE_TEXT_10 {50, 50}
#define STR_TEXT_10 "COMPETENCIES POINT :\0"
#define SIZE_TEXT_MAX 21
#define POS_TEXT {POS_TEXT_1, POS_TEXT_2, POS_TEXT_3, POS_TEXT_4,\
	POS_TEXT_5, POS_TEXT_6, POS_TEXT_7, POS_TEXT_8, POS_TEXT_9, POS_TEXT_10}
#define COLOR_TEXT {COLOR_TEXT_1, COLOR_TEXT_2, COLOR_TEXT_3, COLOR_TEXT_4,\
	COLOR_TEXT_5, COLOR_TEXT_6, COLOR_TEXT_7, COLOR_TEXT_8, COLOR_TEXT_9,\
	COLOR_TEXT_10}
#define SIZE_TEXT {SIZE_TEXT_1, SIZE_TEXT_2, SIZE_TEXT_3, SIZE_TEXT_4,\
	SIZE_TEXT_5, SIZE_TEXT_6, SIZE_TEXT_7, SIZE_TEXT_8, SIZE_TEXT_9,\
	SIZE_TEXT_10}
#define STR_TEXT {STR_TEXT_1, STR_TEXT_2, STR_TEXT_3, STR_TEXT_4, STR_TEXT_5,\
	STR_TEXT_6, STR_TEXT_7, STR_TEXT_8, STR_TEXT_9, STR_TEXT_10}
#define FONT_TEXT FONT_BLACK_ITALIC

int event_skill_tree(menu_t *sk, game_t *game, int choice);
void detail_init_menu_skill_tree(menu_t *menu);
void verbose_skill_tree_init_ok(game_t *game);
void verbose_skill_tree_init_fail(game_t *game);

#endif /* end of include guard: SKILL_TREE_H */
