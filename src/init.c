#include "../include/snake.h"

void	init_map(t_game *game, int height, int width)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (y == 0 || x == 0 || y == height - 1 || x == width - 1)
				game->map[y][x] = 1;
			else
				game->map[y][x] = 0;
		}
	}
}

void	init_all(t_game *game)
{
	int a;
	t_snake	*snake;

	snake = malloc(sizeof(t_snake));
	game->mlx =  mlx_init();
	game->screen = mlx_new_window(game->mlx, WIDTH, HEIGHT, "SNAKE");
	game->f_counter = 0;
	snake->body = malloc(sizeof(t_body));
	snake->body->next = NULL;
	snake->body->prev = NULL;
	snake->body->x = WIDTH / 2;
	snake->body->y = HEIGHT / 2;
	snake->body->next_x = WIDTH / 2;
	snake->body->next_y = HEIGHT / 2;
	snake->snake_len = 1;
	game->snake = snake;
	game->last = NULL;
	game->gameSpeed = GAMESPEED;
	init_map(game, HEIGHT / SSIZE, WIDTH / SSIZE);
	game->data.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data.addr = (int *)mlx_get_data_addr(game->data.img, &a, &a, &a);
	add_body(game->snake->body, game);
	add_body(game->snake->body, game);
	generate_food(game);
	move_dir = r;
	game->discoMode = false;
}
