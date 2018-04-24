/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Check all the buttons of a menu and change the color if there is a fly over
*/

#include "menu.h"

void fly_over_button(game_t *game, menu_t *menu, sfColor *def_color, int modif)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(
		game->window->window);

	for (unsigned int i = 0; i < menu->number_button; i++) {
		if (mouse.x > menu->button[i]->position.x && mouse.x <
		menu->button[i]->position.x + menu->button[i]->size.x &&
		mouse.y > menu->button[i]->position.y && mouse.y <
		menu->button[i]->position.y + menu->button[i]->size.y) {
			menu->button[i]->color.r = def_color[i].r + modif;
			menu->button[i]->color.g = def_color[i].g + modif;
			menu->button[i]->color.b = def_color[i].b + modif;
		} else {
			menu->button[i]->color = def_color[i];
		}
		sfRectangleShape_setFillColor(menu->button[i]->shape,
			menu->button[i]->color);
	}
}
