#include "../inc/so_long_bonus.h"


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
	if (!check_errors(&game, argv[1], argc))
		return (0);
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