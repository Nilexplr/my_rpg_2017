/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Play menu functions and macros
*/

#ifndef PLAY_MENU_H
#define PLAY_MENU_H

#include "resources.h"
#include "game_info.h"
#include "menu.h"
#include "colors.h"
#include "player.h"

/* -------------------------------------------------------------- */
/* ------------- HERE BEGINS THE PLAY_MENU'S MARCOS ------------- */
/* -------------------------------------------------------------- */

/* ---- BACKGROUND ---- */
#define NB_BACKGROUND 0
#define POS_BACKGROUND_1 {0, 0}
#define PATH_BACKGROUND_1 NULL
#define SIZE_MAX_PATH_BACKGROUND 0
#define POS_BACKGROUND {POS_BACKGROUND_1}
#define PATH_BACKGROUND {PATH_BACKGROUND_1}

/* ---- FOREGROUND ---- */
#define NB_FOREGROUND 2
#define POS_FOREGROUND_1 {700, 50}
#define POS_FOREGROUND_2 {1100, 425}
#define COLOR_FOREGROUND_1 COLOR_DARK_BLUE
#define COLOR_FOREGROUND_2 COLOR_LIGHTER_BLUE
#define SIZE_FOREGROUND_1 {1025, 950}
#define SIZE_FOREGROUND_2 {500, 100}
#define POS_FOREGROUND {POS_FOREGROUND_1, POS_FOREGROUND_2}
#define COLOR_FOREGROUND {COLOR_FOREGROUND_1, COLOR_FOREGROUND_2}
#define SIZE_FOREGROUND {SIZE_FOREGROUND_1, SIZE_FOREGROUND_2}

/* ---- BUTTON ---- */
#define NB_BUTTON 3
#define POS_BUTTON_1 {725, 875}
#define POS_BUTTON_2 {1750, 25}
#define POS_BUTTON_3 {1350, 825}
#define COLOR_BUTTON_1 COLOR_DARK_GREEN
#define COLOR_BUTTON_2 COLOR_DARK_GREEN
#define COLOR_BUTTON_3 COLOR_DARK_GREEN
#define SIZE_BUTTON_1 {150, 100}
#define SIZE_BUTTON_2 {150, 75}
#define SIZE_BUTTON_3 {350, 150}
#define POS_BUTTON {POS_BUTTON_1, POS_BUTTON_2, POS_BUTTON_3}
#define COLOR_BUTTON {COLOR_BUTTON_1, COLOR_BUTTON_2, COLOR_BUTTON_3}
#define SIZE_BUTTON {SIZE_BUTTON_1, SIZE_BUTTON_2, SIZE_BUTTON_3}
#define OVER_COLOR_CHANGE 25

/* ---- TEXT ---- */
#define NB_TEXT 7
#define POS_TEXT_1 {1080, 70}
#define POS_TEXT_2 {750, 230}
#define POS_TEXT_3 {750, 440}
#define POS_TEXT_4 {1110, 440}
#define POS_TEXT_5 {1400, 850}
#define POS_TEXT_6 {740, 885}
#define POS_TEXT_7 {1770, 25}
#define COLOR_TEXT_1 COLOR_LIGHT_GREY
#define COLOR_TEXT_2 COLOR_LIGHT_WHITE
#define COLOR_TEXT_3 COLOR_LIGHT_WHITE
#define COLOR_TEXT_4 COLOR_LIGHT_WHITE
#define COLOR_TEXT_5 COLOR_LIGHT_WHITE
#define COLOR_TEXT_6 COLOR_LIGHT_WHITE
#define COLOR_TEXT_7 COLOR_LIGHT_WHITE
#define SIZE_TEXT_1 {100, 75}
#define SIZE_TEXT_2 {45, 50}
#define SIZE_TEXT_3 {55, 50}
#define SIZE_TEXT_4 {50, 50}
#define SIZE_TEXT_5 {75, 50}
#define SIZE_TEXT_6 {60, 50}
#define SIZE_TEXT_7 {50, 40}
#define STR_TEXT_1 "Play"
#define STR_TEXT_2 "You have no savegame yet ...\nLet's create one !"
#define STR_TEXT_3 "Your name :"
#define STR_TEXT_4 ""
#define STR_TEXT_5 "Let's Go!"
#define STR_TEXT_6 "Back"
#define STR_TEXT_7 "Quit"
#define SIZE_TEXT_MAX 1000
#define POS_TEXT {POS_TEXT_1, POS_TEXT_2, POS_TEXT_3, POS_TEXT_4, POS_TEXT_5,\
		POS_TEXT_6, POS_TEXT_7}
#define COLOR_TEXT {COLOR_TEXT_1, COLOR_TEXT_2, COLOR_TEXT_3, COLOR_TEXT_4,\
		COLOR_TEXT_5, COLOR_TEXT_6, COLOR_TEXT_7}
#define SIZE_TEXT {SIZE_TEXT_1, SIZE_TEXT_2, SIZE_TEXT_3, SIZE_TEXT_4,\
		SIZE_TEXT_5, SIZE_TEXT_6, SIZE_TEXT_7}
#define STR_TEXT {STR_TEXT_1, STR_TEXT_2, STR_TEXT_3, STR_TEXT_4,\
		STR_TEXT_5, STR_TEXT_6, STR_TEXT_7}
#define FONT_TEXT FONT_REGULAR

/* ------------- HERE BEGINS THE PLAY_MENU'S FUNCTIONS ------------- */

int play_menu(game_t *game, menu_t *main_menu);
menu_t *initialisation_play_menu(game_t *game);
void verbose_play_menu_init_ok(game_t *game);
void verbose_play_menu_init_fail(game_t *game);
unsigned int get_event_play_menu(game_t *game, menu_t *menu);
void detail_init_play_menu(menu_t *menu);
int event_button_play_menu(game_t *game, menu_t *menu, sfEvent event);
int back_choice_play_menu(game_t *game, menu_t *menu, int i, sfEvent event);
int quit_choice_play_menu(game_t *game, menu_t *menu, int i, sfEvent event);
int play_choice_play_menu(game_t *game, menu_t *menu, int i, sfEvent event);
void detail_init_old_play_menu(player_t *player, menu_t *menu);

#endif /* end of include guard: PLAY_MENU_H */
