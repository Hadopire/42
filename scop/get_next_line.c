/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 13:00:11 by zcarde            #+#    #+#             */
/*   Updated: 2014/12/05 03:00:03 by mel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int		read_next_line(char **n_ret, int fd)
{
	char		*buf;
	int			nb_read;
	char		*temp;

	buf = ft_strnew(BUFF_SIZE);
	nb_read = BUFF_SIZE;
	while (ft_strchr(*n_ret, '\n') == NULL && nb_read == BUFF_SIZE)
	{
		if ((nb_read = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[nb_read] = '\0';
		temp = ft_strjoin(*n_ret, buf);
		free(*n_ret);
		*n_ret = ft_strdup(temp);
		free(temp);
	}
	free(buf);
	return (nb_read);
}

int		get_next_line(int fd, char **line)
{
	static char *n_ret[256];
	int			nb_read;
	char		*temp;

	if (!n_ret[fd])
		n_ret[fd] = ft_strnew(0);
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if ((nb_read = read_next_line(&n_ret[fd], fd)) == -1)
		return (-1);
	if (nb_read < BUFF_SIZE && ft_strchr(n_ret[fd], '\n') == NULL)
	{
		*line = ft_strdup(n_ret[fd]);
		ft_bzero(n_ret[fd], ft_strlen(n_ret[fd]));
		return (0);
	}
	*line = ft_strsub(n_ret[fd], 0, (size_t)(ft_strchr(n_ret[fd], '\n')
	- n_ret[fd]));
	temp = ft_strdup(ft_strchr(n_ret[fd], '\n') + 1);
	free(n_ret[fd]);
	n_ret[fd] = ft_strdup(temp);
	free(temp);
	return (1);
}
