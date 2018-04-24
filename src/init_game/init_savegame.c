/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Find the samegame and load it in the struct player
*/

#include <stdlib.h>
#include "game_info.h"
#include "player.h"

sfRectangleShape *create_player(sfVector2f pos)
{
	sfRectangleShape *rec = sfRectangleShape_create();
	sfVector2f size = {40, 60};
	sfVector2f origin = {20, 30};

	sfRectangleShape_setSize(rec, size);
	sfRectangleShape_setOutlineThickness(rec, 2);
	sfRectangleShape_setOutlineColor(rec, sfCyan);
	sfRectangleShape_setFillColor(rec, sfTransparent);
	sfRectangleShape_setOrigin(rec, origin);
	sfRectangleShape_setPosition(rec, pos);
	return (rec);
}

render_t *init_render_character(sfVector2f real_pos, sfVector2f pos_map)
{
	render_t *render_character = malloc(sizeof(render_t));

	if (render_character == NULL)
		return (NULL);
	render_character->map_pos = pos_map;
	render_character->shape = create_player(real_pos);
	return (render_character);
}

player_info_t *init_player_info(void)
{
	player_info_t *info = malloc(sizeof(player_info_t));

	if (info == NULL)
		return (NULL);
	info->name_player[0] = '\0';
	info->attack = DEFAULT_ATTACK;
	info->nb_life = 10;
	info->defense = DEFAULT_DEFENSE;
	info->attack = DEFAULT_ATTACK;
	info->speed = DEFAULT_SPEED;
	info->critical = DEFAULT_CRITICAL;
	info->level = 1;
	info->compet_point = 5;
	info->actual_mission = INTRO;
	info->mana = DEFAULT_MANA;
	info->health = DEFAULT_HEALTH;
	info->exp = DEFAULT_EXP;
	info->new_savegame = true;
	return (info);
}
