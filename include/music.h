/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Include file of the music structure and functions
*/

#ifndef MUSIC_H
#define MUSIC_H

#include <SFML/Audio.h>
#include <stdbool.h>

typedef struct music_info_s {
	bool play;
	sfMusic *main_menu;
} music_t;

#endif /* end of include guard: MUSIC_H */
