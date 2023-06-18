/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique <henrique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 01:45:33 by henrique          #+#    #+#             */
/*   Updated: 2023/06/18 01:48:51 by henrique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	refresh_graphics_player(t_game *game, int x_pos, int y_pos, char flag)
{
	load_graphics(&game->floor, game, x_pos, y_pos);
	if (flag == 'w')
	{
		load_graphics(&game->floor, game, x_pos, y_pos - 1);
		load_graphics(&game->player_w, game, x_pos, y_pos - 1);
	}
	else if (flag == 's')
	{
		load_graphics(&game->floor, game, x_pos, y_pos + 1);
		load_graphics(&game->player_s, game, x_pos, y_pos + 1);
	}
	else if (flag == 'a')
	{
		load_graphics(&game->floor, game, x_pos - 1, y_pos);
		load_graphics(&game->player_a, game, x_pos - 1, y_pos);
	}
	else if (flag == 'd')
	{
		load_graphics(&game->floor, game, x_pos + 1, y_pos);
		load_graphics(&game->player_d, game, x_pos + 1, y_pos);
	}
	if (game->nmr_collectibles == 0)
		load_graphics(&game->exit2, game, game->ex_x, game->ex_y);
	mlx_put_image_to_window(game->initmlx, game->winmlx, game->img.ptr, 0, 0);
}

void	print_on_screen(t_game *game)
{
	char	*print;
	char	*move;

	move = ft_itoa(game->nmr_moves);
	print = ft_strjoin("Moves: ", move);
	mlx_string_put(game->initmlx, game->winmlx, 70, 30, 0xffffff, print);
	free(print);
	free(move);
}

void	save_coords(t_game *game, int i, int j, int flag)
{
	if (flag == 0)
	{
		game->ex_x = j;
		game->ex_y = i;
		game->nmr_exit++;
	}
	if (flag == 1)
	{
		game->p_x = j;
		game->p_y = i;
		game->nmr_player++;
	}
}

void	help_graph(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0' || game->map[y][x] == 'P'
		|| game->map[y][x] == 'C' || game->map[y][x] == 'Y')
	{
		{
			load_graphics(&game->floor, game, x, y);
			if (game->map[y][x] == 'P')
				load_graphics(&game->player_s, game, x, y);
			else if (game->map[y][x] == 'C')
				load_graphics(&game->collect1, game, x, y);
			else if (game->map[y][x] == 'Y')
				load_graphics(&game->enemy1, game, x, y);
		}
	}
	else if (game->map[y][x] == '1')
		load_graphics(&game->wall, game, x, y);
	else if (game->map[y][x] == 'E')
		load_graphics(&game->exit, game, x, y);
}
