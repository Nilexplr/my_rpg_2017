/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/
#include <stdlib.h>
#include "menu.h"
#include "skill_tree.h"

menu_t *initialisation_skill_tree(game_t *game)
{
	menu_t *menu = malloc(sizeof(menu_t));

	if (menu == NULL)
		return (NULL);
	detail_init_menu_skill_tree(menu);
	if (menu->button == NULL || menu->text == NULL ||
	/*menu->foreground == NULL ||*/ menu->display == NULL ||
	menu->destroy == NULL) {
		verbose_skill_tree_init_fail(game);
		return (NULL);
	}
	verbose_skill_tree_init_ok(game);
	return (menu);
}

static void modif_text(game_t *game, menu_t *skill_tree)
{
	sfText_setString(skill_tree->text[3]->text,
		my_itoa(game->player->info->level));
	sfText_setString(skill_tree->text[4]->text,
		my_itoa(game->player->info->nb_life));
	sfText_setString(skill_tree->text[5]->text,
		my_itoa(game->player->info->defense));
	sfText_setString(skill_tree->text[6]->text,
		my_itoa(game->player->info->mana));
	sfText_setString(skill_tree->text[7]->text,
		my_itoa(game->player->info->attack));
	sfText_setString(skill_tree->text[8]->text,
		my_itoa(game->player->info->compet_point));
}

static void modif_scale(menu_t *skill_tree)
{
	sfVector2f scale_back = {2, 2};
	sfVector2f scale_skills = {0.5, 0.5};

	sfSprite_setScale(skill_tree->background[0]->sprite, scale_back);
	sfSprite_setScale(skill_tree->background[1]->sprite, scale_back);
	sfSprite_setScale(skill_tree->background[2]->sprite, scale_skills);
	sfSprite_setScale(skill_tree->background[3]->sprite, scale_skills);
	sfSprite_setScale(skill_tree->background[4]->sprite, scale_skills);
	sfSprite_setScale(skill_tree->background[5]->sprite, scale_skills);
	sfSprite_setScale(skill_tree->background[6]->sprite, scale_skills);
	sfSprite_setScale(skill_tree->background[7]->sprite, scale_skills);
	sfSprite_setScale(skill_tree->background[8]->sprite, scale_skills);
	sfSprite_setScale(skill_tree->background[9]->sprite, scale_skills);
}

int skill_tree(game_t *game)
{
	menu_t *skill_tree = initialisation_skill_tree(game);
	int choice = 0;
	sfColor back_color = {139, 139, 139, 255};
	sfVector2f posview = {960, 540};

	if (skill_tree == NULL)
		return (ERROR);
	sfView_setCenter(game->window->view, posview);
	sfRenderWindow_setView(game->window->window, game->window->view);
	while (choice == 0) {
		sfRenderWindow_clear(game->window->window, back_color);
		modif_text(game, skill_tree);
		modif_scale(skill_tree);
		skill_tree->display(game->window->window, skill_tree, true);
		choice = event_skill_tree(skill_tree, game, choice);
	}
	skill_tree->destroy(skill_tree);
	return (choice);
}
