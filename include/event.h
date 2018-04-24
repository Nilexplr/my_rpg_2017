/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** event.h
*/

#ifndef EVENT_H_
#define EVENT_H_

#include "game_info.h"
#include "hud.h"

typedef enum mode_s {
	MOUVE,
	BASIC_SPELL,
	SPECIAL_SPELL,
	SPELL_ONE,
	SPELL_TWO,
	SPELL_THREE,
	SPELL_ULTI,
	TP
} event_t;

int inventory(game_t *game);
int skill_tree(game_t *game);
void event(sfRenderWindow *, game_t *, hud_t *);


#endif /* end of include guard: EVENT_H_ */
