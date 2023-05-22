NAME = so_long
all: $(NAME)

.PHONY: all, fclean, re

$(NAME):
	cc srcs/map.c srcs/errors.c srcs/so_long.c -Iinc -Llibft -lft -o so_long

fclean: 
	rm -f ${NAME}

re: fclean all