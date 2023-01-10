#ifndef SNAKE_H
# define SNAKE_H

#if CAN == 1
	#include "../mlx-linux/mlx.h"
	#define GAMESPEED 5000
	#define GG 666
#else
	#include "../mlx-mac/mlx.h"
	#define GAMESPEED 1000
	#define GG 777
#endif

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

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

typedef struct s_data
{
	void	*img;
	int		*addr;
}	t_data;

typedef struct s_game
{
	void		*mlx;
	void		*screen;
	int			f_counter;
	int			foodx;
	int			foody;
	t_snake		*snake;
	t_body		*last;
	t_data		data;
	bool		speed_up;
	bool		discoMode;
	int			gameSpeed;
	int			map[HEIGHT / SSIZE][WIDTH / SSIZE];
}	t_game;

extern int	move_dir;
extern int	head_color;
extern int	body_color;
extern int	score;
extern int	bg_color;

void	init_all(t_game *game);
int		key_hook(int keycode, t_game *game);
void	move_event(t_game *game);
void	draw(t_game *game);
void	add_body(t_body *body, t_game *game);
int		randomRange(int min, int max);
void	generate_food(t_game *game);
void	printmap(t_game *game);
void	clear_image(t_game *game);
void	free_all(t_game *game);
int		key_up(int keycode, t_game *game);
void	init_map(t_game *game, int height, int width);
void	reset_game(t_game *game);

#endif