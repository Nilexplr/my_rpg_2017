/*
** EPITECH PROJECT, 2017
** My_Hunter - C_Graphical_Programming
** File description:
** florent.poinsard@epitech.eu
*/

#include <stdlib.h>
#include <stdbool.h>
#include "mylib.h"

char *my_itoa(long long int num)
{
	char *str = malloc(sizeof(char) * my_nbrlen(num) + 2);
	int i = 0;
	bool is_negative = false;
	int rem = 0;

	if (num == 0) {
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	num < 0 ? is_negative = true : 0;
	num < 0 ? num = -num : 0;
	while (num != 0) {
		rem = num % 10;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / 10;
	}
	is_negative ? str[i++] = '-' : 0;
	str[i] = '\0';
	return (str = my_revstr(str));
}
