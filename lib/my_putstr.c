/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** putstr writting char * on the stdout
*/

#include "mylib.h"

void my_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
}
