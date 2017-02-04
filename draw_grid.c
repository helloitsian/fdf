#include "fdf.h"

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
			right = NULL;
			down = NULL;
			current = &points[i][j];
			if (j < x - 2)
				right = &points[i][j + 1];
			if (i < y - 2)
				down = &points[i + 1][j];
			if (j == x - 1 && i != y - 1)
				down = &points[i + 1][j];
			if (i == y - 1 && j != x - 1)
				right = &points[i][j + 1];
			//printf("current - x: %f y: %f z: %f \n",
			//		current->x, current->y, current->z);
			if (right)
				draw_line(current->x * 10, current->y * 100, right->x * 100, right->y * 100, mlx, win);
			//	printf("right - x: %f y: %f z: %f \n",
			//		right->x, right->y, right->z);
			if (down)
				draw_line(current->x * 100, current->y * 100, down->x * 100, down->y * 100, mlx, win);
			//	printf("down - x: %f y: %f z: %f \n",
			//		down->x, down->y, down->z);
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
	win = mlx_new_window(mlx, 800, 1000, "draw grid");
	draw_map(points, x, y, mlx, win);
	mlx_loop(mlx);
}
