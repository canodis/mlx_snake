#include "../include/snake.h"

void	move_event(t_game *game)
{
	t_body	*body = game->snake->body;

	if (move_dir == r)
		body->next_x += SSIZE;
	if (move_dir == l)
		body->next_x -= SSIZE;
	if (move_dir == u)
		body->next_y -= SSIZE;
	if (move_dir == d)
		body->next_y += SSIZE;
	draw(game);
	game->f_counter = 0;
}
