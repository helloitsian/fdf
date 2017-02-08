/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurawsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:16:01 by imurawsk          #+#    #+#             */
/*   Updated: 2017/02/08 02:22:57 by imurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		rotate_z(t_3D *point, float angle)
{
	float temp;

	temp = point->x;
	point->x = (point->x * cos(angle)) + (point->y * sin(angle));
	point->y = (temp * -sin(angle)) + (point->y * cos(angle));
}

static void		rotate_x(t_3D *point, float angle)
{
	float temp;

	temp = point->y;
	point->y = (point->y * cos(angle)) + (point->z * sin(angle));
	point->z = (temp * -sin(angle)) + (point->z * cos(angle));
}

static void		rotate_point(t_3D *point, float angle, char axis)
{
	if (axis == 'x')
		rotate_x(point, angle);
	else if (axis == 'z')
		rotate_z(point, angle);
}

void			isometric(t_3D **points, int x, int y)
{
	int i;
	int j;
	int scale;

	i = 0;
	j = 0;
	scale = x > y ? (500 / (x - 1)) : (500 / (y - 1));
	while(i < y)
	{
		j = 0;
		while (j < x)
		{
			points[i][j].x *= scale;
			points[i][j].y *= scale;
			points[i][j].z *= scale;
			points[i][j].x -= (scale / 2.0) * (x - 1);
			points[i][j].y -= (scale / 2.0) * (y - 1);
			rotate_point(&points[i][j], 45 * (M_PI / 180), 'z');
			rotate_point(&points[i][j], atan(-sqrt(2)), 'x');
			points[i][j].x += 500;
			points[i][j].y += 500;
			j++;
		}
		i++;
	}
}
