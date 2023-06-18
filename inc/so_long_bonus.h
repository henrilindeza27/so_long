/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique <henrique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 02:06:06 by henrique          #+#    #+#             */
/*   Updated: 2023/06/18 02:06:16 by henrique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		x;
	int		y;
	int		endian;
}			t_data;

typedef struct s_game
{
	char	**map;
	int		map_width;
	int		map_height;

	int		nmr_moves;
	int		nmr_collectibles;
	int		nmr_exit;
	int		nmr_player;
	int		nmr_enemys;

	t_data	img;
	t_data	wall;
	t_data	player_w;
	t_data	player_a;
	t_data	player_s;
	t_data	player_d;
	t_data	exit;
	t_data	exit2;
	t_data	collect1;
	t_data	collect2;
	t_data	enemy1;
	t_data	enemy2;
	t_data	floor;

	int		p_x;
	int		p_y;
	int		*enemy_x;
	int		*enemy_y;

	int		ex_x;
	int		ex_y;

	void	*initmlx;
	void	*winmlx;

}			t_game;

int			read_map(t_game *game, char *file);
int			check_map_size(t_game *game);
int			check_limits(t_game *game);
int			read_characters(t_game *game);
void		ft_free(char **map);
int			check_errors(t_game *game, char *file, int argc);

int			control_hooks(int key, t_game *game);

void		init_images(t_game *game);
void		put_graphics(t_game *game);
void		load_graphics(t_data *type, t_game *game, int x_pos, int y_pos);
void		refresh_graphics_player(t_game *game, int x_pos, int y_pos,
				char flag);

void		print_on_screen(t_game *game);
void		exit_game(t_game *game);

int			anim_collect(t_game *game);
void		read_enemy(t_game *game);
void		save_coords(t_game *game, int i, int j, int flag);

void		random_move_enemy(t_game *game);
void		help_graph(t_game *game, int x, int y);
#endif
