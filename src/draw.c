#include "../include/snake.h"

void	draw_object(int *addr, int x, int y, int color, bool is)
{
	for (int i = 0; i < SSIZE; i++)
	{
		for (int j = 0; j < SSIZE; j++)
		{
			if (is)
			{
				if (i == 0 || i == SSIZE - 1 || j == 0 || j == SSIZE - 1)
					addr[(y + i) * WIDTH + x + j] = 0;
				else
					addr[(y + i) * WIDTH + x + j] = color;
			}
			else
				addr[(y + i) * WIDTH + x + j] = color;
		}
	}
}

void	clear_image(t_game *game)
{
	int	*addr = game->data.addr;
	for (int y = 0; y < HEIGHT / SSIZE; y++)
	{
		for (int x = 0; x < WIDTH / SSIZE; x++)
		{
			if (game->map[y][x] == 1)
				draw_object(addr, x * SSIZE, y * SSIZE, 0x4D4C38, true);
			else if (game->map[y][x] == 0)
				draw_object(addr, x * SSIZE, y * SSIZE, bg_color, false);
		}
	}
}

void	draw_snake(t_game *game, t_body *body, int a)
{
	for (int y = 0; y < SSIZE; y++)
	{
		for (int x = 0; x < SSIZE; x++)
		{
			if (a == 0)
			{
				if (y == 0 || y == SSIZE - 1 || x == 0 || x == SSIZE - 1)
					game->data.addr[(y + body->y) * WIDTH + x + body->x] = 0;
				else
					game->data.addr[(y + body->y) * WIDTH + x + body->x] = head_color;
			}
			else
			{
				if (y == 0 || y == SSIZE - 1 || x == 0 || x == SSIZE - 1)
					game->data.addr[(y + body->y) * WIDTH + x + body->x] = 0;
				else
					game->data.addr[(y + body->y) * WIDTH + x + body->x] = body_color;
			}
		}
	}	
}

void	draw_food(t_game *game)
{
	for (int y = 0; y < SSIZE; y++)
	{
		for (int x = 0; x < SSIZE; x++)
			if (y == 0 || y == SSIZE - 1 || x == 0 || x == SSIZE - 1)
				game->data.addr[(y + game->foody) * WIDTH + x + game->foodx] = 0;
			else
				game->data.addr[(y + game->foody) * WIDTH + x + game->foodx] = 0xFF0000;
	}
}

void	draw(t_game *game)
{
	t_body	*body = game->snake->body;
	t_body	*lastToFirst = game->last;
	int	xx = game->last->x;
	int	yy = game->last->y;
	draw_object(game->data.addr, xx, yy, bg_color, false);
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
		if (game->map[body->y / SSIZE][body->x / SSIZE] == 1 ||
			game->map[body->y / SSIZE][body->x / SSIZE] == 7)
		{
			reset_game(game);
			return ;
		}
		game->map[body->y / SSIZE][body->x / SSIZE] = 7;
		draw_snake(game, body, a);
		if (body->x == game->foodx && body->y == game->foody)
		{
			add_body(game->snake->body, game);
			generate_food(game);
			score++;
			if (score != 0 && score % 10 == 0)
			{
				bg_color += randomRange(10000, 1000000);
				score++;
				clear_image(game);
				draw_object(game->data.addr, xx, yy, bg_color, false);
			}
		}
		body = body->next;
	}
	draw_food(game);
	mlx_put_image_to_window(game->mlx, game->screen, game->data.img, 0, 0);
}
