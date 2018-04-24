/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init mouvement between 2 point
*/

#include <SFML/Graphics.h>
#include <math.h>

sfVector2f get_vertical(sfVector2f dep, sfVector2f arr, int speed)
{
	sfVector2f mouvement;

	mouvement.x = 0;
	if (dep.y > arr.y)
		mouvement.y = -speed;
	if (dep.y < arr.y)
		mouvement.y = speed;
	return (mouvement);
}

sfVector2f get_mouvement_y(sfVector2f dep, sfVector2f arr, int spd)
{
	sfVector2f mouvement;

	if (dep.y < arr.y) {
		mouvement.y = spd;
		mouvement.x = (dep.x - arr.x) / (dep.y - arr.y) * spd;
	}
	if (dep.y > arr.y) {
		mouvement.y = -spd;
		mouvement.x = -(dep.x - arr.x) / (dep.y - arr.y) * spd;
	}
	return (mouvement);
}

sfVector2f init_mouvement(sfVector2f dep, sfVector2f arr, int spd)
{
	sfVector2f mouvement;

	if (dep.x == arr.x)
		return(get_vertical(dep, arr, spd));
	if (fabs(dep.x - arr.x)  >= fabs(dep.y - arr.y)) {
		if (dep.x < arr.x) {
			mouvement.x = spd;
			mouvement.y = (dep.y - arr.y) / (dep.x - arr.x) * spd;
		}
		if (dep.x > arr.x) {
			mouvement.x = -spd;
			mouvement.y = -(dep.y - arr.y) / (dep.x - arr.x) * spd;
		}
	}
	else
		mouvement = get_mouvement_y(dep, arr, spd);
	return (mouvement);
}
