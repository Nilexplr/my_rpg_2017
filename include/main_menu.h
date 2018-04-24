/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Main menu functions and macros
*/

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "resources.h"
#include "game_info.h"
#include "menu.h"
#include "colors.h"

/* -------------------------------------------------------------- */
/* ------------- HERE BEGINS THE MAIN_MENU'S MARCOS ------------- */
/* -------------------------------------------------------------- */

/* ---- BACKGROUND ---- */
#define NB_BACKGROUND 1
#define POS_BACKGROUND_1 {0, 0}
#define PATH_BACKGROUND_1 MAIN_MENU_BACKGROUND
#define SIZE_MAX_PATH_BACKGROUND 42
#define POS_BACKGROUND {POS_BACKGROUND_1}
#define PATH_BACKGROUND {PATH_BACKGROUND_1}

/* ---- FOREGROUND ---- */
#define NB_FOREGROUND 1
#define POS_FOREGROUND_1 {50, 50}
#define COLOR_FOREGROUND_1 COLOR_DARK_BLUE
#define SIZE_FOREGROUND_1 {600, 950}
#define POS_FOREGROUND {POS_FOREGROUND_1}
#define COLOR_FOREGROUND {COLOR_FOREGROUND_1}
#define SIZE_FOREGROUND {SIZE_FOREGROUND_1}

/* ---- BUTTON ---- */
#define NB_BUTTON 5
#define POS_BUTTON_1 {150, 250}
#define POS_BUTTON_2 {150, 425}
#define POS_BUTTON_3 {150, 600}
#define POS_BUTTON_4 {150, 775}
#define POS_BUTTON_5 {1750, 25}
#define COLOR_BUTTON_1 COLOR_DARK_GREEN
#define COLOR_BUTTON_2 COLOR_DARK_GREEN
#define COLOR_BUTTON_3 COLOR_DARK_GREEN
#define COLOR_BUTTON_4 COLOR_DARK_GREEN
#define COLOR_BUTTON_5 COLOR_DARK_GREEN
#define SIZE_BUTTON_1 {400, 125}
#define SIZE_BUTTON_2 {400, 125}
#define SIZE_BUTTON_3 {400, 125}
#define SIZE_BUTTON_4 {400, 125}
#define SIZE_BUTTON_5 {150, 75}
#define POS_BUTTON {POS_BUTTON_1, POS_BUTTON_2, POS_BUTTON_3,\
	POS_BUTTON_4, POS_BUTTON_5}
#define COLOR_BUTTON {COLOR_BUTTON_1, COLOR_BUTTON_2, COLOR_BUTTON_3,\
	COLOR_BUTTON_4, COLOR_BUTTON_5}
#define SIZE_BUTTON {SIZE_BUTTON_1, SIZE_BUTTON_2, SIZE_BUTTON_3,\
	SIZE_BUTTON_4, SIZE_BUTTON_5}
#define OVER_COLOR_CHANGE 25

/* ---- TEXT ---- */
#define NB_TEXT 6
#define POS_TEXT_1 {120, 90}
#define POS_TEXT_2 {260, 260}
#define POS_TEXT_3 {155, 430}
#define POS_TEXT_4 {210, 610}
#define POS_TEXT_5 {230, 780}
#define POS_TEXT_6 {1770, 25}
#define COLOR_TEXT_1 COLOR_LIGHT_GREY
#define COLOR_TEXT_2 COLOR_LIGHT_WHITE
#define COLOR_TEXT_3 COLOR_LIGHT_WHITE
#define COLOR_TEXT_4 COLOR_LIGHT_WHITE
#define COLOR_TEXT_5 COLOR_LIGHT_WHITE
#define COLOR_TEXT_6 COLOR_LIGHT_WHITE
#define SIZE_TEXT_1 {100, 75}
#define SIZE_TEXT_2 {75, 50}
#define SIZE_TEXT_3 {75, 50}
#define SIZE_TEXT_4 {75, 50}
#define SIZE_TEXT_5 {75, 50}
#define SIZE_TEXT_6 {50, 40}
#define STR_TEXT_1 "Game name"
#define STR_TEXT_2 "Play"
#define STR_TEXT_3 "How to play"
#define STR_TEXT_4 "Settings"
#define STR_TEXT_5 "About"
#define STR_TEXT_6 "Quit"
#define SIZE_TEXT_MAX 13
#define POS_TEXT {POS_TEXT_1, POS_TEXT_2, POS_TEXT_3, POS_TEXT_4, POS_TEXT_5,\
		POS_TEXT_6}
#define COLOR_TEXT {COLOR_TEXT_1, COLOR_TEXT_2, COLOR_TEXT_3, COLOR_TEXT_4,\
		COLOR_TEXT_5, COLOR_TEXT_6}
#define SIZE_TEXT {SIZE_TEXT_1, SIZE_TEXT_2, SIZE_TEXT_3, SIZE_TEXT_4,\
		SIZE_TEXT_5, SIZE_TEXT_6}
#define STR_TEXT {STR_TEXT_1, STR_TEXT_2, STR_TEXT_3, STR_TEXT_4, STR_TEXT_5,\
		STR_TEXT_6}
#define FONT_TEXT FONT_REGULAR

/* ------------- HERE BEGINS THE MAIN_MENU'S FUNCTIONS ------------- */

int main_menu(game_t *game);
menu_t *initialisation_main_menu(game_t *game);
void verbose_main_menu_init_ok(game_t *game);
void verbose_main_menu_init_fail(game_t *game);
unsigned int get_event_main_menu(game_t *game, menu_t *menu);
int quit_choice(game_t *game, menu_t *menu, int i, sfEvent event);
int about_choice(game_t *game, menu_t *menu, int i, sfEvent event);
int settings_choice(game_t *game, menu_t *menu, int i, sfEvent event);
int tuto_choice(game_t *game, menu_t *menu, int i, sfEvent event);
int play_choice(game_t *game, menu_t *menu, int i, sfEvent event);
void detail_init_main_menu(menu_t *menu);
void quit_main_menu(menu_t *menu);
int event_button_main_menu(game_t *game, menu_t *menu, sfEvent event);

#endif /* end of include guard: MAIN_MENU_H */
