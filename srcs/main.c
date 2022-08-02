#include "../include/snake.h"

int	g_x = 0;
int	g_y = 0;
int	move_dir = 0;
int	counter = 0;

void	draw_square(t_game *game, int x, int y)
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
			mlx_pixel_put(game->mlx, game->screen, x + j, y + i, 0x008000);
	}
}

int	update(t_game *game)
{
	counter++;
	if (move_dir != 0 && counter >= 5000)
	{
		if (move_dir == r)
			g_x += 50;
		if (move_dir == l)
			g_x -= 50;
		if (move_dir == u)
			g_y -= 50;
		if (move_dir == d)
			g_y += 50;
		mlx_clear_window(game->mlx, game->screen);
		draw_square(game, g_x, g_y);
		counter = 0;
	}
}

int main(int argc, char **argv)
{
	t_game	game;
	init_all(&game);
	mlx_hook(game.screen, 2, 0, key_hook, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
}
