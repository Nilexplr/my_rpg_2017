/*
** EPITECH PROJECT, 2017
** My_rpg
** File description:
** Mouse traking
*/

#include "game_info.h"
/*
void traking_display(game_t *game)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(
				game->window->window);
	sfVector2f up = {0, -SPEED_VIEW};
	sfVector2f down = {0, SPEED_VIEW};
	sfVector2f left = {-SPEED_VIEW, 0};
	sfVector2f right = {SPEED_VIEW, 0};

	if (mouse.y <= 15) {
		sfView_move(game->window->view, up);
		game->window->posView.y -= SPEED_VIEW;
	}
	if (mouse.y >= DEFAULT_SIZE_Y - 100) {
		sfView_move(game->window->view, down);
		game->window->posView.y += SPEED_VIEW;
	}
	if (mouse.x <= 15) {
		sfView_move(game->window->view, left);
		game->window->posView.x -= SPEED_VIEW;
	}
	if (mouse.x >= DEFAULT_SIZE_X - 15) {
		sfView_move(game->window->view, right);
		game->window->posView.x += SPEED_VIEW;
	}
}
*/
sfVector2i get_real_pos_mouse(game_t *game)
{
	sfVector2i mouse = sfMouse_getPosition((sfWindow *)game->window->window);
	sfVector2i final;

	final.x = mouse.x + game->window->posView.x - (DEFAULT_SIZE_X / 2);
	final.y = mouse.y + game->window->posView.y - (DEFAULT_SIZE_Y / 2);
	return final;
}
