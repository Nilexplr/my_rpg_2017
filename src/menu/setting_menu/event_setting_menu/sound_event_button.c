/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Do the event if we clicked on the sound on/off option in the settings menu
*/

#include "game_info.h"
#include "menu.h"
#include "mylib.h"
#include "colors.h"
#include "setting_menu.h"

static void display_verbose_sound(bool playing)
{
	my_putstr(LIGHT_BLUE);
	my_putstr("[MUSIC SWITCHED]\n");
	my_putstr(GREEN);
	my_putstr("\tSet : ");
	my_putstr(playing == true ? "ON" : "OFF");
	my_putchar('\n');
	my_putstr(WHITE);
}

// Turn off the music
int off_sound_setting_menu(game_t *game, menu_t *menu, int i, sfEvent event)
{
	sfColor def_color = COLOR_BUTTON_1;

	if (event.type == sfEvtMouseButtonPressed)
		set_button_clicked(menu->button[i], def_color);
	if (event.type == sfEvtMouseButtonReleased) {
		game->music->play = false;
		sfMusic_stop(game->music->main_menu);
		if (game->verbose == true)
			display_verbose_sound(false);
	}
	return (0);
}

// Turn on the music
int on_sound_setting_menu(game_t *game, menu_t *menu, int i, sfEvent event)
{
	sfColor def_color = COLOR_BUTTON_1;

	if (event.type == sfEvtMouseButtonPressed)
		set_button_clicked(menu->button[i], def_color);
	if (event.type == sfEvtMouseButtonReleased && !game->music->play) {
		game->music->play = true;
		sfMusic_play(game->music->main_menu);
		if (game->verbose == true)
			display_verbose_sound(true);
	}
	return (0);
}
