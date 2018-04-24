/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** about_menu function do the whole menu loop and display and init
*/

#include <stdlib.h>
#include "menu.h"
#include "about_menu.h"

// INITIALISATION OF THE ABOUT MAIN MENU
menu_t *initialisation_about_menu(game_t *game)
{
	menu_t *menu = malloc(sizeof(menu_t));

	if (menu == NULL)
		return (NULL);
	detail_init_about_menu(menu);
	if (menu->button == NULL || menu->text == NULL ||
	menu->foreground == NULL || menu->display == NULL ||
	menu->destroy == NULL) {
		verbose_about_menu_init_fail(game);
		return (NULL);
	}
	verbose_about_menu_init_ok(game);
	return (menu);
}

static void update_all_menu_shape(menu_t *menu, int alpha)
{
	for (int i = 0; i < NB_FOREGROUND; i++) {
		menu->foreground[i]->color.a = alpha;
		sfRectangleShape_setFillColor(menu->foreground[i]->shape,
			menu->foreground[i]->color);
	}
	for (int i = 0; i < NB_BUTTON; i++) {
		menu->button[i]->color.a = alpha;
		sfRectangleShape_setFillColor(menu->button[i]->shape,
			menu->button[i]->color);
	}
	for (int i = 0; i < NB_TEXT; i++) {
		menu->text[i]->color.a = alpha;
		sfText_setColor(menu->text[i]->text, menu->text[i]->color);
	}
}

static void animation_menu(game_t *game, menu_t *menu, menu_t *main_menu)
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

int about_menu(game_t *game, menu_t *main_menu)
{
	menu_t *menu = initialisation_about_menu(game);

	if (menu == NULL)
		return (84);
	animation_menu(game, menu, main_menu);
	while (menu->looping == true && menu->code == OK) {
		if (get_event_about_menu(game, menu) == FAILURE)
			return (84);
		display_menu(game->window->window, main_menu, false);
		display_menu(game->window->window, menu, true);
	}
	if (menu->code == QUIT_GAME) {
		menu->destroy(menu);
		return (0);
	} else if (menu->code == ERROR) {
		menu->destroy(menu);
		return (84);
	}
	menu->destroy(menu);
	return (1);
}
