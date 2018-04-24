/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Include file of all the in game HUD
*/

#ifndef HUD_H
#define HUD_H

#include "menu.h"
#include "colors.h"
#include "resources.h"

typedef menu_t hud_t;

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
#define NB_FOREGROUND 7
#define POS_FOREGROUND_1 {480, 918}
#define POS_FOREGROUND_2 {480, 1035}
#define POS_FOREGROUND_3 {480, 1035}
#define POS_FOREGROUND_4 {555, 928}
#define POS_FOREGROUND_5 {555, 928}
#define POS_FOREGROUND_6 {555, 980}
#define POS_FOREGROUND_7 {555, 980}
#define COLOR_FOREGROUND_1 COLOR_DARK_BLUE
#define COLOR_FOREGROUND_2 COLOR_LIGHT_BLUE
#define COLOR_FOREGROUND_3 COLOR_PURPLE
#define COLOR_FOREGROUND_4 COLOR_LIGHT_BLUE
#define COLOR_FOREGROUND_5 COLOR_GREEN
#define COLOR_FOREGROUND_6 COLOR_LIGHT_BLUE
#define COLOR_FOREGROUND_7 COLOR_BLUE_LIGHT
#define SIZE_FOREGROUND_1 {960, 162}
#define SIZE_FOREGROUND_2 {960, 45}
#define SIZE_FOREGROUND_3 {5, 45}
#define SIZE_FOREGROUND_4 {400, 45}
#define SIZE_FOREGROUND_5 {5, 45}
#define SIZE_FOREGROUND_6 {400, 45}
#define SIZE_FOREGROUND_7 {5, 45}
#define POS_FOREGROUND {POS_FOREGROUND_1, POS_FOREGROUND_2, POS_FOREGROUND_3,\
		POS_FOREGROUND_4, POS_FOREGROUND_5, POS_FOREGROUND_6,\
		POS_FOREGROUND_7}
#define COLOR_FOREGROUND {COLOR_FOREGROUND_1, COLOR_FOREGROUND_2,\
	COLOR_FOREGROUND_3, COLOR_FOREGROUND_4, COLOR_FOREGROUND_5,\
	COLOR_FOREGROUND_6, COLOR_FOREGROUND_7}
#define SIZE_FOREGROUND {SIZE_FOREGROUND_1, SIZE_FOREGROUND_2,\
	SIZE_FOREGROUND_3, SIZE_FOREGROUND_4, SIZE_FOREGROUND_5,\
	SIZE_FOREGROUND_6, SIZE_FOREGROUND_7}

/* ---- BUTTON ---- */
#define NB_BUTTON 4
#define POS_BUTTON_1 {1000, 930}
#define POS_BUTTON_2 {1110, 930}
#define POS_BUTTON_3 {1225, 930}
#define POS_BUTTON_4 {1335, 930}
#define COLOR_BUTTON_1 sfWhite
#define COLOR_BUTTON_2 sfWhite
#define COLOR_BUTTON_3 sfWhite
#define COLOR_BUTTON_4 sfWhite
#define SIZE_BUTTON_1 {80, 80}
#define SIZE_BUTTON_2 {80, 80}
#define SIZE_BUTTON_3 {80, 80}
#define SIZE_BUTTON_4 {80, 80}
#define POS_BUTTON {POS_BUTTON_1, POS_BUTTON_2, POS_BUTTON_3, POS_BUTTON_4}
#define COLOR_BUTTON {COLOR_BUTTON_1, COLOR_BUTTON_2, COLOR_BUTTON_3,\
	COLOR_BUTTON_4}
#define SIZE_BUTTON {SIZE_BUTTON_1, SIZE_BUTTON_2, SIZE_BUTTON_3,\
	SIZE_BUTTON_4}
#define OVER_COLOR_CHANGE 25

/* ---- TEXT ---- */
#define NB_TEXT 2
#define POS_TEXT_1 {485, 928}
#define POS_TEXT_2 {485, 980}
#define COLOR_TEXT_1 COLOR_LIGHT_GREY
#define COLOR_TEXT_2 COLOR_LIGHT_GREY
#define SIZE_TEXT_1 {40, 40}
#define SIZE_TEXT_2 {40, 40}
#define STR_TEXT_1 "HP"
#define STR_TEXT_2 "MA"
#define SIZE_TEXT_MAX 1000
#define POS_TEXT {POS_TEXT_1, POS_TEXT_2}
#define COLOR_TEXT {COLOR_TEXT_1, COLOR_TEXT_2}
#define SIZE_TEXT {SIZE_TEXT_1, SIZE_TEXT_2}
#define STR_TEXT {STR_TEXT_1, STR_TEXT_2}
#define FONT_TEXT FONT_REGULAR

/* -------------------------------------------------------------- */
/* ------------- HERE BEGINS THE PLAY_MENU'S FUNCTIONS ---------- */
/* -------------------------------------------------------------- */

void move_hud_view(hud_t *hud, sfView *view);
void update_hud(hud_t *hud, window_t *window, player_t *player);
void update_hud_component(hud_t *hud, player_t *player);
hud_t *init_hud(void);
void update_component(hud_t *hud, player_t *player);
void init_image_hud(button_t **button, hud_t *hud);
void event_hud(game_t *game, sfRenderWindow *window, hud_t *hud, sfEvent evt);

#endif /* end of include guard: HUD_H */
