#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft.h"
# include <math.h>

# include <stdio.h>

typedef struct s_2D
{
   float x;
   float y;
} t_2D;

typedef struct s_3D
{
   float x;
   float y;
   float z;
} t_3D;

void	rotate_point(t_3D *point);
void  	draw_line(float x1, float x2, float y1, float y2, void *mlx, void *win);
void	init_draw(t_3D **points, int x, int y);

#endif
