/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurawsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 01:55:35 by imurawsk          #+#    #+#             */
/*   Updated: 2017/02/08 01:59:31 by imurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_3D		**create_points_array(t_3D **points, int x, int y)
{
	int i;

	i = 0;
	points = (t_3D **)malloc(sizeof(t_3D *) * y);
	while (i < y)
	{
		points[i] = (t_3D *)malloc(sizeof(t_3D) * x);
		i++;
	}
	return (points);
}

static int		words(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i + 1] != '\0')
			i++;
		i++;
	}
	return (count);
}

static void		make_point_array(char **data, int x, int y)
{
	t_3D		**points;
	int			i;
	int			j;
	int			t_x;

	points = create_points_array(points, x, y);
	i = 0;
	j = 0;
	t_x = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			points[i][j].x = j;
			points[i][j].y = i;
			points[i][j].z = (float)atoi(data[t_x]);
			t_x++;
			j++;
		}
		i++;
	}
	init_draw(points, x, y);
}

int				main(int argc, char **argv)
{
	char		*line;
	char		*contents;
	char		**data;
	char		*temp;
	int			ret;
	int			fd;
	int			x;
	int			y;

	x = -1;
	y = 0;
	fd = open(argv[1], O_RDONLY);
	contents = ft_strnew(0);
	while ((ret = get_next_line(fd, &line)))
	{
		temp = contents;
		contents = ft_strjoin(contents, line);
		contents = ft_strjoin(contents, " ");
		if (x == -1)
			x = words(line, ' ');
		free(temp);
		y++;
	}
	data = ft_strsplit(contents, ' ');
	make_point_array(data, x, y);
}
