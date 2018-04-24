/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include "game_object.h"
#include <stdlib.h>
#include "resources.h"
#include "inventory.h"

text_t **create_text_inventory(text_t **text, game_obj_t *obj)
{
	char desc[NB_OBJ][SIZE_MAX_DESC] = DESCRIPTIONS;
	char life[NB_OBJ][SIZE_MAX_DESC] = LIFE;
	char defense[NB_OBJ][SIZE_MAX_DESC] = DEFENSE;
	char mana[NB_OBJ][SIZE_MAX_DESC] = MANA;
	char attaque[NB_OBJ][SIZE_MAX_DESC] = ATTAQUE;
	sfVector2f pos_text = {1200, 200};
	sfVector2f pos_text_1 = {1400, 475};
	sfVector2f pos_text_2 = {1485, 475};
	sfVector2f pos_text_3 = {1400, 555};
	sfVector2f pos_text_4 = {1485, 555};

	create_text(text[0], pos_text, FONT_BLACK_ITALIC, desc[obj->id]);
	create_text(text[1], pos_text_1, FONT_BLACK_ITALIC, life[obj->id]);
	create_text(text[2], pos_text_2, FONT_BLACK_ITALIC, defense[obj->id]);
	create_text(text[3], pos_text_3, FONT_BLACK_ITALIC, mana[obj->id]);
	create_text(text[4], pos_text_4, FONT_BLACK_ITALIC, attaque[obj->id]);
	for (int i = 0; i < NB_TEXT_OBJ; i++)
		if (text[i] == NULL)
			return (NULL);
	return (text);
}

text_t **init_text_obj(game_obj_t *obj)
{
	text_t **text = malloc(sizeof(text_t *) * NB_TEXT_OBJ);

	if (text == NULL)
		return (NULL);
	for (int i = 0; i < NB_TEXT_OBJ; i++) {
		text[i] = malloc(sizeof(text_t));
		if (text[i] == NULL)
			return (NULL);
	}
	text = create_text_inventory(text, obj);
	return (text);
}

game_obj_t *create_game_obj(const char *path, sfVector2f pos, sfIntRect rect,
	int id)
{
	game_obj_t *object = malloc(sizeof(game_obj_t));

	if (object == NULL)
		return (NULL);
	object->sprite = sfSprite_create();
	object->texture = sfTexture_createFromFile(path, NULL);
	object->id = id;
	object->text = init_text_obj(object);
	if (object->texture == NULL || object->sprite == NULL ||
		object->text == NULL)
		return (NULL);
	sfTexture_setSmooth(object->texture, sfTrue);
	sfSprite_setTexture(object->sprite, object->texture, sfTrue);
	object->pos.x = pos.x;
	object->pos.y = pos.y;
	object->rect.top = rect.top;
	object->rect.left = rect.left;
	object->rect.width = rect.width;
	object->rect.height = rect.height;
	return (object);
}
