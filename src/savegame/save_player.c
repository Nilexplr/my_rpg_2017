/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Save the player info on the savegame file.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "player.h"
#include "resources.h"

void save_player(player_t *player)
{
	int fd = open(PATH_SAVEGAME, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR
		| S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	if (fd == -1)
		return;
	write(fd, player->info, sizeof(player_info_t));
	close(fd);
}
