#include "../include/snake.h"

int	move_dir = 0;

int	update(t_game *game)
{
	game->f_counter++;
	if (move_dir != 0 && game->f_counter >= game->gameSpeed)
		move_event(game);
	return (0);
}

int main(int argc, char **argv)
{
	t_game	game;
	init_all(&game);
	mlx_hook(game.screen, 2, 1, key_hook, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
}
