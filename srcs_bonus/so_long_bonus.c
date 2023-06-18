/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique <henrique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 01:45:07 by henrique          #+#    #+#             */
/*   Updated: 2023/06/18 01:45:18 by henrique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_free(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	free_images(t_game *game)
{
	mlx_destroy_image(game->initmlx, game->img.ptr);
	mlx_destroy_image(game->initmlx, game->wall.ptr);
	mlx_destroy_image(game->initmlx, game->player_a.ptr);
	mlx_destroy_image(game->initmlx, game->player_d.ptr);
	mlx_destroy_image(game->initmlx, game->player_s.ptr);
	mlx_destroy_image(game->initmlx, game->player_w.ptr);
	mlx_destroy_image(game->initmlx, game->exit.ptr);
	mlx_destroy_image(game->initmlx, game->exit2.ptr);
	mlx_destroy_image(game->initmlx, game->collect1.ptr);
	mlx_destroy_image(game->initmlx, game->collect2.ptr);
	mlx_destroy_image(game->initmlx, game->enemy1.ptr);
	mlx_destroy_image(game->initmlx, game->enemy2.ptr);
	mlx_destroy_image(game->initmlx, game->floor.ptr);
	free(game->enemy_x);
	free(game->enemy_y);
}

void	exit_game(t_game *game)
{
	ft_free(game->map);
	if (game->winmlx)
		mlx_destroy_window(game->initmlx, game->winmlx);
	free_images(game);
	mlx_destroy_display(game->initmlx);
	free(game->initmlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	read_map(&game, argv[1]);
	if (!check_errors(&game, argv[1], argc))
	{
		ft_free(game.map);
		return (0);
	}
	game.initmlx = mlx_init();
	game.winmlx = mlx_new_window(game.initmlx, (game.map_width * 64),
			(game.map_height * 64), "Creep Cat");
	init_images(&game);
	mlx_loop_hook(game.initmlx, &anim_collect, &game);
	mlx_key_hook(game.winmlx, &control_hooks, &game);
	mlx_hook(game.winmlx, 17, 0L, (void *)exit_game, &game);
	mlx_loop(game.initmlx);
	return (0);
}
