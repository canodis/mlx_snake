#ifndef SNAKE_H
# define SNAKE_H

#include "../minilibx/mlx.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define r 2
#define u 3
#define l 4
#define d 5

typedef struct s_game
{
	void		*mlx;
	void		*screen;
}	t_game;

extern int move_dir;

void	init_all(t_game *game);
int	key_hook(int keycode, t_game *game);

#endif