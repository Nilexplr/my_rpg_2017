/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** How menu functions and macros
*/

#ifndef HOW_MENU_H
#define HOW_MENU_H

#include "resources.h"
#include "game_info.h"
#include "menu.h"
#include "colors.h"

/* -------------------------------------------------------------- */
/* ------------ HERE BEGINS THE HOW_MENU'S MARCOS ------------- */
/* -------------------------------------------------------------- */

/* ---- BACKGROUND ---- */
#define NB_BACKGROUND 0
#define POS_BACKGROUND_1 {0, 0}
#define PATH_BACKGROUND_1 NULL
#define SIZE_MAX_PATH_BACKGROUND 0
#define POS_BACKGROUND {POS_BACKGROUND_1}
#define PATH_BACKGROUND {PATH_BACKGROUND_1}

/* ---- FOREGROUND ---- */
#define NB_FOREGROUND 1
#define POS_FOREGROUND_1 {700, 50}
#define COLOR_FOREGROUND_1 COLOR_DARK_BLUE
#define SIZE_FOREGROUND_1 {1000, 950}
#define POS_FOREGROUND {POS_FOREGROUND_1}
#define COLOR_FOREGROUND {COLOR_FOREGROUND_1}
#define SIZE_FOREGROUND {SIZE_FOREGROUND_1}

/* ---- BUTTON ---- */
#define NB_BUTTON 2
#define POS_BUTTON_1 {725, 875}
#define POS_BUTTON_2 {1750, 25}
#define COLOR_BUTTON_1 COLOR_DARK_GREEN
#define COLOR_BUTTON_2 COLOR_DARK_GREEN
#define SIZE_BUTTON_1 {150, 100}
#define SIZE_BUTTON_2 {150, 75}
#define POS_BUTTON {POS_BUTTON_1, POS_BUTTON_2}
#define COLOR_BUTTON {COLOR_BUTTON_1, COLOR_BUTTON_2}
#define SIZE_BUTTON {SIZE_BUTTON_1, SIZE_BUTTON_2}
#define OVER_COLOR_CHANGE 25

/* ---- TEXT ---- */
#define NB_TEXT 6
#define POS_TEXT_1 {960, 70}
#define POS_TEXT_2 {750, 230}
#define POS_TEXT_3 {740, 885}
#define POS_TEXT_4 {1770, 25}
#define COLOR_TEXT_1 COLOR_LIGHT_GREY
#define COLOR_TEXT_2 COLOR_LIGHT_WHITE
#define COLOR_TEXT_3 COLOR_LIGHT_WHITE
#define COLOR_TEXT_4 COLOR_LIGHT_WHITE
#define SIZE_TEXT_1 {100, 75}
#define SIZE_TEXT_2 {40, 50}
#define SIZE_TEXT_3 {60, 50}
#define SIZE_TEXT_4 {50, 40}
#define STR_TEXT_1 "How to play"
#define STR_TEXT_2 "Click to move your character, bla bla bla bla\nBla"\
		"bla bla bla bla"
#define STR_TEXT_3 "Back"
#define STR_TEXT_4 "Quit"
#define SIZE_TEXT_MAX 1000
#define POS_TEXT {POS_TEXT_1, POS_TEXT_2, POS_TEXT_3, POS_TEXT_4}
#define COLOR_TEXT {COLOR_TEXT_1, COLOR_TEXT_2, COLOR_TEXT_3, COLOR_TEXT_4}
#define SIZE_TEXT {SIZE_TEXT_1, SIZE_TEXT_2, SIZE_TEXT_3, SIZE_TEXT_4}
#define STR_TEXT {STR_TEXT_1, STR_TEXT_2, STR_TEXT_3, STR_TEXT_4}
#define FONT_TEXT FONT_REGULAR

/* ------------- HERE BEGINS THE HOW_MENU'S FUNCTIONS ------------- */

int how_menu(game_t *game, menu_t *main_menu);
menu_t *initialisation_how_menu(game_t *game);
void verbose_how_menu_init_ok(game_t *game);
void verbose_how_menu_init_fail(game_t *game);
unsigned int get_event_how_menu(game_t *game, menu_t *menu);
void detail_init_how_menu(menu_t *menu);
int event_button_how_menu(game_t *game, menu_t *menu, sfEvent event);
int back_choice_how_menu(game_t *game, menu_t *menu, int i, sfEvent event);
int quit_choice_how_menu(game_t *game, menu_t *menu, int i, sfEvent event);

#endif /* end of include guard: HOW_MENU_H */
