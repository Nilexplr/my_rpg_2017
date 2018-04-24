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
#define POS_FOREGROUND_2 {725, 300}
#define COLOR_FOREGROUND_1 COLOR_DARK_BLUE
#define COLOR_FOREGROUND_2 COLOR_LIGHTER_BLUE
#define SIZE_FOREGROUND_1 {1025, 950}
#define SIZE_FOREGROUND_2 {950, 450}
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
#define NB_TEXT 12
#define POS_TEXT_1 {1080, 70}
#define POS_TEXT_2 {750, 230}
#define POS_TEXT_3 {750, 300}
#define POS_TEXT_4 {910, 367}
#define POS_TEXT_5 {960, 500}
#define POS_TEXT_6 {880, 630}
#define POS_TEXT_7 {1380, 367}
#define POS_TEXT_8 {1360, 500}
#define POS_TEXT_9 {1435, 635}
#define POS_TEXT_10 {1400, 850}
#define POS_TEXT_11 {740, 885}
#define POS_TEXT_12 {1770, 25}
#define COLOR_TEXT_1 COLOR_LIGHT_GREY
#define COLOR_TEXT_2 COLOR_LIGHT_WHITE
#define COLOR_TEXT_3 COLOR_LIGHT_WHITE
#define COLOR_TEXT_4 COLOR_LIGHT_GREY
#define COLOR_TEXT_5 COLOR_LIGHT_GREY
#define COLOR_TEXT_6 COLOR_LIGHT_GREY
#define COLOR_TEXT_7 COLOR_LIGHT_GREY
#define COLOR_TEXT_8 COLOR_LIGHT_GREY
#define COLOR_TEXT_9 COLOR_LIGHT_GREY
#define COLOR_TEXT_10 COLOR_LIGHT_WHITE
#define COLOR_TEXT_11 COLOR_LIGHT_WHITE
#define COLOR_TEXT_12 COLOR_LIGHT_WHITE
#define SIZE_TEXT_1 {100, 75}
#define SIZE_TEXT_2 {45, 50}
#define SIZE_TEXT_3 {55, 50}
#define SIZE_TEXT_4 {55, 50}
#define SIZE_TEXT_5 {55, 50}
#define SIZE_TEXT_6 {55, 50}
#define SIZE_TEXT_7 {55, 50}
#define SIZE_TEXT_8 {55, 50}
#define SIZE_TEXT_9 {50, 50}
#define SIZE_TEXT_10 {75, 50}
#define SIZE_TEXT_11 {60, 50}
#define SIZE_TEXT_12 {50, 40}
#define STR_TEXT_1 "Play"
#define STR_TEXT_2 "Welcome back!"
#define STR_TEXT_3 "\t\t\tYour stats\n Name:\t\t\t\t\t\t\t\t\tLevel:\n\n"\
	" HP Max:\t\t\t\t\t\t\t\tEXP:\n\n ATK:\t\t\t\t\t\t\t\t\t\tMission:"
#define STR_TEXT_4 ""
#define STR_TEXT_5 ""
#define STR_TEXT_6 ""
#define STR_TEXT_7 ""
#define STR_TEXT_8 ""
#define STR_TEXT_9 ""
#define STR_TEXT_10 "Continue!"
#define STR_TEXT_11 "Back"
#define STR_TEXT_12 "Quit"
#define SIZE_TEXT_MAX 1000
#define POS_TEXT {POS_TEXT_1, POS_TEXT_2, POS_TEXT_3, POS_TEXT_4, POS_TEXT_5,\
		POS_TEXT_6, POS_TEXT_7, POS_TEXT_8, POS_TEXT_9, POS_TEXT_10,\
		POS_TEXT_11, POS_TEXT_12}
#define COLOR_TEXT {COLOR_TEXT_1, COLOR_TEXT_2, COLOR_TEXT_3, COLOR_TEXT_4,\
		COLOR_TEXT_5, COLOR_TEXT_6, COLOR_TEXT_7, COLOR_TEXT_8,\
		COLOR_TEXT_9, COLOR_TEXT_10, COLOR_TEXT_11, COLOR_TEXT_12}
#define SIZE_TEXT {SIZE_TEXT_1, SIZE_TEXT_2, SIZE_TEXT_3, SIZE_TEXT_4,\
		SIZE_TEXT_5, SIZE_TEXT_6, SIZE_TEXT_7, SIZE_TEXT_8,\
		SIZE_TEXT_9, SIZE_TEXT_10, SIZE_TEXT_11, SIZE_TEXT_12}
#define STR_TEXT {STR_TEXT_1, STR_TEXT_2, STR_TEXT_3, STR_TEXT_4,\
		STR_TEXT_5, STR_TEXT_6, STR_TEXT_7, STR_TEXT_8, STR_TEXT_9,\
		STR_TEXT_10, STR_TEXT_11, STR_TEXT_12}
#define FONT_TEXT FONT_REGULAR

void add_detail_text_old(player_info_t *info, text_t **text);

#endif /* end of include guard: PLAY_MENU_H */
