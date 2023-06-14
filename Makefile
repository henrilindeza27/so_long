NAME = so_long
BONUS = so_long_bonus

SRCS = $(wildcard ./srcs/*.c)
OBJS = $(SRCS:.c=.o)

B_SRCS = $(wildcard ./srcs_bonus/*.c)
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