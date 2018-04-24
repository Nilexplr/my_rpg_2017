/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Setting menu functions and macros
*/

#ifndef SETTING_MENU_H
#define SETTING_MENU_H

#include "resources.h"
#include "game_info.h"
#include "menu.h"
#include "colors.h"

/* -------------------------------------------------------------- */
/* ------------ HERE BEGINS THE SETTING_MENU'S MARCOS ------------- */
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
#define POS_FOREGROUND_2 {725, 300}
#define COLOR_FOREGROUND_1 COLOR_DARK_BLUE
#define COLOR_FOREGROUND_2 COLOR_DARK_BLUE
#define SIZE_FOREGROUND_1 {1000, 950}
#define SIZE_FOREGROUND_2 {950, 450}
#define POS_FOREGROUND {POS_FOREGROUND_1, POS_FOREGROUND_2}
#define COLOR_FOREGROUND {COLOR_FOREGROUND_1, COLOR_FOREGROUND_2}
#define SIZE_FOREGROUND {SIZE_FOREGROUND_1, SIZE_FOREGROUND_2}

/* ---- BUTTON ---- */
#define NB_BUTTON 6
#define POS_BUTTON_1 {725, 875}
#define POS_BUTTON_2 {1750, 25}
#define POS_BUTTON_3 {775, 425}
#define POS_BUTTON_4 {775, 600}
#define POS_BUTTON_5 {1300, 425}
#define POS_BUTTON_6 {1300, 600}
#define COLOR_BUTTON_1 COLOR_DARK_GREEN
#define COLOR_BUTTON_2 COLOR_DARK_GREEN
#define COLOR_BUTTON_3 COLOR_DARK_GREEN
#define COLOR_BUTTON_4 COLOR_DARK_GREEN
#define COLOR_BUTTON_5 COLOR_DARK_GREEN
#define COLOR_BUTTON_6 COLOR_DARK_GREEN
#define SIZE_BUTTON_1 {150, 100}
#define SIZE_BUTTON_2 {150, 75}
#define SIZE_BUTTON_3 {320, 100}
#define SIZE_BUTTON_4 {320, 100}
#define SIZE_BUTTON_5 {320, 100}
#define SIZE_BUTTON_6 {320, 100}
#define POS_BUTTON {POS_BUTTON_1, POS_BUTTON_2, POS_BUTTON_3, POS_BUTTON_4,\
			POS_BUTTON_5, POS_BUTTON_6}
#define COLOR_BUTTON {COLOR_BUTTON_1, COLOR_BUTTON_2, COLOR_BUTTON_3,\
		COLOR_BUTTON_4, COLOR_BUTTON_5, COLOR_BUTTON_6}
#define SIZE_BUTTON {SIZE_BUTTON_1, SIZE_BUTTON_2, SIZE_BUTTON_3,\
		SIZE_BUTTON_4, SIZE_BUTTON_5, SIZE_BUTTON_6}
#define OVER_COLOR_CHANGE 25

/* ---- TEXT ---- */
#define NB_TEXT 10
#define POS_TEXT_1 {970, 70}
#define POS_TEXT_2 {750, 230}
#define POS_TEXT_3 {740, 885}
#define POS_TEXT_4 {1770, 25}
#define POS_TEXT_5 {800, 330}
#define POS_TEXT_6 {890, 420}
#define POS_TEXT_7 {880, 600}
#define POS_TEXT_8 {1370, 330}
#define POS_TEXT_9 {1405, 435}
#define POS_TEXT_10 {1405, 610}
#define COLOR_TEXT_1 COLOR_LIGHT_GREY
#define COLOR_TEXT_2 COLOR_LIGHT_WHITE
#define COLOR_TEXT_3 COLOR_LIGHT_WHITE
#define COLOR_TEXT_4 COLOR_LIGHT_WHITE
#define COLOR_TEXT_5 COLOR_LIGHT_GREY
#define COLOR_TEXT_6 COLOR_LIGHT_WHITE
#define COLOR_TEXT_7 COLOR_LIGHT_WHITE
#define COLOR_TEXT_8 COLOR_LIGHT_WHITE
#define COLOR_TEXT_9 COLOR_LIGHT_GREY
#define COLOR_TEXT_10 COLOR_LIGHT_WHITE
#define SIZE_TEXT_1 {100, 75}
#define SIZE_TEXT_2 {40, 50}
#define SIZE_TEXT_3 {60, 50}
#define SIZE_TEXT_4 {50, 40}
#define SIZE_TEXT_5 {60, 75}
#define SIZE_TEXT_6 {70, 50}
#define SIZE_TEXT_7 {70, 50}
#define SIZE_TEXT_8 {60, 40}
#define SIZE_TEXT_9 {60, 75}
#define SIZE_TEXT_10 {60, 50}
#define STR_TEXT_1 "Settings"
#define STR_TEXT_2 ""
#define STR_TEXT_3 "Back"
#define STR_TEXT_4 "Quit"
#define STR_TEXT_5 "Framerate"
#define STR_TEXT_6 "60"
#define STR_TEXT_7 "120"
#define STR_TEXT_8 "Sound"
#define STR_TEXT_9 "ON"
#define STR_TEXT_10 "OFF"
#define SIZE_TEXT_MAX 1000
#define POS_TEXT {POS_TEXT_1, POS_TEXT_2, POS_TEXT_3, POS_TEXT_4, POS_TEXT_5,\
	POS_TEXT_6, POS_TEXT_7, POS_TEXT_8, POS_TEXT_9, POS_TEXT_10}
#define COLOR_TEXT {COLOR_TEXT_1, COLOR_TEXT_2, COLOR_TEXT_3, COLOR_TEXT_4,\
	COLOR_TEXT_5, COLOR_TEXT_6, COLOR_TEXT_7, COLOR_TEXT_8, COLOR_TEXT_9,\
	COLOR_TEXT_10}
#define SIZE_TEXT {SIZE_TEXT_1, SIZE_TEXT_2, SIZE_TEXT_3, SIZE_TEXT_4,\
	SIZE_TEXT_5, SIZE_TEXT_6, SIZE_TEXT_7, SIZE_TEXT_8, SIZE_TEXT_9,\
	SIZE_TEXT_10}
#define STR_TEXT {STR_TEXT_1, STR_TEXT_2, STR_TEXT_3, STR_TEXT_4, STR_TEXT_5,\
	STR_TEXT_6, STR_TEXT_7, STR_TEXT_8, STR_TEXT_9, STR_TEXT_10}
#define FONT_TEXT FONT_REGULAR

/* ------------- HERE BEGINS THE SETTING_MENU'S FUNCTIONS ------------- */

int setting_menu(game_t *game, menu_t *main_menu);
menu_t *initialisation_setting_menu(game_t *game);
void verbose_setting_menu_init_ok(game_t *game);
void verbose_setting_menu_init_fail(game_t *game);
unsigned int get_event_setting_menu(game_t *game, menu_t *menu);
void detail_init_setting_menu(menu_t *menu);
int event_button_setting_menu(game_t *game, menu_t *menu, sfEvent event);
int back_choice_setting_menu(game_t *game, menu_t *menu, int i, sfEvent event);
int quit_choice_setting_menu(game_t *game, menu_t *menu, int i, sfEvent event);
int frame_high_setting_menu(game_t *game, menu_t *menu, int i, sfEvent event);
int frame_med_setting_menu(game_t *game, menu_t *menu, int i, sfEvent event);
int on_sound_setting_menu(game_t *game, menu_t *menu, int i, sfEvent event);
int off_sound_setting_menu(game_t *game, menu_t *menu, int i, sfEvent event);

#endif /* end of include guard: HOW_MENU_H */
