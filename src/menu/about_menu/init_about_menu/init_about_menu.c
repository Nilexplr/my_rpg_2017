/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** initialisation of the menu "about" in the main menu
*/

#include <stdlib.h>
#include "menu.h"
#include "about_menu.h"

// INITIALISATION OF THE ABOUT MAIN MENU'S BACKGROUND
static background_t **init_background(background_t **background, menu_t *menu)
{
	menu->number_background = NB_BACKGROUND;
	background = NULL;
	return (background);
}

// INITIALISATION OF THE ABOUT MAIN MENU'S FOREGROUND
static button_t **init_foreground(button_t **foreground, menu_t *menu)
{
	sfVector2f pos[NB_FOREGROUND] = POS_FOREGROUND;
	sfColor color[NB_FOREGROUND] = COLOR_FOREGROUND;
	sfVector2f size[NB_FOREGROUND] = SIZE_FOREGROUND;

	menu->number_foreground = NB_FOREGROUND;
	foreground = malloc(sizeof(button_t *) * (NB_FOREGROUND + 1));
	if (foreground == NULL)
		return (NULL);
	for (int i = 0; i < NB_FOREGROUND; i++) {
		foreground[i] = malloc(sizeof(button_t));
		if (foreground[i] == NULL)
			return (NULL);
		if (create_button(foreground[i], pos[i]) < 0)
			return (NULL);
		add_detail_button(foreground[i], color[i], size[i]);
	}
	foreground[NB_FOREGROUND] = NULL;
	return (foreground);
}


// INITIALISATION OF THE ABOUT MAIN MENU'S BUTTONS
static button_t **init_button(button_t **button, menu_t *menu)
{
	sfVector2f pos[NB_BUTTON] = POS_BUTTON;
	sfColor color[NB_BUTTON] = COLOR_BUTTON;
	sfVector2f size[NB_BUTTON] = SIZE_BUTTON;

	menu->number_button = NB_BUTTON;
	button = malloc(sizeof(button_t *) * (NB_BUTTON + 1));
	if (button == NULL)
		return (NULL);
	for (int i = 0; i < NB_BUTTON; i++) {
		button[i] = malloc(sizeof(button_t));
		if (button[i] == NULL)
			return (NULL);
		if (create_button(button[i], pos[i]) < 0)
			return (NULL);
		add_detail_button(button[i], color[i], size[i]);
	}
	button[NB_BUTTON] = NULL;
	return (button);
}

// INITIALISATION OF THE ABOUT MAIN MENU'S TEXTS
static text_t **init_text(text_t **text, menu_t *menu)
{
	sfVector2f pos[NB_TEXT] = POS_TEXT;
	sfColor color[NB_TEXT] = COLOR_TEXT;
	sfVector2f size[NB_TEXT] = SIZE_TEXT;
	char str[NB_TEXT][SIZE_TEXT_MAX] = STR_TEXT;

	menu->number_text = NB_TEXT;
	text = malloc(sizeof(text_t *) * (NB_TEXT + 1));
	if (text == NULL)
		return (NULL);
	for (int i = 0; i < NB_TEXT; i++) {
		text[i] = malloc(sizeof(text_t));
		if (text[i] == NULL)
			return (NULL);
		if (create_text(text[i], pos[i], FONT_TEXT, str[i]) < 0)
			return (NULL);
		add_detail_text(text[i], color[i], size[i]);
	}
	text[NB_TEXT] = NULL;
	return (text);
}

void detail_init_about_menu(menu_t *menu)
{
	menu->background = init_background(menu->background, menu);
	menu->foreground = init_foreground(menu->foreground, menu);
	menu->button = init_button(menu->button, menu);
	menu->text = init_text(menu->text, menu);
	menu->display = display_menu;
	menu->destroy = free_menu;
	menu->looping = true;
	menu->code = OK;
}
