/*
** EPITECH PROJECT, 2017
** filename
** File description
** Main include file, containing the game_t structure and the important func
*/

#ifndef GAME_INFO_H
#define GAME_INFO_H

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "window.h"
#include "map.h"
#include "music.h"
#include "player.h"
#include "projectile.h"
#include "enemy.h"
#include "collision.h"

#define SUCCESS 0
#define FAILURE 84
#define SECONDS 1000000

typedef enum prog_state_s {
	FINE,
	QUIT_PROG,
	GAME_ERROR = 84
} prog_state_t;

typedef struct game_s {
	bool verbose;
	void (*destroy)(struct game_s*);
	music_t *music;
	prog_state_t prog_state;
	window_t *window;
	map_t *map;
	player_t *player;
	projectile_t *projectile;
	enemy_t *enemy;
} game_t;

game_t *init_game(int argc, char **argv);
window_t *init_window(bool verbose);
music_t *init_music(void);
player_t *init_player(game_t *game);
void destroy_game(game_t *game);
void game_loop(game_t *game);
sfVector2i get_real_pos_mouse(game_t *);
void save_player(player_t *player);
int update(game_t *game, void *);
int draw_call(game_t *game, void *);
int collision(game_t *game);
void get_mouve(game_t *game);
void init_drop(game_t *game);

/* ENEMY FUNCTIONS */
void collision_projectile_enemy(game_t *all, projectile_t *);
void get_slayer_turn(game_t *game, enemy_t *enemy);
void ia_move(game_t *game, enemy_t *enemy);
void get_dog_turn(game_t *game, enemy_t *enemy);
sfVector2f get_spawn_pos(game_t *game);

/* SPELL function */
void teleport(game_t *game);


#endif /* end of include guard: GAME_INFO_H */
