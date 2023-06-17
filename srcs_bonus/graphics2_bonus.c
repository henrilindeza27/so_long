#include "../inc/so_long_bonus.h"

void	put_collect_sprite(t_game *game, int flag)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
			{
				load_graphics(&game->floor, game, x, y);
				if (flag == 0)
					load_graphics(&game->collect1, game, x, y);
				else if (flag == 1)
					load_graphics(&game->collect2, game, x, y);
			}
			x++;
		}
	}
	mlx_put_image_to_window(game->initmlx, game->winmlx, game->img.ptr, 0, 0);
}
int	anim_collect(t_game *game)
{
	static int i;
	print_on_screen(game);
	if(game->nmr_exit)
		random_move_enemy(game);
	if (i < 200)
		put_collect_sprite(game, 0);
	else if (i < 250)
		put_collect_sprite(game, 1);
	if (i == 250)
		i = 0;
	print_on_screen(game);
	i++;
	return (1);
}