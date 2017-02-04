/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurawsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:16:01 by imurawsk          #+#    #+#             */
/*   Updated: 2017/02/02 18:12:55 by imurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

static void		rotate_z(t_3D *point, float angle)
{
	float temp;

	temp = point->x;
	point->x = (point->x * cos(angle)) - (point->y * sin(angle));
	point->y = (temp * sin(angle)) + (point->y * cos(angle));
}

static void		rotate_x(t_3D *point, float angle)
{
	float temp;

	temp = point->y;
	point->y = (point->y * cos(angle)) - (point->z * sin(angle));
	point->z = (temp * sin(angle)) + (point->z * cos(angle));
}

void	rotate_point(t_3D *point)
{
	//90 degree rotation
	//rotate_z(point, M_PI / 2);
	
	//Isometric Rotation
	rotate_z(point, 45 * (M_PI/180));
	rotate_x(point, 60 * (M_PI/180));
}
/*
int main()
{
	t_3D *sample;

	sample = (t_3D *)malloc(sizeof(t_3D));
	sample->x = 1;
	sample->y = 2;
	sample->z = 1;
	rotate_point(sample);
	printf("x: %f y: %f z: %f", sample->x, sample->y, sample->z);
}
*/
