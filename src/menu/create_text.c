/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** creation of the text ptr and destroy function
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "menu.h"

void destroy_text(text_t *text)
{
	sfFont_destroy(text->font);
	sfText_destroy(text->text);
	free(text);
}

int create_text(text_t *text, sfVector2f pos, char *font_path, char *string)
{
	text->font = sfFont_createFromFile(font_path);
	if (text->font == NULL)
		return (-1);
	text->text = sfText_create();
	if (text->text == NULL)
		return (-1);
	sfText_setString(text->text, string);
	sfText_setFont(text->text, text->font);
	sfText_setPosition(text->text, pos);
	text->position.x = pos.x;
	text->position.y = pos.y;
	return (0);
}
