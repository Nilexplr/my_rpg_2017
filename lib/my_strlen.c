/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** florent.poinsard@epitech.eu
*/

#include <stdlib.h>

int my_strlen(char *str)
{
	int size = 0;

	if (str == NULL)
		return (0);
	while (str[size] != '\0') {
		size++;
	}
	return (size);
}
