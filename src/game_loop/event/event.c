/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** event functions
*/

#include "game_info.h"
#include "event.h"
#include "hud.h"

event_t get_mode(sfEvent *event, event_t mode)
{/*
	if (sfKeyboard_isKeyPressed(sfKeyA))
		return (mode != SPELL_ONE ? SPELL_ONE : MOUVE);
	if (sfKeyboard_isKeyPressed(sfKeyZ))
		return (mode != SPELL_TWO ? SPELL_TWO : MOUVE);
	if (sfKeyboard_isKeyPressed(sfKeyE))
		return (mode != SPELL_THREE ? SPELL_THREE : MOUVE);
	if (sfKeyboard_isKeyPressed(sfKeyR))
		return (mode != SPELL_ULTI ? SPELL_ULTI : MOUVE);*/
	if (sfKeyboard_isKeyPressed(sfKeyD))
		return (mode != TP ? TP : MOUVE);
	if (sfKeyboard_isKeyPressed(sfKeyLShift))
		return(BASIC_SPELL);
	if (mode == BASIC_SPELL && !sfKeyboard_isKeyPressed(sfKeyLShift))
		return (MOUVE);
	return (mode);
}

void event(sfRenderWindow *window, game_t *game, hud_t *hud)
{
	sfEvent event;
	static event_t mode = MOUVE;

	while (sfRenderWindow_pollEvent(window, &event)) {
		mode = get_mode(&event, mode);
		if (sfKeyboard_isKeyPressed(sfKeyI))
			inventory(game);
		if (sfKeyboard_isKeyPressed(sfKeyS))
			skill_tree(game);
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		else if (mode == BASIC_SPELL && sfMouse_isButtonPressed(sfMouseLeft))
			create_projectile(game, true);
		else if (mode == TP && sfMouse_isButtonPressed(sfMouseLeft))
			teleport(game);
		else if (mode == MOUVE && sfMouse_isButtonPressed(sfMouseLeft))
			get_mouve(game);
		if (sfKeyboard_isKeyPressed(sfKeyP)) {
			insert_enemy_list(game->enemy, create_slayer(game->map, get_spawn_pos(game)));
			insert_enemy_list(game->enemy, create_dog(game->map, get_spawn_pos(game)));
		}
		event_hud(game, window, hud, event);
	}
}
