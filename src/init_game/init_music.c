/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Init all the music in the game.
*/

#include <stdlib.h>
#include "resources.h"
#include "game_info.h"
#include "music.h"

music_t *init_music(void)
{
	music_t *music = malloc(sizeof(music_t));

	if (music == NULL)
		return (NULL);
	music->play = true;
	music->main_menu = sfMusic_createFromFile(MAIN_MENU_MUSIC);
	sfMusic_setLoop(music->main_menu, sfTrue);
	if (music->main_menu == NULL)
		return (NULL);
	return (music);
}
