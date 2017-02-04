#include "fdf.h"

void  draw_line(float x1, float x2, float y1, float y2, void *mlx, void *win)
{
	double dx;
	double dy;
	double sx;
	double sy;
	int err;
	int e2;
	int b = 0;

	dx = fabs(x2 - x1);
	dy = fabs(y2 - y1);
	err = 0;
	if (x1 < x2)
		sx = 1;
	else
		sx = -1;
	if (y1 < y2)
		sy = 1;
	else
		sy = -1;
	while (1 == 1)
	{
		mlx_pixel_put(mlx, win, x1, y1, 0x00FFFFFF);
		if (x1 == x2 && y1 == y2)
			break;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y1 += sy;
		}
	}
}
