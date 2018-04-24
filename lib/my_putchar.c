/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Putchar writting on the stdout
*/

#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}
