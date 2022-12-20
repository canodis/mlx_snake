#ifndef SNAKE_H
# define SNAKE_H

#include "../mlx/mlx.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define r 2
#define u 3
#define l 4
#define d 5

#define WIDTH 800
#define HEIGHT 600
#define SSIZE 25

typedef struct s_body
{
	int		x;
	int		y;
	int		next_x;
	int		next_y;
	struct s_body	*next;
	struct s_body	*prev;
}	t_body;

typedef struct s_snake
{
	char	move;
	int		snake_len;
	t_body	*body;
}	t_snake;

typedef struct s_game
{
	void		*mlx;
	void		*screen;
	int			f_counter;
	int			foodx;
	int			foody;
	t_snake		*snake;
	t_body		*last;
	int map[HEIGHT / SSIZE][WIDTH / SSIZE];
	int	gameSpeed;
}	t_game;

extern int move_dir;
extern int g_x;
extern int g_y;

void	init_all(t_game *game);
int		key_hook(int keycode, t_game *game);
void	move_event(t_game *game);
void	draw_snake(t_game *game, int color);
void	add_body(t_body *body, t_game *game);
int		randomRange(int min, int max);
void	generate_food(t_game *game);

#endif