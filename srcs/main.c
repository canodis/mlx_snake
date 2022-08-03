#include "../include/snake.h"

int	move_dir = 0;

void	draw_snake(t_game *game, int color)
{
	t_body	*body = game->snake->body;
	for (int a = 0; a < game->snake->snake_len; a++)
	{
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
				mlx_pixel_put(game->mlx, game->screen, body->x + j, body->y + i, color);
		}
		body = body->next;
	}
		
}

void	add_body(t_body *body)
{
	t_body	*tmp;
	t_body	*new;
	t_snake *new = malloc(sizeof(t_body));
	while (tmp->next)
		tmp = tmp->next;
	new->prev = tmp;
	new->next = NULL;
	tmp->next = new;

}

int	update(t_game *game)
{
	game->f_counter++;
	if (move_dir != 0 && game->f_counter >= 5000)
		move_event(game);
	return (0);
}

int main(int argc, char **argv)
{
	t_game	game;
	init_all(&game);
	mlx_hook(game.screen, 2, 0, key_hook, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
}
