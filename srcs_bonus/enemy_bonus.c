#include "../inc/so_long_bonus.h"

void	read_enemy(t_game *game)
{
	int	x;
	int	y;
	int	n;

	game->enemy_x = malloc(sizeof(int) * game->nmr_enemys);
	if (!game->enemy_x)
		return ;
	game->enemy_y = malloc(sizeof(int) * game->nmr_enemys);
	if (!game->enemy_y)
		return ;
	n = -1;
	y = -1;
	while (game->map[++y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'Y')
			{
				game->enemy_x[++n] = x;
				game->enemy_y[n] = y;
			}
			x++;
		}
	}
}
void	move_a_enemy(t_game *game, int flag)
{
	int	x;
	int	y;

	x = game->enemy_x[flag];
	y = game->enemy_y[flag];
	if (game->map[y][x - 1] == '1' || game->map[y][x - 1] == 'E'
		|| game->map[y][x - 1] == 'C' || game->map[y][x - 1] == 'Y')
		return ;
	if (game->map[y][x - 1] == 'P')
		exit_game(game);
	game->map[y][x] = '0';
	game->map[y][x - 1] = 'Y';
	load_graphics(&game->floor, game, x, y);
	load_graphics(&game->floor, game, x - 1, y);
	load_graphics(&game->enemy2, game, x - 1, y);
	mlx_put_image_to_window(game->initmlx, game->winmlx, game->img.ptr, 0, 0);
	game->enemy_x[flag]--;
}

void	move_d_enemy(t_game *game, int flag)
{
	int	x;
	int	y;

	x = game->enemy_x[flag];
	y = game->enemy_y[flag];
	if (game->map[y][x + 1] == '1' || game->map[y][x + 1] == 'E'
		|| game->map[y][x + 1] == 'C' || game->map[y][x + 1] == 'Y')
		return ;
	if (game->map[y][x + 1] == 'P')
		exit_game(game);
	game->map[y][x] = '0';
	game->map[y][x + 1] = 'Y';
	load_graphics(&game->floor, game, x, y);
	load_graphics(&game->floor, game, x + 1, y);
	load_graphics(&game->enemy1, game, x + 1, y);
	mlx_put_image_to_window(game->initmlx, game->winmlx, game->img.ptr, 0, 0);
	game->enemy_x[flag]++;
}

void	random_move_enemy(t_game *game)
{
	int i;
	static int n;
	i = -1;

	if (n == 1500)
	{
		while (game->enemy_x[++i])
			move_d_enemy(game, i);
	}
	else if(n == 3000)
	{
		while (game->enemy_x[++i])
			move_a_enemy(game, i);
		n = 0;
	}
	n++;
}