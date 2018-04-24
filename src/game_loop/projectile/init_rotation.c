/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init rotation of the projectiles
*/

#include "projectile.h"

float calcul_up(sfVector2f dep, sfVector2f arr, float rotate)
{
	if (dep.x > arr.x)
		rotate = -rotate;
	else
		rotate = rotate;
	return (rotate);
}

float calcul_down(sfVector2f dep, sfVector2f arr, float rotate, int nb)
{
	if (dep.x < arr.x )
		rotate = nb + rotate;
	if (dep.x > arr.x)
		rotate = nb - rotate;
	return (rotate);
}

float init_rotate(sfVector2f dep, sfVector2f arr)
{
	float x = (float)(fabs(dep.x - arr.x));
	float y = (float)(fabs(dep.y - arr.y));
	float rotate = atanf((x / y)) * 180.0 / M_PI;

	if (dep.x == arr.x) {
		if (dep.y > arr.y)
			rotate = 0;
		if (dep.y < arr.y)
			rotate = 180;
		return (rotate);
	}
	if (dep.y >= arr.y) {
		if (fabs((dep.y - arr.y)) / fabs((dep.x - arr.x)) >= 1)
			rotate = calcul_up(dep, arr, rotate);
		else
			rotate = calcul_down(dep, arr, rotate, 0);
	}
	if (dep.y < arr.y) {
		if (fabs((dep.y - arr.y)) / fabs((dep.x - arr.x)) >= 1)
			rotate = 180 + calcul_up(arr, dep, rotate);
		else
			rotate = calcul_down(arr, dep, rotate, 180);
	}
	return (rotate);
}
