#include "../include/snake.h"

int	key_hook(int keycode, t_game *game)
{
	if (GG == 777)
	{
		if (keycode == 53)
		free_all(game);
		if (keycode == 0 && move_dir != r)
			move_dir = l;
		if (keycode == 1 && move_dir != u)
			move_dir = d;
		if (keycode == 2 && move_dir != l)
			move_dir = r;
		if (keycode == 13 && move_dir != d)
			move_dir = u;
		if (keycode == 257)
		{
			body_color = 0x9A12B2;
			game->speed_up = true;
		}
		if (keycode == 8)
		{
			if (game->discoMode)
				game->discoMode = false;
			else
				game->discoMode = true;
		}
	}
	else if (GG == 666)
	{
		if (keycode == 65307)
			free_all(game);
		if (keycode == 97 && move_dir != r)
			move_dir = l;
		if (keycode == 115 && move_dir != u)
			move_dir = d;
		if (keycode == 100 && move_dir != l)
			move_dir = r;
		if (keycode == 119 && move_dir != d)
			move_dir = u;
		if (keycode == 65505)
		{
			body_color = 0x9A12B2;
			game->speed_up = true;
		}
		if (keycode == 99)
		{
			if (game->discoMode)
				game->discoMode = false;
			else
				game->discoMode = true;
		}
	}
	return (0);
}

int	key_up(int keycode, t_game *game)
{
	if (GG == 777)
	{
		if (keycode == 257)
		{
			body_color = 0x00FF00;
			game->speed_up = false;
		}
	}
	else
	{
		if (keycode == 65505)
		{
			body_color = 0x00FF00;
			game->speed_up = false;
		}
	}
		
	return (0);
}