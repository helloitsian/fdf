#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft.h"
# include <math.h>

typdef struct s_mlxwin
{
	void *mlx;
	void *win;
} t_mlxwin;

typedef struct s_3D
{
   float x;
   float y;
   float z;
} t_3D;

void	isometric(t_3D **points, int x, int y);
void  	draw_line(int x1, int x2, int y1, int y2, void *mlx, void *win);
void	init_draw(t_3D **points, int x, int y);

#endif
