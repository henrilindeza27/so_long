NAME = so_long

SRCS = $(wildcard ./srcs/*.c)
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -Iinc/
MLXFLAGS = -lXext -lX11 -lm -lz
LIBFT = libft/libft.a
MLX = minilibx/libmlx_Linux.a

all: $(NAME)

.PHONY: all, fclean, re

$(NAME): $(OBJS)
		make -C minilibx/
		make -C libft/
		cc $(FLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME) 

clean:
	rm -f $(OBJS)
	make clean -C minilibx/
	make fclean -C libft/
	
fclean: clean
	rm -f ${NAME}

re: fclean all