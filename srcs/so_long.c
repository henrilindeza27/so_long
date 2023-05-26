#include "../inc/so_long.h"

void	ft_free(char **map)
{
	int	y;

	y = -1;
	while (map[++y])
		free(map[y]);
	free(map);
}

int	control_hooks(t_game *game, int key)
{
	int	c;

	if (key == 65307)
		//sair do jogo
	if (key == 119)
		c = move_w(game, key);
	if (key == 115)
		c = move_s(game, key);
	if (key == 97)
		c = move_a(game, key);
	if (key == 100)
		c = move_d(game, key);
	if(c)
		//load graficos
	return 1;
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
	game.winmlx = mlx_new_window(game.initmlx, (game.map_width * 50),
			(game.map_height * 50), "yes");

	return (0);
}