#include "../inc/so_long.h"

void refresh_graphics_player(t_game *game, int x_pos, int y_pos, char flag)
{
	load_graphics(&game->floor, game, x_pos, y_pos);
	if(flag == 'w')
	{
		load_graphics(&game->floor, game, x_pos, y_pos - 1);
		load_graphics(&game->player_w, game, x_pos, y_pos - 1);
	}
	else if(flag == 's')
	{
		load_graphics(&game->floor, game, x_pos, y_pos + 1);
		load_graphics(&game->player_s, game, x_pos, y_pos + 1);
	}
	else if(flag == 'a')
	{
		load_graphics(&game->floor, game, x_pos - 1, y_pos);
		load_graphics(&game->player_a, game, x_pos - 1, y_pos);
	}
	else if(flag == 'd')
	{
		load_graphics(&game->floor, game, x_pos + 1, y_pos);
		load_graphics(&game->player_d, game, x_pos + 1, y_pos);
	}
	if(game->nmr_collectibles == 0)
		load_graphics(&game->exit2, game, game->ex_x, game->ex_y);
	mlx_put_image_to_window(game->initmlx, game->winmlx, game->img.img_ptr, 0, 0);

}

void print_on_screen(t_game *game)
{
	char *str;

	str = ft_itoa(game->nmr_moves);
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

int	main(int argc, char **argv)
{
	t_game game;

	ft_memset(&game, 0, sizeof(t_game));
	read_map(&game, argv[1]);
	read_characters(&game);
	if (!check_errors(&game, argv[1], argc))
		return (0);
	game.initmlx = mlx_init();
	game.winmlx = mlx_new_window(game.initmlx, (game.map_width * 64),
			(game.map_height * 64), "yes");
	init_images(&game);
	mlx_key_hook(game.winmlx, &control_hooks, &game);
	mlx_hook(game.winmlx, 17, 0L, exit_game, &game);
	mlx_loop(game.initmlx);

	return (0);
}