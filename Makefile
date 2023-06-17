NAME = so_long
BONUS = so_long_bonus

SRCS = srcs/errors.c srcs/graphics.c srcs/hooks.c srcs/map.c\
		srcs/so_long.c srcs/utilits.c
OBJS = $(SRCS:.c=.o)

B_SRCS = srcs_bonus/enemy_bonus.c srcs_bonus/errors_bonus.c\
		srcs_bonus/graphics_bonus.c srcs_bonus/graphics2_bonus.c\
		srcs_bonus/hooks_bonus.c srcs_bonus/map_bonus.c\
		srcs_bonus/so_long_bonus.c srcs_bonus/utilits_bonus.c
B_OBJS = $(B_SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -Iinc/
MLXFLAGS = -lXext -lX11 -lm -lz
LIBFT = libft/libft.a
MLX = minilibx/libmlx_Linux.a


all: $(NAME) $(BONUS)

.PHONY: all, fclean, re

$(NAME): $(OBJS)
		make -C minilibx/
		make -C libft/
		cc $(FLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME) 

bonus: $(B_OBJS)
		make -C minilibx/
		make -C libft/
		cc $(FLAGS) $(B_OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(BONUS) 
clean:
	rm -f $(OBJS) $(B_OBJS)
	make clean -C minilibx/
	make fclean -C libft/
	
fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all