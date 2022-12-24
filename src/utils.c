#include "../include/snake.h"
#include <sys/time.h>

void	free_all(t_game *game)
{
	t_body	*tmp = game->snake->body;
	while (tmp)
	{
		tmp = tmp->next;
		free(game->snake->body);
		game->snake->body = tmp;
	}
	free (game->snake->body);
	free (game->snake);
	mlx_destroy_image(game->mlx, game->data.img);
	mlx_destroy_window(game->mlx, game->screen);
	exit(0);
}

void	printmap(t_game *game)
{
	printf("\n=======================================\n");
	for (int y = 0; y < HEIGHT / SSIZE; y++)
	{
		for (int x = 0; x < WIDTH / SSIZE; x++)
			printf("%d", game->map[y][x]);
		printf("\n");
	}
	printf("\n=======================================\n");
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
	if (game->map[randomy][randomx] == 1 || randomx * SSIZE >= WIDTH - SSIZE || randomx * SSIZE < SSIZE || 
		randomy * SSIZE >= HEIGHT - SSIZE || randomy * SSIZE < SSIZE || game->map[randomy][randomx] == 7)
	{
		generate_food(game);
		return ;
	}
	game->map[randomy][randomx] = 2;
	game->foodx = randomx * SSIZE;
	game->foody = randomy * SSIZE;
}

int	randomRange(int min, int max)
{
	struct timeval t;
	gettimeofday(&t, 0);
	srand(t.tv_sec + t.tv_usec);
	return (rand() % (max - min + 1) + min);
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