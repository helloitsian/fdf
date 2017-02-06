#include "fdf.h"
#include <unistd.h>

static void draw_map(t_3D **points, int x, int y, void *mlx, void *win)
{
	t_3D *current;
	t_3D *right;
	t_3D *down;
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			printf("FLAG0.0\n");
			right = NULL;
			down = NULL;
			current = &points[i][j];
			if (j < x - 1)
				right = &points[i][j + 1];
			if (i < y - 1)
				down = &points[i + 1][j];
			printf("current - x: %f y: %f z: %f \n",
					current->x, current->y, current->z);
			printf("FLAG0.1\n");
			if (current)
			{
				rotate_point(current);
				current->y = current->z;
			}
			printf("FLAG0.2\n");
			if (right)
			{
				rotate_point(right);
				right->y = right->z;
				//draw_line(current->x * 30, right->x * 30, current->y * 30, right->y * 30, mlx, win);
				printf("right - x: %f y: %f z: %f \n",
					right->x, right->y, right->z);
			}
			printf("FLAG0.3\n");
			if (down)
			{
				rotate_point(down);
				down->y = down->z;
				//draw_line(current->x * 30, down->x * 30, current->y * 30, down->y * 30, mlx, win);
				printf("down - x: %f y: %f z: %f \n",
					down->x, down->y, down->z);
			}
			printf("FLAG0.4\n");
			j++;
		}
		i++;
	}
}

void	init_draw(t_3D **points, int x, int y)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "draw grid");
	//draw_line(0, 10, 0, 10, mlx, win);
	draw_map(points, x, y, mlx, win);
	mlx_loop(mlx);
}
