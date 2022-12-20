#include "../include/snake.h"

void	clear_image(int *addr)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
			addr[y * WIDTH + x] = 0;
	}
}

void	reset_game(t_game *game)
{
	t_snake *snake = game->snake;
	t_body	*body = snake->body;
	body = body->next->next;
	while (body)
	{
		free(body->prev);
		body = body->next;
	}
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
	add_body(game->snake->body, game);
	add_body(game->snake->body, game);
	generate_food(game);
	move_dir = r;
}

void	draw_snake(t_game *game)
{
	t_body	*body = game->snake->body;
	t_body	*lastToFirst = game->last;
	while (lastToFirst && lastToFirst->prev)
	{
		lastToFirst->next_x = lastToFirst->prev->x;
		lastToFirst->next_y = lastToFirst->prev->y;
		lastToFirst = lastToFirst->prev;
	}
	for (int a = 0; a < game->snake->snake_len; a++)
	{
		game->map[body->y / SSIZE][body->x / SSIZE] = 0;
		body->x = body->next_x;
		body->y = body->next_y;
		if (game->map[body->y / SSIZE][body->x / SSIZE] == 1)
			reset_game(game);
		game->map[body->y / SSIZE][body->x / SSIZE] = 1;
		if (body->x > WIDTH || body->x < 0 || body->y > HEIGHT || body->y < 0)
			reset_game(game);
		for (int y = 0; y < SSIZE; y++)
			for (int x = 0; x < SSIZE; x++)
			{
				if (a == 0)
					game->data.addr[(y + body->y) * WIDTH + x + body->x] = head_color;
				else
					game->data.addr[(y + body->y) * WIDTH + x + body->x] = body_color;
			}
		if (body->x == game->foodx && body->y == game->foody)
		{
			add_body(game->snake->body, game);
			generate_food(game);
			game->gameSpeed -= 10;
		}
		body = body->next;
	}
	for (int y = 0; y < SSIZE; y++)
	{
		for (int x = 0; x < SSIZE; x++)
			game->data.addr[(y + game->foody) * WIDTH + x + game->foodx] = 0xFF0000;
	}
	// printmap(game);
	// printf("snake x %d   snake y %d   foodx %d   foody %d\n", game->snake->body->x, game->snake->body->y, game->foodx, game->foody);
	mlx_put_image_to_window(game->mlx, game->screen, game->data.img, 0, 0);
}