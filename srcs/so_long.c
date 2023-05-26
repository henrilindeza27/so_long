#include "../inc/so_long.h"

void	ft_free(char **map)
{
	int	y;

	y = -1;
	while (map[++y])
		free(map[y]);
	free(map);
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
	game.winmlx = mlx_new_window(game.initmlx, (game.map_width * 50),(game.map_height * 50), "yes");
	
	return (0);
}