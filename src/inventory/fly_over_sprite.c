/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include "game_object.h"
#include "game_info.h"
#include "menu.h"
#include "resources.h"
#include "inventory.h"

static sfVector2i get_mouse_position(game_t *game)
{
	return (sfMouse_getPositionRenderWindow(game->window->window));
}

void fly_over_sprite(game_t *game, game_obj_t *obj)
{
	sfVector2i mouse = get_mouse_position(game);
	sfVector2f pos_sprite = {1200, 300};
	sfVector2f scale = {2, 2};
	sfVector2f normal_size = {1, 1};

	if (mouse.x > obj->pos.x && mouse.x < obj->pos.x + obj->rect.width &&
	mouse.y > obj->pos.y && mouse.y < obj->pos.y + obj->rect.height) {
		sfSprite_setScale(obj->sprite, scale);
		sfSprite_setPosition(obj->sprite, pos_sprite);
		sfRenderWindow_drawSprite(game->window->window, obj->sprite,
			NULL);
		for (int i = 0; i < NB_TEXT_OBJ; i++)
			sfRenderWindow_drawText(game->window->window,
				obj->text[i]->text, NULL);
	}
	sfSprite_setScale(obj->sprite, normal_size);
}
