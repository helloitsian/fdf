NAME = fdf

SRCS = parse_input.c \
	   rotate_points.c \
	   draw_grid.c \
	   draw_line.c \

MLX = ./minilibx_macos/

MLXFLAGS = -framework OpenGL -framework AppKit

GNL = ./get_next_line/get_next_line.c

all: $(NAME)

$(NAME):
		gcc $(SRCS) $(GNL) -L. -lft -I  $(MLX) -L $(MLX) -lmlx $(MLXFLAGS)

clean:
	rm -f $(NAME)

fclean: clean
		rm -f $(NAME)
re:
	fclean all
