/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Do the event if we clicked on the framerate option in the settings
*/

#include "game_info.h"
#include "menu.h"
#include "mylib.h"
#include "colors.h"
#include "setting_menu.h"

static void display_verbose_framerate(int framerate)
{
	my_putstr(LIGHT_BLUE);
	my_putstr("[CHANGING FRAMERATE]\n");
	my_putstr(GREEN);
	my_putstr("\tFramerate set to : ");
	my_putnbr(framerate);
	my_putchar('\n');
	my_putstr(WHITE);
}

// Set the framerate to 60 (medium / med)
int frame_med_setting_menu(game_t *game, menu_t *menu, int i, sfEvent event)
{
	sfColor def_color = COLOR_BUTTON_1;

	if (event.type == sfEvtMouseButtonPressed)
		set_button_clicked(menu->button[i], def_color);
	if (event.type == sfEvtMouseButtonReleased) {
		sfRenderWindow_setFramerateLimit(game->window->window, 60);
		if (game->verbose == true)
			display_verbose_framerate(60);
	}
	return (0);
}

// Set the framerate to 120 (high)
int frame_high_setting_menu(game_t *game, menu_t *menu, int i, sfEvent event)
{
	sfColor def_color = COLOR_BUTTON_1;

	if (event.type == sfEvtMouseButtonPressed)
		set_button_clicked(menu->button[i], def_color);
	if (event.type == sfEvtMouseButtonReleased) {
		sfRenderWindow_setFramerateLimit(game->window->window, 120);
		if (game->verbose == true)
			display_verbose_framerate(120);
	}
	return (0);
}
