#include "../inc/so_long.h"


void	place_player(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->initmlx,
		game->winmlx, game->player, width * 50, height * 50);
	game->p_y = height;
	game->p_x = width;
}

void	place_collectable(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->initmlx,
		game->winmlx, game->collect, width * 50, height * 50);
	game->nmr_collectibles++;
}

void init_images(t_game *game)
{
    int i;
    int j;

    game->player =  mlx_xpm_file_to_image(game->initmlx,"textures/porco.xpm", &i, &j);
    game->wall = mlx_xpm_file_to_image(game->initmlx,"textures/terra.xpm", &i, &j);
    game->exit = mlx_xpm_file_to_image(game->initmlx,"textures/door.xpm", &i, &j);
    game->collect = mlx_xpm_file_to_image(game->initmlx,"textures/maca.xpm", &i, &j);
}

void put_graphics(t_game *game)
{
    int width;  
	int height;

    height = 0;
	while (height < game->map_height)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->initmlx,
					game->winmlx, game->wall, width * 50, height * 50);
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->initmlx,
					game->winmlx, game->exit, width * 50, height * 50);
			
			width++;
		}
		height++;
	}
}
