/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** detect colision prototype
*/

#ifndef COLLISION_H_
#define COLLISION_H_

#include <stdbool.h>

typedef struct transformed_s
{
	int point_count;
	sfVector2f *points;
	float *axis_slopes;
}transformed_shape_t;

int detect_collision(transformed_shape_t *obj1, transformed_shape_t *obj2);
transformed_shape_t *convex_transformed_shape(sfConvexShape *shape);
transformed_shape_t *rectangle_transformed_shape(sfRectangleShape *shape);
bool setup_collision(int option, ...);
sfVector2f project_point_on_axis(float axis_slopes, sfVector2f to_project);
int first_check(transformed_shape_t *obj1, transformed_shape_t *obj2
	, sfVector2f *projected1, sfVector2f *projected2);
int detect_overlap(sfVector2f *obj1, sfVector2f *obj2, int nb1, int nb2);


#endif /* !COLLISION_H_ */
