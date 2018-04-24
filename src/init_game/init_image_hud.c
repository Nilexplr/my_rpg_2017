/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Init the hud images
*/

#include "menu.h"
#include "hud.h"
#include "resources.h"

void init_image_hud(button_t **button, hud_t *hud)
{
	sfIntRect rect_1 = {266, 133, 135, 133};
	sfIntRect rect_2 = {0, 0, 133, 133};
	sfIntRect rect_3 = {0, 133, 133, 133};
	sfIntRect rect_4 = {133, 0, 133, 133};
	sfTexture *text1 = sfTexture_createFromFile(SPELL_SPRITE, &rect_1);
	sfTexture *text2 = sfTexture_createFromFile(SPELL_SPRITE, &rect_2);
	sfTexture *text3 = sfTexture_createFromFile(SPELL_SPRITE, &rect_3);
	sfTexture *text4 = sfTexture_createFromFile(SPELL_SPRITE, &rect_4);
	sfRectangleShape_setTexture(button[0]->shape, text1, 1);
	sfRectangleShape_setTexture(button[1]->shape, text2, true);
	sfRectangleShape_setTexture(button[2]->shape, text3, sfFalse);
	sfRectangleShape_setTexture(button[3]->shape, text4, sfFalse);
}
