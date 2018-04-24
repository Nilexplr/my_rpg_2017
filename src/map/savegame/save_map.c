/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Save the whole map into the file.
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "map.h"
#include "mylib.h"
#include "resources.h"

static sfVector2f get_size_load_map(int fd)
{
	sfVector2f size = {0, 0};
	sfVector2f size_0 = {0, 0};
	int err = 0;

	err = read(fd, &size, sizeof(sfVector2f));
	if (err != sizeof(sfVector2f)) {
		my_putstr("Wrong map save file.\n");
		return (size_0);
	}
	return (size);
}

float **load_the_map(void)
{
	float **map3d = NULL;
	sfVector2f size = {0, 0};
	int fd = open(PATH_SAVEGAME_MAP, O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR
		| S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	int err = 0;

	if (fd == -1)
		return (NULL);
	size = get_size_load_map(fd);
	map3d = malloc(sizeof(float *) * (size.y + 1));
	if (map3d == NULL)
		return (NULL);
	for (int i = 0; i < size.y; i++) {
		map3d[i] = malloc(sizeof(float) * (size.x + 1));
		if (map3d[i] == NULL)
			return (NULL);
		if (read(fd, map3d[i], (sizeof(float) * (size.x))) !=
		sizeof(float) * (size.x))
			return (NULL);
	}
	return (map3d);
}

void save_the_map(map_t *map)
{
	float **map3d = NULL;
	sfVector2f size = {0, 0};
	int fd = open(PATH_SAVEGAME_MAP, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR
		| S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	if (fd == -1)
		return;
	write(fd, &map->max, sizeof(sfVector2f));
	for (int i = 0; i < map->max.y; i++)
		write(fd, map->map3d[i], sizeof(float) * (map->max.x + 1));
}
