/*
** EPITECH PROJECT, 2017
** my_nbrlen.c
** File description:
** florent.poinsard@epitech.eu
*/

int my_nbrlen(int nb)
{
	int result = nb;
	int i = 0;

	while (result > 0) {
		result = result / 10;
		i++;
	}
	return (i);
}
