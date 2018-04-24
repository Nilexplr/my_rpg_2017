/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/
#include <stdlib.h>
#include "menu.h"
#include "skill_tree.h"


void click_on_skills(background_t *obj, int i, sfMouseButtonEvent event,
	game_t *game)
{
	if (game->player->info->compet_point <= 0)
		return;
	if (event.x > obj->position.x && event.x < obj->position.x + 90 &&
	event.y > obj->position.y && event.y < obj->position.y + 90) {
		if (i == 2) {
			game->player->info->nb_life++;
			game->player->info->compet_point--;
		}
		if (i == 3) {
			game->player->info->defense++;
			game->player->info->compet_point--;
		}
		if (i == 4) {
			game->player->info->mana++;
			game->player->info->compet_point--;
		}
		if (i == 5) {
			game->player->info->attack++;
			game->player->info->compet_point--;
		}
	}
}

void add_skills(menu_t *sk, sfMouseButtonEvent event, game_t *game)
{
	for (int i = 2; i <= 5; i++)
		click_on_skills(sk->background[i], i, event, game);
}

static int quit_skill_tree(sfEvent *event)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		return (QUIT_MENU);
}

int event_skill_tree(menu_t *sk, game_t *game, int choice)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(game->window->window, &event)) {
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close(game->window->window);
			return (QUIT_GAME);
		}
		choice = quit_skill_tree(&event);
		if (event.type == sfEvtMouseButtonPressed) {
			add_skills(sk, event.mouseButton, game);
		}
	}
	return (choice);
}
