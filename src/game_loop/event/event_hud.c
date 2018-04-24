/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Catch all the event for the HUD
*/

#include "game_info.h"
#include "hud.h"

static int what_button_clicked(game_t *game, hud_t *hud, sfEvent event)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(
		game->window->window);

	for (unsigned int i = 0; i < hud->number_button; i++) {
		if ((event.type == sfEvtMouseButtonReleased ||
		event.type == sfEvtMouseButtonPressed) && event.key.code ==
		sfMouseLeft && mouse.x > hud->button[i]->position.x &&
		mouse.x < hud->button[i]->position.x + hud->button[i]->size.x
		&& mouse.y > hud->button[i]->position.y && mouse.y <
		hud->button[i]->position.y + hud->button[i]->size.y) {
			return (i);
		}
	}
	return (-1);
}

void event_hud(game_t *game, sfRenderWindow *window, hud_t *hud, sfEvent event)
{
	int click = what_button_clicked(game, hud, event);

	if (click == 0) {}
	if (click == 1) {}
	if (click == 2) {}
	if (click == 3) {}
}
