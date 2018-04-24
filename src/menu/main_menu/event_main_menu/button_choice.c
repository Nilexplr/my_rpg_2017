/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Analyse the user choice when he clicked on a button in the main menu
*/

#include "game_info.h"
#include "menu.h"
#include "main_menu.h"

int play_choice(game_t *game, menu_t *menu, int i, sfEvent event)
{
	sfColor def_color = COLOR_BUTTON_4;
	int err = 1;

	if (event.type == sfEvtMouseButtonPressed)
		set_button_clicked(menu->button[i], def_color);
	if (event.type == sfEvtMouseButtonReleased)
		err = play_menu(game, menu);
	if (err == 0) {
		menu->code = QUIT_GAME;
		menu->looping = false;
	} else if(err == 84) {
		menu->code = ERROR;
		menu->looping = false;
	}
	if (err == 2) {
		menu->code = QUIT_MENU;
		menu->looping = false;
	}
	return (0);
}

int tuto_choice(game_t *game, menu_t *menu, int i, sfEvent event)
{
	sfColor def_color = COLOR_BUTTON_2;
	int err = 1;

	if (event.type == sfEvtMouseButtonPressed)
		set_button_clicked(menu->button[i], def_color);
	if (event.type == sfEvtMouseButtonReleased)
		err = how_menu(game, menu);
	if (err == 0) {
		menu->code = QUIT_GAME;
		menu->looping = false;
	} else if(err == 84) {
		menu->code = ERROR;
		menu->looping = false;
	}
	return (0);
}

int settings_choice(game_t *game, menu_t *menu, int i, sfEvent event)
{
	sfColor def_color = COLOR_BUTTON_3;
	int err = 1;

	if (event.type == sfEvtMouseButtonPressed)
		set_button_clicked(menu->button[i], def_color);
	if (event.type == sfEvtMouseButtonReleased)
		err = setting_menu(game, menu);
	if (err == 0) {
		menu->code = QUIT_GAME;
		menu->looping = false;
	} else if(err == 84) {
		menu->code = ERROR;
		menu->looping = false;
	}
	return (0);
}

int about_choice(game_t *game, menu_t *menu, int i, sfEvent event)
{
	sfColor def_color = COLOR_BUTTON_4;
	int err = 1;

	if (event.type == sfEvtMouseButtonPressed)
		set_button_clicked(menu->button[i], def_color);
	if (event.type == sfEvtMouseButtonReleased)
		err = about_menu(game, menu);
	if (err == 0) {
		menu->code = QUIT_GAME;
		menu->looping = false;
	} else if(err == 84) {
		menu->code = ERROR;
		menu->looping = false;
	}
	return (0);
}

int quit_choice(game_t *game, menu_t *menu, int i, sfEvent event)
{
	sfColor def_color = COLOR_BUTTON_5;

	if (event.type == sfEvtMouseButtonPressed)
		set_button_clicked(menu->button[i], def_color);
	if (event.type == sfEvtMouseButtonReleased)
		quit_main_menu(menu);
	return (0);
}
