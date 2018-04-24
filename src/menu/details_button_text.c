/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** Add detail to the text or the button pointers
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "menu.h"

void add_detail_text(text_t *text, sfColor color, sfVector2f size)
{
	sfText_setCharacterSize(text->text, size.x);
	sfText_setColor(text->text, color);
	text->color = color;
}

void add_detail_button(button_t *but, sfColor color, sfVector2f size)
{
	sfRectangleShape_setFillColor(but->shape, color);
	sfRectangleShape_setSize(but->shape, size);
	but->size.y = size.y;
	but->size.x = size.x;
	but->color = color;
}
