/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurawsk <imurawsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 12:48:06 by imurawsk          #+#    #+#             */
/*   Updated: 2016/11/10 10:59:15 by imurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*list_func(t_list **file, int fd)
{
	t_list		*temp;

	temp = *file;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", 1);
	temp->content_size = fd;
	ft_lstadd(file, temp);
	return (temp);
}

int				index_to_nl(char *str)
{
	int			i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static char		*add_to(char *tmp, char *buf, size_t ret)
{
	char	*str;
	size_t	i;

	str = ft_strnew(ft_strlen(tmp) + ++ret);
	i = 0;
	while (*tmp)
		str[i++] = *tmp++;
	while (*buf && --ret > 0)
		str[i++] = *buf++;
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	int					ret;
	char				buf[BUFF_SIZE + 1];
	char				*copy;
	t_list				*t;
	static	t_list		*file;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	t = file;
	file = list_func(&t, fd);
	while (!ft_strchr(file->content, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
	{
		copy = file->content;
		file->content = add_to(file->content, buf, ret);
		free(copy);
	}
	ret = index_to_nl((char *)file->content);
	*line = ft_strncpy(ft_strnew(ret), file->content, ret);
	if (((char *)file->content)[ret] == '\n')
		ret++;
	copy = file->content;
	file->content = ft_strdup(file->content + ret);
	free(copy);
	file = t;
	return (ret ? 1 : 0);
}
