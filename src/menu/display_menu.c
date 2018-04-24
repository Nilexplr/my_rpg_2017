/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** display of the whole given menu
*/

#include <stdbool.h>
#include "menu.h"

static void display_background(background_t **background, unsigned int nb,
	sfRenderWindow *window)
{
	for (unsigned int i = 0; i < nb; i++) {
		sfRenderWindow_drawSprite(window, background[i]->sprite, NULL);
	}
}

static void display_foreground(button_t **foreground, unsigned int nb,
	sfRenderWindow *window)
{
	for (unsigned int i = 0; i < nb; i++) {
		sfRenderWindow_drawRectangleShape(window, foreground[i]->shape,
		NULL);
	}
}

static void display_button(button_t **button, unsigned int nb,
	sfRenderWindow *window)
{
	for (unsigned int i = 0; i < nb; i++) {
		sfRenderWindow_drawRectangleShape(window, button[i]->shape,
		NULL);
	}
}

static void display_text(text_t **text, unsigned int nb,
	sfRenderWindow *window)
{
	for (unsigned int i =  0; i < nb; i++) {
		sfRenderWindow_drawText(window, text[i]->text, NULL);
	}
}

void display_menu(sfRenderWindow *window, menu_t *menu, bool display)
{
	display_background(menu->background, menu->number_background, window);
	display_foreground(menu->foreground, menu->number_foreground, window);
	display_button(menu->button, menu->number_button, window);
	display_text(menu->text, menu->number_text, window);
	if (display == true)
		sfRenderWindow_display(window);
}
