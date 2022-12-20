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
	game->gameSpeed = 300;
	init_map(game, HEIGHT / SSIZE, WIDTH / SSIZE);
	add_body(game->snake->body, game);
	add_body(game->snake->body, game);
	generate_food(game);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->screen);
		exit(0);
	}
	if (keycode == 0)
		move_dir = l;
	if (keycode == 1)
		move_dir = d;
	if (keycode == 2)
		move_dir = r;
	if (keycode == 13)
		move_dir = u;
	if (keycode == 12)
	{
		generate_food(game);
	}
	return (0);
}

void	draw_snake(t_game *game, int color)
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
		game->map[body->y / SSIZE][body->x / SSIZE] = 1;
		for (int i = 0; i < SSIZE; i++)
		{
			for (int j = 0; j < SSIZE; j++)
				mlx_pixel_put(game->mlx, game->screen, body->x + j, body->y + i, color);
		}
		if (body->x > WIDTH || body->x < 0 || body->y > HEIGHT || body->y < 0)
			exit(0);
		if (body->x == game->foodx && body->y == game->foody)
		{
			add_body(game->snake->body, game);
			generate_food(game);
			game->gameSpeed -= 10;
		}
		body = body->next;
	}
	for (int i = 0; i < SSIZE; i++)
	{
		for (int j = 0; j < SSIZE; j++)
			mlx_pixel_put(game->mlx, game->screen, j + game->foodx, i + game->foody, 0xFF0000);
	}
	printf("snake x %d   snake y %d   foodx %d   foody %d\n", game->snake->body->x, game->snake->body->y, game->foodx, game->foody);
}

void	add_body(t_body *body, t_game *game)
{
	t_body	*tmp = body;
	t_body	*new = malloc(sizeof(t_body));
	while (tmp && tmp->next)
		tmp = tmp->next;
	new->prev = tmp;
	tmp->next = new;
	new->next = NULL;
	game->last = new;
	new->x = body->x;
	new->y = body->y;
	new->next_x = body->x;
	new->next_y = body->y;
	game->snake->snake_len++;
}

void	generate_food(t_game *game)
{
	int randomx = randomRange(0, WIDTH / SSIZE);
	int randomy = randomRange(0, HEIGHT / SSIZE);
	while (game->map[randomy][randomx] == 1)
	{
		randomx = randomRange(0, WIDTH / SSIZE - 2);
		randomy = randomRange(0, HEIGHT / SSIZE - 2);
	}
	game->map[randomy][randomx] = 2;
	game->foodx = randomx * SSIZE;
	game->foody = randomy * SSIZE;
}