/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurawsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 01:55:35 by imurawsk          #+#    #+#             */
/*   Updated: 2017/02/16 17:01:23 by imurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_3d		**create_points_array(t_3d **points, int x, int y)
{
	int i;

	i = 0;
	points = (t_3d **)malloc(sizeof(t_3d *) * y);
	while (i < y)
	{
		points[i] = (t_3d *)malloc(sizeof(t_3d) * x);
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
	t_3d		**points;
	int			i;
	int			j;
	int			t_x;

	points = NULL;
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
	t_parse		p;
	char		**data;

	if (argc != 2)
		exit(0);
	p.x = -1;
	p.y = 0;
	if ((p.fd = open(argv[1], O_RDONLY)) <= 0)
		return (0);
	p.contents = ft_strnew(0);
	while ((p.ret = get_next_line(p.fd, &p.line)))
	{
		p.temp = p.contents;
		p.contents = ft_strjoin(p.contents, p.line);
		free(p.temp);
		p.temp = p.contents;
		p.contents = ft_strjoin(p.contents, " ");
		if (p.x == -1)
			p.x = words(p.line, ' ');
		free(p.temp);
		p.y++;
	}
	data = ft_strsplit(p.contents, ' ');
	make_point_array(data, p.x, p.y);
	return (0);
}
