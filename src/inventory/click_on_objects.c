/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include "inventory.h"
#include "menu.h"
#include "game_info.h"

void if_stuff_empty(game_obj_t *obj, inventory_t *inv)
{
	int x_pos_stuff[5] = X_POS_STUFF;
	int y_pos_stuff[5] = Y_POS_STUFF;
	char type[5] = TYPES;

	obj->pos.x = x_pos_stuff[type[obj->id] - 1];
	obj->pos.y = y_pos_stuff[type[obj->id] - 1];
	inv->player_stuff[type[obj->id] - 1] = obj;
	obj = NULL;
}

void if_inv_empty(game_obj_t *obj, inventory_t *inv, int save_pos_x,
	int save_pos_y)
{
	char type[5] = TYPES;

	obj->pos.x = save_pos_x;
	obj->pos.y = save_pos_y;
	obj = inv->player_stuff[type[obj->id] - 1];
	inv->player_stuff[type[obj->id] - 1] = NULL;
}

void swap_obj(game_obj_t *obj, inventory_t *inv)
{
	char type[5] = TYPES;
	game_obj_t *tmp = malloc(sizeof(game_obj_t));

	tmp = obj;
	obj = inv->player_stuff[type[obj->id] - 1];
	inv->player_stuff[type[obj->id] - 1] = tmp;
}

void check_click(sfMouseButtonEvent event, game_obj_t *obj, inventory_t *inv)
{
	char type[5] = TYPES;
	int x_pos_stuff[5] = X_POS_STUFF;
	int y_pos_stuff[5] = Y_POS_STUFF;
	static int save_pos_x = 0;
	static int save_pos_y = 0;

	if (event.x > obj->pos.x && event.x < obj->pos.x + obj->rect.width &&
	event.y > obj->pos.y && event.y < obj->pos.y + obj->rect.height) {
		if (type[obj->id] <= 0)
			return;
		if (inv->player_stuff[type[obj->id] - 1] == NULL) {
			save_pos_x = obj->pos.x;
			save_pos_y = obj->pos.y;
			if_stuff_empty(obj, inv);
		} else if (obj->pos.x == x_pos_stuff[type[obj->id] - 1] &&
			obj->pos.y == y_pos_stuff[type[obj->id] - 1]) {
			if_inv_empty(obj, inv, save_pos_x, save_pos_y);
		} else
			swap_obj(obj, inv);
	}
}
