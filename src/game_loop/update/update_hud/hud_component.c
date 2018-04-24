/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** update hud component
*/

#include <stdbool.h>
#include "player.h"
#include "hud.h"

static void update_mana(hud_t *hud, player_t *player)
{
	sfVector2f size[7] = SIZE_FOREGROUND;

	if (player->info->mana > 100)
		player->info->mana = 100;
	if (player->info->mana < 0)
		player->info->mana = 0;
	hud->foreground[6]->size.x = size[5].x / 100 * player->info->mana;
	sfRectangleShape_setSize(hud->foreground[6]->shape,
		hud->foreground[6]->size);
}

static void update_health(hud_t *hud, player_t *player)
{
	sfVector2f size[7] = SIZE_FOREGROUND;

	if (player->info->health > 100)
		player->info->health = 100;
	if (player->info->health < 0)
		player->info->health = 0;
	hud->foreground[4]->size.x = size[3].x / 100 * player->info->health;
	sfRectangleShape_setSize(hud->foreground[4]->shape,
		hud->foreground[4]->size);
}

static void update_exp(hud_t *hud, player_t *player)
{
	sfVector2f size[7] = SIZE_FOREGROUND;

	if (player->info->exp > 100)
		player->info->exp = 100;
	hud->foreground[2]->size.x = size[1].x / 100 * player->info->exp;
	sfRectangleShape_setSize(hud->foreground[2]->shape,
		hud->foreground[2]->size);
}

void update_component(hud_t *hud, player_t *player)
{
	update_mana(hud, player);
	update_health(hud, player);
	update_exp(hud, player);
}
