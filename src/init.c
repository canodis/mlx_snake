#include "../include/snake.h"

void	init_map(t_game *game, int height, int width)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
			game->map[y][x] = 0;
	}
}

void	init_all(t_game *game)
{
	int a;

	t_snake	*snake;
	snake = malloc(sizeof(t_snake));
	game->mlx =  mlx_init();
	game->screen = mlx_new_window(game->mlx, WIDTH, HEIGHT, "SNAKE");
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
	game->gameSpeed = 5000;
	init_map(game, HEIGHT / SSIZE, WIDTH / SSIZE);
	game->data.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data.addr = (int *)mlx_get_data_addr(game->data.img, &a, &a, &a);
	add_body(game->snake->body, game);
	add_body(game->snake->body, game);
	generate_food(game);
	move_dir = r;
}
