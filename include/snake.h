#ifndef SNAKE_H
# define SNAKE_H

#include "../mlx/mlx.h"
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
	int map[HEIGHT / SSIZE][WIDTH / SSIZE];
	bool		speed_up;
	bool		discoMode;
	int	gameSpeed;
}	t_game;

extern int move_dir;
extern int	head_color;
extern int	body_color;
extern int	score;
extern int	bg_color;

void	init_all(t_game *game);
int		key_hook(int keycode, t_game *game);
void	move_event(t_game *game);
void	draw_snake(t_game *game);
void	add_body(t_body *body, t_game *game);
int		randomRange(int min, int max);
void	generate_food(t_game *game);
void	printmap(t_game *game);
void	clear_image(int *addr);
void	free_all(t_game *game);
int		key_up(int keycode, t_game *game);
void	init_map(t_game *game, int height, int width);

#endif