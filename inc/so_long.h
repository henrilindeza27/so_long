#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	char	**map;
	int map_width;  //x
	int map_height; //y

	int		nmr_moves;
	int		nmr_collectibles;
	int		nmr_exit;
	int		nmr_player;

	void	*wall;
	void	*player;
	void	*exit;
	void	*collect;
	void	*floor;

	int		p_x;
	int		p_y;

	void	*initmlx;
	void	*winmlx;

}			t_game;

int			read_map(t_game *game, char *file);
int			check_map_size(t_game *game);
int			check_limits(t_game *game);
void		read_characters(t_game *game);
void		ft_free(char **map);
int			check_errors(t_game *game, char *file, int argc);

int			move_w(t_game *game, int key);
int			move_s(t_game *game, int key);
int			move_a(t_game *game, int key);
int			move_d(t_game *game, int key);

void		init_images(t_game *game);
void		put_graphics(t_game *game);
#endif
