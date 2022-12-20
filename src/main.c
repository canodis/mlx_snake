#include "../include/snake.h"

int	move_dir = 0;
int	body_color = 0x00FF00;
int	head_color = 0x0000FF;

int	update(t_game *game)
{
	if (game->speed_up)
		game->gameSpeed = 2000;
	else
		game->gameSpeed = 5000;
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
	mlx_hook(game.screen, 3, 2, key_up, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
}
