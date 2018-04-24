/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Include file of the window
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.h>

#define DEFAULT_FRAMERATE 60
#define CURSOR_VISIBLE sfTrue
#define TITLE_WINDOW "My RPG"
#define DEFAULT_SIZE_X 1920
#define DEFAULT_SIZE_Y 1080
#define POS_CURSOR(x) get_real_pos_mouse(x)

typedef struct window_s {
	sfRenderWindow *window;
	sfVideoMode video_mode;
	unsigned int height;
	unsigned int width;
	sfView *view;
	sfVector2f posView;
} window_t;

#endif /* end of include guard: WINDOW_H */
