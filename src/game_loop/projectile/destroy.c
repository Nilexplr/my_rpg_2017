/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** different destroy function for projectile
*/

#include "game_info.h"
#include <stdlib.h>

void destroy_projectile(projectile_t *obj)
{
	obj->prev->next = obj->next;
	obj->next->prev = obj->prev;
	if (obj->rec != NULL)
		sfRectangleShape_destroy(obj->rec);
	//if (obj->convex != NULL)
		//sfConvexShape_destroy(obj->convex);
	free(obj);
}

void destroy_projectile_charact(projectile_t *obj, float *life)
{
	*life -= obj->dammage;
	destroy_projectile(obj);
}
/*
void destroy_projectile_to_player(projectil_t *obj, player_t *player)
{
	player->
}
*/
