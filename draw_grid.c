/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurawsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:30:48 by imurawsk          #+#    #+#             */
/*   Updated: 2017/02/09 22:23:32 by imurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		key_read(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

static void		draw_right(t_3d **points, t_mlxwin *mw, t_dl *dl, t_3d *c)
{
	dl->x1 = c->x;
	dl->x2 = points[dl->i][dl->j + 1].x;
	dl->y1 = c->y;
	dl->y2 = points[dl->i][dl->j + 1].y;
	dl->dx = abs(dl->x2 - dl->x1);
	dl->dy = abs(dl->y2 - dl->y1);
	draw_line(dl, mw);
}

static void		draw_down(t_3d **points, t_mlxwin *mw, t_dl *dl, t_3d *c)
{
	dl->x1 = c->x;
	dl->x2 = points[dl->i + 1][dl->j].x;
	dl->y1 = c->y;
	dl->y2 = points[dl->i + 1][dl->j].y;
	dl->dx = abs(dl->x2 - dl->x1);
	dl->dy = abs(dl->y2 - dl->y1);
	draw_line(dl, mw);
}

static void		draw_map(t_3d **points, int x, int y, t_mlxwin *mw)
{
	t_3d		*c;
	t_dl		*dl;

	dl = (t_dl *)malloc(sizeof(t_dl));
	dl->i = 0;
	dl->j = 0;
	isometric(points, x, y);
	while (dl->i < y)
	{
		dl->j = 0;
		while (dl->j < x)
		{
			c = &points[dl->i][dl->j];
			if (dl->j < x - 1 && points[dl->i][dl->j + 1].x
					&& points[dl->i][dl->j + 1].y)
				draw_right(points, mw, dl, c);
			if (dl->i < y - 1 && points[dl->i + 1][dl->j].x
					&& points[dl->i + 1][dl->j].y)
				draw_down(points, mw, dl, c);
			dl->j++;
		}
		dl->i++;
	}
	mlx_key_hook(mw->win, key_read, 0);
}

void			init_draw(t_3d **points, int x, int y)
{
	t_mlxwin *mw;

	mw = (t_mlxwin *)malloc(sizeof(t_mlxwin));
	mw->mlx = mlx_init();
	mw->win = mlx_new_window(mw->mlx, 1000, 1000, "draw grid");
	draw_map(points, x, y, mw);
	mlx_loop(mw->mlx);
}
