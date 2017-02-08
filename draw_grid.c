/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurawsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:30:48 by imurawsk          #+#    #+#             */
/*   Updated: 2017/02/08 02:21:38 by imurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>

static void		draw_map(t_3D **points, int x, int y, void *mlx, void *win)
{
	t_3D *c;
	int i;
	int j;

	i = 0;
	j = 0;
	isometric(points, x, y);
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			c = &points[i][j];
			if (j < x - 1 && points[i][j + 1].x && points[i][j + 1].y)
				draw_line(c->x, points[i][j + 1].x, 
				c->y, points[i][j + 1].y, mlx, win);
			if (i < y - 1 && points[i + 1][j].x && points[i + 1][j].y)
				draw_line(c->x, points[i + 1][j].x, 
				c->y, points[i + 1][j].y, mlx, win);
			j++;
		}
		i++;
	}
}

void		init_draw(t_3D **points, int x, int y)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "draw grid");
	draw_map(points, x, y, mlx, win);
	mlx_loop(mlx);
}
