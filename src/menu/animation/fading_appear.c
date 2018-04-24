/*
** EPITECH PROJET, 2018
** my_rpg
** File description:
** Fade appear the given menu
*/

#include "game_info.h"
#include "menu.h"

static void update_all_menu_shape(menu_t *menu, int alpha)
{
	for (unsigned int i = 0; i < menu->number_foreground; i++) {
		menu->foreground[i]->color.a = alpha;
		sfRectangleShape_setFillColor(menu->foreground[i]->shape,
			menu->foreground[i]->color);
	}
	for (unsigned int i = 0; i < menu->number_button; i++) {
		menu->button[i]->color.a = alpha;
		sfRectangleShape_setFillColor(menu->button[i]->shape,
			menu->button[i]->color);
	}
	for (unsigned int i = 0; i < menu->number_text; i++) {
		menu->text[i]->color.a = alpha;
		sfText_setColor(menu->text[i]->text, menu->text[i]->color);
	}
}

void menu_faded_appear(game_t *game, menu_t *menu, menu_t *main_menu)
{
	sfClock *clock = sfClock_create();
	sfTime time;
	int i = 0;

	while (i < 255) {
		time = sfClock_getElapsedTime(clock);
		if (time.microseconds > 0) {
			update_all_menu_shape(menu, i);
			sfRenderWindow_clear(game->window->window, sfBlack);
			display_menu(game->window->window, main_menu, false);
			display_menu(game->window->window, menu, true);
			sfClock_restart(clock);
			i += 15;
		}
	}
	sfClock_destroy(clock);
}
