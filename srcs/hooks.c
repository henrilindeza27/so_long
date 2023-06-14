#include "../inc/so_long.h"

int	move_w(t_game *game, int key)
{
	int	x;
	int	y;

	x = game->p_x;
	y = game->p_y;
	if (game->map[y - 1][x] == 'E' && game->nmr_collectibles == 0)
		exit_game(game);
	if (game->map[y - 1][x] == '1' || (game->map[y - 1][x] == 'E'
			&& game->nmr_collectibles != 0))
		return (0);
	else if (game->map[y - 1][x] == 'C')
		game->nmr_collectibles--;
	refresh_graphics_player(game, x, y , 'w');
	game->map[y][x] = '0';
	game->map[y - 1][x] = 'P';
	game->p_y--;
	game->nmr_moves++;
	ft_printf("Moves: %d\n", game->nmr_moves);
	return (1);
}

int	move_s(t_game *game, int key)
{
	int	x;
	int	y;

	x = game->p_x;
	y = game->p_y;
	if (game->map[y + 1][x] == '1' || (game->map[y + 1][x] == 'E'
			&& game->nmr_collectibles != 0))
		return (0);
	if (game->map[y + 1][x] == 'E' && game->nmr_collectibles == 0)
		exit_game(game);
	else if (game->map[y + 1][x] == 'C')
		game->nmr_collectibles--;
	refresh_graphics_player(game, x, y , 's');
	game->map[y][x] = '0';
	game->map[y + 1][x] = 'P';
	game->p_y++;
	game->nmr_moves++;
	ft_printf("Moves: %d\n", game->nmr_moves);
	return (1);
}

int	move_a(t_game *game, int key)
{
	int	x;
	int	y;

	x = game->p_x;
	y = game->p_y;
	if (game->map[y][x - 1] == '1' || game->map[y][x - 1] == 'E'
		&& game->nmr_collectibles != 0)
		return (0);
	if (game->map[y][x - 1] == 'E' && game->nmr_collectibles == 0)
		exit_game(game);
	else if (game->map[y][x - 1] == 'C')
		game->nmr_collectibles--;
	refresh_graphics_player(game, x, y , 'a');
	game->map[y][x] = '0';
	game->map[y][x - 1] = 'P';
	game->p_x--;
	game->nmr_moves++;
	ft_printf("Moves: %d\n", game->nmr_moves);
	return (1);
}

int	move_d(t_game *game, int key)
{
	int	x;
	int	y;

	x = game->p_x;
	y = game->p_y;
	if (game->map[y][x + 1] == '1' || game->map[y][x + 1] == 'E'
		&& game->nmr_collectibles != 0)
		return (0);
	if (game->map[y][x + 1] == 'E' && game->nmr_collectibles == 0)
		exit_game(game);
	else if (game->map[y][x + 1] == 'C')
		game->nmr_collectibles--;
	refresh_graphics_player(game, x, y , 'd');
	game->map[y][x] = '0';
	game->map[y][x + 1] = 'P';
	game->p_x++;
	game->nmr_moves++;
	ft_printf("Moves: %d\n", game->nmr_moves);
	return ('d');
}

int	control_hooks(int key, t_game *game)
{
	if (key == 65307)
		exit_game(game);
	if (key == 119)
		move_w(game, key);
	if (key == 115)
		move_s(game, key);
	if (key == 97)
		move_a(game, key);
	if (key == 100)
		move_d(game, key);
	return (1);
}