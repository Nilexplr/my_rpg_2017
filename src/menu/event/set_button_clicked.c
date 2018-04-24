/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Set the clicked color of the given button
*/

#include "game_info.h"
#include "menu.h"

void set_button_clicked(button_t *button, sfColor def_color)
{
	button->color.r = def_color.r - 25;
	button->color.g = def_color.g - 25;
	button->color.b = def_color.b - 25;
	sfRectangleShape_setFillColor(button->shape, button->color);
}
