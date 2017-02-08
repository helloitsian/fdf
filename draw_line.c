/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurawsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 02:04:31 by imurawsk          #+#    #+#             */
/*   Updated: 2017/02/08 02:08:21 by imurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(int x1, int x2, int y1, int y2, void *mlx, void *win)
{
	int		dx;
	int		dy;
	float	sx;
	float	sy;
	float	err;
	float	e2;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	err = (dx > dy ? dx : -dy) / 2;
	sx = x1 < x2 ? 1 : -1;
	sy = y1 < y2 ? 1 : -1;
	while (1)
	{
		mlx_pixel_put(mlx, win, x1, y1, 0x00FFFFFF);
		if (x1 == x2 && y1 == y2)
			break ;
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
