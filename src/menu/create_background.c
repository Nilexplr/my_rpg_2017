/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Creation of the menu's background
*/

#include <stdlib.h>
#include "menu.h"

int create_background(background_t *background, sfVector2f pos, char *path)
{
	background->sprite = sfSprite_create();
	background->texture = sfTexture_createFromFile(path, NULL);
	if (background->texture == NULL || background->sprite == NULL)
		return (-1);
	sfTexture_setSmooth(background->texture, sfTrue);
	sfSprite_setTexture(background->sprite, background->texture, sfTrue);
	background->position.x = pos.x;
	background->position.y = pos.y;
	sfSprite_setPosition(background->sprite, pos);
	return (0);
}
