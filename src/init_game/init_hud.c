/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Init the whole HUD structure and its menu sub structure
*/

#include <stdlib.h>
#include "hud.h"

// INITIALISATION OF THE HUD'S BACKGROUND
static background_t **init_background(background_t **background, hud_t *hud)
{
	hud->number_background = NB_BACKGROUND;
	background = NULL;
	return (background);
}

// INITIALISATION OF THE HUD'S FOREGROUND
static button_t **init_foreground(button_t **foreground, hud_t *hud)
{
	sfVector2f pos[NB_FOREGROUND] = POS_FOREGROUND;
	sfColor color[NB_FOREGROUND] = COLOR_FOREGROUND;
	sfVector2f size[NB_FOREGROUND] = SIZE_FOREGROUND;

	hud->number_foreground = NB_FOREGROUND;
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

// INITIALISATION OF THE HUD'S BUTTONS
static button_t **init_button(button_t **button, hud_t *hud)
{
	sfVector2f pos[NB_BUTTON] = POS_BUTTON;
	sfColor color[NB_BUTTON] = COLOR_BUTTON;
	sfVector2f size[NB_BUTTON] = SIZE_BUTTON;

	hud->number_button = NB_BUTTON;
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

// INITIALISATION OF THE HUD'S TEXTS
static text_t **init_text(text_t **text, hud_t *hud)
{
	sfVector2f pos[NB_TEXT] = POS_TEXT;
	sfColor color[NB_TEXT] = COLOR_TEXT;
	sfVector2f size[NB_TEXT] = SIZE_TEXT;
	char str[NB_TEXT][SIZE_TEXT_MAX] = STR_TEXT;

	hud->number_text = NB_TEXT;
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

hud_t *init_hud(void)
{
	hud_t *hud = malloc(sizeof(hud_t));

	if (hud == NULL)
		return (NULL);
	hud->background = init_background(hud->background, hud);
	hud->foreground = init_foreground(hud->foreground, hud);
	hud->button = init_button(hud->button, hud);
	hud->text = init_text(hud->text, hud);
	init_image_hud(hud->button, hud);
	hud->display = display_menu;
	hud->destroy = free_menu;
	hud->looping = true;
	hud->code = OK;
	return (hud);
}
