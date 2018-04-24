/*
** EPITECH PROJECT, 2017
** init_window.c
** File description
** Creation of the window struct, return NULL if error. Display verbose if set.
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include "colors.h"
#include "window.h"
#include "mylib.h"

// DISPLAY VERBOSE IS SUCCESS
static window_t *verbose_creation_window(window_t *window, bool verbose)
{
	if (verbose == true) {
		my_putstr(LIGHT_BLUE);
		my_putstr("[WINDOW CREATION]\n");
		my_putstr(GREEN);
		my_putstr("\tWindow Created");
		my_putstr(WHITE);
		my_putstr("\t->\tVideo Mode = ");
		my_putnbr(window->width);
		my_putstr(" / ");
		my_putnbr(window->height);
		my_putstr("\n");
	}
	return (window);
}

// DISPLAY VERBOSE IS THE CREATION IS A FAILURE
static void *verbose_creation_window_fail(window_t *window, bool verbose)
{
	if (verbose == true) {
		my_putstr(LIGHT_BLUE);
		my_putstr("[W<INDOW CREATION]\n");
		my_putstr(LIGHT_RED);
		my_putstr("\tFAIL");
		my_putstr(WHITE);
		my_putstr("\t->\tThe window could not be created.\n");
	}
	free(window);
	return (NULL);
}

// CHOOSE THE VIDEO MODE BETWEEN ALL THE AVAILABLE VIDEO MODE
static sfVideoMode set_video_mode(const sfVideoMode *list, int max)
{
	sfVideoMode video = {DEFAULT_SIZE_X, DEFAULT_SIZE_Y, 32};

	for (int i = 0; i < max; i++) {
		if (sfVideoMode_isValid(list[i]))
			return (list[i]);
	}
	return (video);
}

// INIT THE WINDOW AND THE WINDOW STRUCT, RETURN NULL IF ERROR
window_t *init_window(bool verbose)
{
	window_t *window = malloc(sizeof(window_t));
	size_t *count = malloc(sizeof(size_t));
	const sfVideoMode *list = sfVideoMode_getFullscreenModes(count);
	sfVideoMode video = set_video_mode(list, *count);

	if (window == NULL)
		return (NULL);
	window->video_mode = video;
	window->width = video.width;
	window->height = video.height;
	window->window = sfRenderWindow_create(video, "my rpg", sfClose, NULL);
	if (window->window == NULL)
		return (verbose_creation_window_fail(window, verbose));
	sfRenderWindow_setMouseCursorVisible(window->window, CURSOR_VISIBLE);
	sfRenderWindow_setFramerateLimit(window->window, DEFAULT_FRAMERATE);
	sfRenderWindow_setTitle(window->window, TITLE_WINDOW);
	free(count);
	return (verbose_creation_window(window, verbose));
}
