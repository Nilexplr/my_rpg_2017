/*
** EPITECH PROJECT, 2018
** setup_collision.c
** File description:
** setup collision functions
*/

#include "game_info.h"
#include <stdarg.h>
#include <stdlib.h>

int detect_collision(transformed_shape_t *obj1, transformed_shape_t *obj2)
{
	sfVector2f *projected1 = malloc(sizeof(sfVector2f) *
		(obj1->point_count + 1));
	sfVector2f *projected2 = malloc(sizeof(sfVector2f) *
		(obj2->point_count + 1));

	if (first_check(obj1, obj2, projected1, projected2) == 0)
		return (0);
	for (int j = 0; j < obj2->point_count; j++) {
		for (int i = 0; i < obj1->point_count; i++)
			projected1[i] = project_point_on_axis(obj2->
				axis_slopes[j], obj1->points[i]);
		for (int i = 0; i < obj2->point_count; i++)
			projected2[i] = project_point_on_axis(obj2->
				axis_slopes[j], obj2->points[i]);
		if (detect_overlap(projected1, projected2, obj1->point_count
			, obj2->point_count) == 0)
			return (0);
	}
	return (1);
}
/*
void collision_convex_square(va_list ap)
{
	area_t *area = va_arg(ap, area_t*);
	plane_t *plane = va_arg(ap, plane_t*);
	transformed_shape_t *obj1 = area->sprite.transfo;
	transformed_shape_t *obj2 = plane->sprite.transfo;

	obj1 = convex_transformed_shape(area->sprite.convex);
	obj2 = rectangle_transformed_shape(plane->sprite.rect);

	if (detect_collision(obj1, obj2) == 1) {
		destroy_plane(plane);
		my_putstr("It collides\n");
	}
}
*/
bool collision_square_enemy(va_list ap)
{
	sfRectangleShape *plane1 = va_arg(ap, sfRectangleShape *);
	sfRectangleShape *plane2 = va_arg(ap, sfRectangleShape *);
	transformed_shape_t *obj1 = rectangle_transformed_shape(plane1);
	transformed_shape_t *obj2 = rectangle_transformed_shape(plane2);
	bool it_collide = false;

	if (detect_collision(obj1, obj2) == 1) {
		it_collide = true;
	}
	free(obj1->points);
	free(obj1->axis_slopes);
	free(obj2->points);
	free(obj2->axis_slopes);
	free(obj1);
	free(obj2);
	return (it_collide);
}

bool setup_collision(int option, ...)
{
	va_list ap;
	bool collide = false;

	va_start(ap, option);
/*	if (option == 1)
		collision_convex_plane(ap);
	*/if (option == 2)
		collide = collision_square_enemy(ap);
	return (collide);
}

void collision_projectile_enemy(game_t *all, projectile_t *it)
{
	bool collide = false;
	enemy_t *itb;

	for (itb = all->enemy->next; itb != all->enemy &&
		collide == false
		; itb = itb->next) {
		collide = setup_collision(2, it->rec, itb->shape);
	}
	if (collide == true) {
		it = it->prev;
		destroy_projectile_charact(it->next, &itb->prev->life);
		}
}
