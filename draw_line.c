/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurawsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 02:04:31 by imurawsk          #+#    #+#             */
/*   Updated: 2017/02/08 16:01:04 by imurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_dl *dl, t_mlxwin *mw)
{
	dl->err = (dl->dx > dl->dy ? dl->dx : -dl->dy) / 2;
	dl->sx = dl->x1 < dl->x2 ? 1 : -1;
	dl->sy = dl->y1 < dl->y2 ? 1 : -1;
	while (1)
	{
		mlx_pixel_put(mw->mlx, mw->win, dl->x1, dl->y1, 0x00FFFFFF);
		if (dl->x1 == dl->x2 && dl->y1 == dl->y2)
			break ;
		dl->e2 = dl->err;
		if (dl->e2 > -dl->dx)
		{
			dl->err -= dl->dy;
			dl->x1 += dl->sx;
		}
		if (dl->e2 < dl->dy)
		{
			dl->err += dl->dx;
			dl->y1 += dl->sy;
		}
	}
}
