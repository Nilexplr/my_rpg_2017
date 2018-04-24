/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Set the menu ptr to QUIT_GAME if the user closes the window.
*/

#include "menu.h"

void event_close(sfEvent event, menu_t *menu)
{
	if (event.type == sfEvtClosed) {
		menu->code = QUIT_GAME;
		menu->looping = false;
	}
}