#include "../inc/so_long.h"

static int	check_move(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->p_x = x;
		game->p_y = y;
		game->nmr_moves++;
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->p_x = x;
		game->p_y = y;
		game->nmr_collectibles--;
		game->nmr_moves++;
	}
	if (game->map[y][x] == 'E')
	{
		if (game->nmr_collectibles != 0)
			return (0);
		ft_printf("WOW Nice job, u won!\n");
	}
	return (1);
}

int	move_w(t_game *game, int key)
{
	int	x;
	int	y;
	int	control;

	x = game->p_x;
	y = game->p_y;
	if (game->map[y][x] == '1')
		return (0);
	control = check_move(game, x, y);
	if (!control)
		return (0);
	game->map[y + 1][x] == '0';
	ft_printf("Moves: %d\n", game->nmr_moves);
	return (1);
}

int	move_s(t_game *game, int key)
{
	int	x;
	int	y;
	int	control;

	x = game->p_x;
	y = game->p_y;
	if (game->map[y][x] == '1')
		return (0);
	control = check_move(game, x, y);
	if (!control)
		return (0);
	game->map[y - 1][x] == '0';
	ft_printf("Moves: %d\n", game->nmr_moves);
	return (1);
}

int	move_a(t_game *game, int key)
{
	int	x;
	int	y;
	int	control;

	x = game->p_x;
	y = game->p_y;
	if (game->map[y][x] == '1')
		return (0);
	control = check_move(game, x, y);
	if (!control)
		return (0);
	game->map[y][x - 1] == '0';
	ft_printf("Moves: %d\n", game->nmr_moves);
	return (1);
}

int	move_d(t_game *game, int key)
{
	int x;
	int y;
	int control;

	x = game->p_x;
	y = game->p_y;
	if (game->map[y][x] == '1')
		return (0);
	control = check_move(game, x, y);
	if (!control)
		return (0);
	game->map[y][x + 1] == '0';
	ft_printf("Moves: %d\n", game->nmr_moves);
	return (1);
}