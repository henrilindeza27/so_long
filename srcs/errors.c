/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique <henrique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:35:07 by henrique          #+#    #+#             */
/*   Updated: 2023/05/26 16:25:17 by henrique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	flod_fill(char **map, int x, int y, int *counter)
{
	if (map[y][x] == 'C' || map[y][x] == 'E')
		*counter += 1;
	map[y][x] = 'F';
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'F')
		flod_fill(map, x + 1, y, counter);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'F')
		flod_fill(map, x - 1, y, counter);
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'F')
		flod_fill(map, x, y + 1, counter);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'F')
		flod_fill(map, x, y - 1, counter);
}

static int	handle_flod_fill(t_game *game)
{
	int		counter;
	char	**map_tmp;
	int		i;

	map_tmp = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!map_tmp)
		return (0);
	counter = 0;
	i = -1;
	while (game->map[++i])
		map_tmp[i] = ft_strdup(game->map[i]);
	map_tmp[i] = NULL;
	flod_fill(map_tmp, game->p_x, game->p_y, &counter);
	ft_free(map_tmp);
	return (counter == (game->nmr_exit + game->nmr_collectibles));
}

static int	check_file_extension(char *filename, char *extension)
{
	char	*file_extension;

	file_extension = ft_strrchr(filename, '.');
	if (file_extension && ft_strncmp(file_extension, extension, 4) == 0)
		return (1);
	return (0);
}

void	read_characters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (game->map[i][j] == 'C')
				game->nmr_collectibles++;
			else if (game->map[i][j] == 'E')
				game->nmr_exit++;
			else if (game->map[i][j] == 'P')
			{
				game->p_x = i;
				game->p_y = j;
				game->nmr_player++;
			}
		}
	}
}

int	check_errors(t_game *game, char *file, int argc)
{
	int	error;

	error = 1;
	if (argc != 2)
		ft_printf("Error(%d), wrong number of args\n", error--);
	else if (!check_file_extension(file, ".ber"))
		ft_printf("Error(%d), wrong extension\n", error--);
	else if (!game->map)
		ft_printf("Error(%d), the map is empty\n", error--);
	else if (!check_map_size(game) || (game->map_height == game->map_width))
		ft_printf("Error(%d), the map is not rectangle\n", error--);
	else if (!check_limits(game))
		ft_printf("Error(%d), the map must be surrounded by walls!\n", error--);
	else if (game->nmr_collectibles < 1)
		ft_printf("Error(%d), the map must have at least 1 collectible !\n",
					error--);
	else if (game->nmr_exit != 1)
		ft_printf("Error(%d), the map must have only/at least 1 exit!\n",
					error--);
	else if (game->nmr_player != 1)
		ft_printf("Error(%d), the map must have only/at least 1 player!\n",
					error--);
	else if (!handle_flod_fill(game))
		ft_printf("Error(%d), no way to reach the final checkpoint\n", error--);
	return (error);
}
