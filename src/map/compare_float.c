/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** compare float functionc
*/

int compare_float(float nb1, float nb2, float precision)
{
	if (nb1 <= nb2 && nb1 + precision >= nb2)
		return 1;
	if (nb1 >= nb2 && nb1 - precision <= nb2)
		return 1;
	return 0;
}
