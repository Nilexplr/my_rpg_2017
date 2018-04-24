/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** florent.poinsard@epitech.eu
*/

#include "mylib.h"

char *my_revstr(char *str)
{
	int i = 0;
	int len = my_strlen(str);
	char c = 0;

	while (i < len / 2) {
		c = *(str + i);
		*(str + i) = *(str + len - i - 1);
		*(str + len - i - 1) = c;
		++i;
	}
	return (str);
}
