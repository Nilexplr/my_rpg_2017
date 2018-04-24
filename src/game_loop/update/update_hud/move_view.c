/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Update the pos of the main HUD depending on the view
*/

#include "hud.h"

static void change_pos_button(hud_t *hud, button_t **button, sfVector2f pos)
{
	sfVector2f ref[NB_BUTTON] = POS_BUTTON;

	for (unsigned int i = 0; i < hud->number_button; i++) {
		button[i]->position.x = (pos.x - (1920 / 2)) +
			ref[i].x;
		button[i]->position.y = (pos.y - (1920 / 2)) +
			ref[i].y + 400;
		sfRectangleShape_setPosition(button[i]->shape,
			button[i]->position);
	}
}

static void change_pos_foreground(hud_t *hud, button_t **fore, sfVector2f pos)
{
	sfVector2f ref[NB_FOREGROUND] = POS_FOREGROUND;

	for (unsigned int i = 0; i < hud->number_foreground; i++) {
		fore[i]->position.x = (pos.x - (1920 / 2)) +
			ref[i].x;
		fore[i]->position.y = (pos.y - (1920 / 2)) +
			ref[i].y + 400;
		sfRectangleShape_setPosition(fore[i]->shape,
			fore[i]->position);
	}
}

static void change_pos_text(hud_t *hud, text_t **text, sfVector2f pos)
{
	sfVector2f ref[NB_TEXT] = POS_TEXT;

	for (unsigned int i = 0; i < hud->number_text; i++) {
		text[i]->position.x = (pos.x - (1920 / 2)) +
			ref[i].x;
		text[i]->position.y = (pos.y - (1920 / 2)) +
			ref[i].y + 400;
		sfText_setPosition(text[i]->text,
			text[i]->position);
	}
}

void move_hud_view(hud_t *hud, sfView *view)
{
	sfVector2f pos = sfView_getCenter(view);

	change_pos_button(hud, hud->button, pos);
	change_pos_text(hud, hud->text, pos);
	change_pos_foreground(hud, hud->foreground, pos);
}
