#include "../include/snake.h"

void	clear_image(int *addr)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (y < SSIZE) 
				addr[y * WIDTH + x] = 0x4D4C38;
			else if (x < SSIZE)
				addr[y * WIDTH + x] = 0x4D4C38;
			else if (y > HEIGHT - SSIZE)
				addr[y * WIDTH + x] = 0x4D4C38;
			else if (x > WIDTH - SSIZE)
				addr[y * WIDTH + x] = 0x4D4C38;
			else
				addr[y * WIDTH + x] = bg_color;
		}
	}
}

void	reset_game(t_game *game)
{
	sleep(1);
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
	snake->body->x = WIDTH / 2;
	snake->body->y = HEIGHT / 2;
	snake->body->next_x = WIDTH / 2;
	snake->body->next_y = HEIGHT / 2;
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
		{
			reset_game(game);
			return ;
		}
		game->map[body->y / SSIZE][body->x / SSIZE] = 1;
		if (body->x > WIDTH - SSIZE * 2 || body->x < SSIZE || body->y > HEIGHT - SSIZE * 2 || body->y < SSIZE)
		{
			reset_game(game);
			return ;
		}
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
			score++;
			if (score != 0 && score % 10 == 0)
			{
				bg_color += randomRange(10000, 1000000);
				score++;
			}
			game->gameSpeed -= 10;
		}
		body = body->next;
	}
	for (int y = 0; y < SSIZE; y++)
	{
		for (int x = 0; x < SSIZE; x++)
			game->data.addr[(y + game->foody) * WIDTH + x + game->foodx] = 0xFF0000;
	}
	mlx_put_image_to_window(game->mlx, game->screen, game->data.img, 0, 0);
}