NAME = fdf
PATH_INC = ./libft/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = fdf.h

GNL = get_next_line/get_next_line.c
SRC =	parse_input.c \
		draw_grid.c \
		draw_line.c \
		rotate_points.c \

OBJ =	$(SRCS:.c=.o)


all: $(NAME)

$(OBJ): $(SRC)
		$(CC) -c $(CFLAGS) $(SRC)

$(LIBS):
		$(MAKE) -C ./libft

$(NAME): $(OBJ) $(LIBS)
		$(MAKE) -C libft/
		$(MAKE) -C minilibx_macos/
		$(CC) -o $(NAME) $(SRC) $(GNL) -L./libft/ -lft -L./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

clean:
		$(MAKE) -C libft/ clean
		rm -f $(OBJ)

fclean: clean
		$(MAKE) -C libft/ fclean
		rm -f $(NAME)

re:	fclean all
