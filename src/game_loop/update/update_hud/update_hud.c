/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Updates the hud pos and its component
*/

#include "window.h"
#include "hud.h"

void update_hud(hud_t *hud, window_t *window, player_t *player)
{
	move_hud_view(hud, window->view);
	update_component(hud, player);
}
