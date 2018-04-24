/*
** EPITECH PROJECT, 2017
** text_box.c
** File description:
** florent.poinsard@epitech.eu
*/

#include <SFML/Graphics.h>
#include "menu.h"
#include "mylib.h"

void text_box(char *str, sfEvent event, text_t *text, int max)
{
	int cursor = 0;

	if (event.type == sfEvtKeyPressed && event.key.code >= sfKeyA &&
		event.key.code <= sfKeyZ) {
		cursor = my_strlen(str);
		if (cursor < max) {
			str[cursor] = event.key.code + 65;
			str[cursor + 1] = 0;
			sfText_setString(text->text, str);
		}
	} else if (event.type == sfEvtKeyPressed
		&& event.key.code == sfKeyBack) {
		cursor = my_strlen(str);
		cursor != 0 ? str[cursor - 1] = 0 : 0;
		sfText_setString(text->text, str);
	}
}
