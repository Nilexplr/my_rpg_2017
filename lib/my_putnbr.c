/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Putnbr writting int
*/

#include "mylib.h"

void my_putnbr(int nb)
{
	if (nb >= 10) {
		my_putnbr(nb / 10);
		my_putnbr(nb % 10);
	} else {
		my_putchar(nb + 48);
	}
}
