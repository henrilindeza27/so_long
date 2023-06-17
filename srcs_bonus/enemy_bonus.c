/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique <henrique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:43:20 by henrique          #+#    #+#             */
/*   Updated: 2023/06/17 13:43:25 by henrique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	load_graphics(&game->floor, game, x, y);
	load_graphics(&game->floor, game, x - 1, y);
	load_graphics(&game->enemy1, game, x - 1, y);
	mlx_put_image_to_window(game->initmlx, game->winmlx, game->img.ptr, 0, 0);
	game->map[y][x] = '0';
	game->map[y][x - 1] = 'Y';
	game->enemy_x[flag] -= 1;
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
	load_graphics(&game->floor, game, x, y);
	load_graphics(&game->floor, game, x + 1, y);
	load_graphics(&game->enemy2, game, x + 1, y);
	mlx_put_image_to_window(game->initmlx, game->winmlx, game->img.ptr, 0, 0);
	game->map[y][x] = '0';
	game->map[y][x + 1] = 'Y';
	game->enemy_x[flag] += 1;
}

void	help_move(t_game *game, int *flag, int i)
{
	if (!*flag)
	{
		if (game->map[game->enemy_y[i]][game->enemy_x[i] + 1] == '0')
			move_d_enemy(game, i);
		else if (game->map[game->enemy_y[i]][game->enemy_x[i] - 1] == '0')
		{
			move_a_enemy(game, i);
			*flag = 1;
		}
	}
	else
	{
		if (game->map[game->enemy_y[i]][game->enemy_x[i] - 1] == '0')
			move_a_enemy(game, i);
		else if (game->map[game->enemy_y[i]][game->enemy_x[i] + 1] == '0')
		{
			move_d_enemy(game, i);
			*flag = 0;
		}
	}
}

void	random_move_enemy(t_game *game)
{
	static int	n;
	static int	w;
	static int	flag;
	int			i;

	i = -1;
	if (w == 0)
		w = 200;
	if (n == w)
	{
		w += 200;
		while (++i < game->nmr_enemys)
			help_move(game, &flag, i);
		i = 0;
	}
	n++;
}
