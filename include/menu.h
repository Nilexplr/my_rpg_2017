/*
** EPITECH PROJECT, 2017
** filename
** File description
** Include file of the menu structure.
*/

#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "game_info.h"
#include "window.h"

typedef struct text_s {
	sfText *text;
	sfFont *font;
	sfVector2f position;
	sfVector2f size;
	sfColor color;
	char *str;
} text_t;

typedef struct button_s {
	sfRectangleShape *shape;
	sfColor color;
	sfVector2f position;
	sfVector2f size;
} button_t;

typedef struct background_s {
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f position;
} background_t;

typedef enum code_s {
	OK,
	ERROR,
	QUIT_GAME,
	QUIT_MENU
} code_t;

typedef struct menu_s {
	text_t **text;
	button_t **button;
	button_t **foreground;
	background_t **background;
	unsigned int number_button;
	unsigned int number_text;
	unsigned int number_background;
	unsigned int number_foreground;
	bool looping;
	code_t code;
	void (*display)(sfRenderWindow*, struct menu_s*, bool);
	void (*destroy)(struct menu_s*);
} menu_t;

typedef struct redirect_button_s {
	int nb;
	int (*menu)(game_t *, menu_t *, int, sfEvent);
} redirect_t;

void add_detail_button(button_t *but, sfColor color, sfVector2f size);
void add_detail_text(text_t *text, sfColor color, sfVector2f size);
int create_button(button_t *button, sfVector2f pos);
void destroy_button(button_t *button);
int create_text(text_t *text, sfVector2f pos, char *font_path, char *string);
void destroy_text(text_t *text);
int create_background(background_t *background, sfVector2f pos, char *path);
void display_menu(sfRenderWindow *window, menu_t *menu, bool display);
void free_menu(menu_t *menu);
void fly_over_button(game_t *game, menu_t *menu, sfColor *def_col, int modif);
void event_close(sfEvent event, menu_t *menu);
void set_button_clicked(button_t *button, sfColor def_color);
void menu_faded_appear(game_t *game, menu_t *menu, menu_t *main_menu);
void menu_faded_disappear(game_t *game, menu_t *menu, menu_t *main_menu);
void text_box(char *str, sfEvent event, text_t *text, int max);

/* ---- ALL DIFFERENT MENU IN GAME ---- */
int main_menu(game_t *game);
int about_menu(game_t *game, menu_t *main_menu);
int play_menu(game_t *game, menu_t *main_menu);
int setting_menu(game_t *game, menu_t *main_menu);
int how_menu(game_t *game, menu_t *main_menu);

#endif /* end of include guard: MENU_H */
