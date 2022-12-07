#include "../include/snake.h"

void	init_all(t_game *game)
{
	t_snake	*snake;
	snake = malloc(sizeof(t_snake));
	game->mlx =  mlx_init();
	game->screen = mlx_new_window(game->mlx, 800, 600, "SNAKE");
	game->last = NULL;
	game->f_counter = 0;
	snake->body = malloc(sizeof(t_body));
	snake->body->next = NULL;
	snake->body->prev = NULL;
	snake->body->x = 0;
	snake->body->y = 0;
	snake->body->next_x = 0;
	snake->body->next_y = 0;
	snake->snake_len = 1;
	game->snake = snake;
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->screen);
		exit(0);
	}
	if (keycode == 97)
		move_dir = l;
	if (keycode == 115)
		move_dir = d;
	if (keycode == 100)
		move_dir = r;
	if (keycode == 119)
		move_dir = u;
	if (keycode == 98)
	{
		add_body(game->snake->body, game);
	}
	return (0);
}
