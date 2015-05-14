/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 17:31:22 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/14 18:18:23 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		error(char *msg)
{
	ft_putendl(msg);
	exit(-1);
}

char		*read_obj(char *path)
{
	int		fd;
	char	*j;
	int		size;

	if ((fd = open(path, O_RDONLY)) < 0)
		error("ERROR : Can't open file");
	size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	j = malloc(sizeof(char) * size);
	read(fd, j, size);
	return (j);
}

char		**split_obj(char **file)
{
	char	**split;

	split = ft_strsplit(*file, '\n');
	ft_strdel(file);
	return (split);
}

double		dot_product(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
