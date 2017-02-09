/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurawsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:22:19 by imurawsk          #+#    #+#             */
/*   Updated: 2017/02/08 20:22:45 by imurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <math.h>

# include <stdio.h>

typedef struct		s_parse
{
	char			*temp;
	char			*line;
	char			*contents;
	int				fd;
	int				ret;
	int				x;
	int				y;
}					t_parse;

typedef struct		s_dl
{
	int				i;
	int				j;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				dx;
	int				dy;
	float			sx;
	float			sy;
	float			err;
	float			e2;
}					t_dl;

typedef struct		s_mlxwin
{
	void			*mlx;
	void			*win;
}					t_mlxwin;

typedef struct		s_3d
{
	float			x;
	float			y;
	float			z;
}					t_3d;

void				isometric(t_3d **points, int x, int y);
void				draw_line(t_dl *dl, t_mlxwin *mw);
void				init_draw(t_3d **points, int x, int y);

#endif
