#include "../include/snake.h"

void	move_event(t_game *game)
{
	t_body	*body = game->snake->body;
	if (move_dir == r)
		body->x += 50;
	if (move_dir == l)
		body->x -= 50;
	if (move_dir == u)
		body->y -= 50;
	if (move_dir == d)
		body->y += 50;
	mlx_clear_window(game->mlx, game->screen);
	draw_snake(game, 0x008000);
	game->f_counter = 0;
}