/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Functions that free a whole menu
*/

#include <stdlib.h>
#include "menu.h"

// FREE FUNCTION OF THE GIVEN MENU'S BUTTONS
static void free_button(button_t **button, unsigned int nb_button)
{
	for (unsigned int i = 0; i < nb_button; i++) {
		sfRectangleShape_destroy(button[i]->shape);
		free(button[i]);
	}
	free(button);
}

// FREE FUNCTION OF THE GIVEN MENU'S BACKGROUNDS
static void free_background(background_t **background, unsigned int nb_back)
{
	for (unsigned int i = 0; i < nb_back; i++) {
		sfSprite_destroy(background[i]->sprite);
		sfTexture_destroy(background[i]->texture);
		free(background[i]);
	}
	free(background);
}

// FREE FUNCTION OF THE GIVEN MENU'S FOREGROUNDS
static void free_foreground(button_t **foreground, unsigned int nb_foreground)
{
	for (unsigned int i = 0; i < nb_foreground; i++) {
		sfRectangleShape_destroy(foreground[i]->shape);
		free(foreground[i]);
	}
	free(foreground);
}

// FREE FUNCTION OF THE GIVEN MENU'S TEXTS
static void free_text(text_t **text, unsigned int nb_text)
{
	for (unsigned int i = 0; i < nb_text; i++) {
		sfText_destroy(text[i]->text);
		sfFont_destroy(text[i]->font);
		free(text[i]);
	}
	free(text);
}

// MAIN FUNCTION OF THE FREE
void free_menu(menu_t *menu)
{
	free_button(menu->button, menu->number_button);
	free_background(menu->background, menu->number_background);
	free_foreground(menu->foreground, menu->number_foreground);
	free_text(menu->text, menu->number_text);
	free(menu);
}
