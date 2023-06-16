/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique <henrique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:56:05 by henrique          #+#    #+#             */
/*   Updated: 2023/06/15 18:56:10 by henrique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void	ft_free(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	exit_game(t_game *game)
{
	ft_free(game->map);
	if (game->winmlx)
		mlx_destroy_window(game->initmlx, game->winmlx);
	free(game->initmlx);
	exit(0);
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
