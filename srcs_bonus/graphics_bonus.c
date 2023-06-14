#include "../inc/so_long_bonus.h"

void	pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->img.addr + (y * game->img.line_length + x * (game->img.bpp
				/ 8));
	*(unsigned int *)dst = color;
}

t_data	create_img(char *path, t_game *game)
{
	t_data	img;

	img.img_ptr = mlx_xpm_file_to_image(game->initmlx, path, &img.x, &img.y);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.line_length,
			&img.endian);
	return (img);
}

void	init_images(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->initmlx, game->map_width * 64,
			game->map_height * 64);
	game->img.addr = mlx_get_data_addr(game->img.img_ptr, &(game->img.bpp),
			&(game->img.line_length), &(game->img.endian));
	game->floor = create_img("textures/floor.xpm", game);
	game->wall = create_img("textures/wall.xpm", game);
	game->player_w = create_img("textures/w.xpm", game);
	game->player_a = create_img("textures/a.xpm", game);
	game->player_s = create_img("textures/s.xpm", game);
	game->player_d = create_img("textures/d.xpm", game);
	game->exit = create_img("textures/trap.xpm", game);
	game->exit2 = create_img("textures/trap2.xpm", game);
	game->collect = create_img("textures/polv1.xpm", game);
	put_graphics(game);
	print_on_screen(game);
}

void	load_graphics(t_data *type, t_game *game, int x_pos, int y_pos)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < type->y)
	{
		x = 0;
		while (x < type->x)
		{
			color = *(unsigned int *)(type->addr + y * type->line_length + x
					* (type->bpp / 8));
			if (color != 4278190080)
				pixel_put(game, x_pos * 64 + x, y_pos * 64 + y, color);
			x++;
		}
		y++;
	}
}

void	put_graphics(t_game *game)
{
	int x;
	int y;
	y = -1;
	x = 0;
	while (game->map[++y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0' || game->map[y][x] == 'P'
				|| game->map[y][x] == 'C')
			{
				load_graphics(&game->floor, game, x, y);

				if (game->map[y][x] == 'P')
					load_graphics(&game->player_s, game, x, y);
				else if (game->map[y][x] == 'C')
					load_graphics(&game->collect, game, x, y);
			}
			else if (game->map[y][x] == '1')
				load_graphics(&game->wall, game, x, y);
			else if (game->map[y][x] == 'E')
				load_graphics(&game->exit, game, x, y);
			x++;
		}
		x = 0;
	}
	
	mlx_put_image_to_window(game->initmlx, game->winmlx, game->img.img_ptr, 0,
			0);

}