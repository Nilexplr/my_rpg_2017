/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** creation of the button ptr and destroy function
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "menu.h"

void destroy_button(button_t *button)
{
	sfRectangleShape_destroy(button->shape);
	free(button);
}

int create_button(button_t *button, sfVector2f pos)
{
	button->shape = sfRectangleShape_create();
	if (button->shape == NULL)
		return (-1);
	button->position.x = pos.x;
	button->position.y = pos.y;
	sfRectangleShape_setPosition(button->shape, pos);
	sfRectangleShape_setOutlineColor(button->shape, sfBlack);
	sfRectangleShape_setOutlineThickness(button->shape, 3);
	return (0);
}
