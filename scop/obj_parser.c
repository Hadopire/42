/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 17:28:36 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/14 17:29:10 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		get_coord_index(char **file, int *vstart, int *vlen)
{
	int	i;

	i = 0;
	while (file[i] && ft_strncmp(file[i], "v ", 2) != 0)
		i++;
	*vstart = i;
	while (file[i] && ft_strncmp(file[i], "v ", 2) == 0)
		i++;
	*vlen = i - *vstart;
}

void		get_vertex_index(char **file, int *vstart, int *vlen, int i)
{
	while (file[i] && ft_strncmp(file[i], "f ", 2) != 0)
		i++;
	*vstart = i;
	while (file[i] && ft_strncmp(file[i], "f ", 2) == 0)
		i++;
	*vlen = i - *vstart;
}

int			count_obj_vertex(int vstart, int vlen, char **file)
{
	int i;
	int	count;
	int a;
	int	linecount;

	i = vstart - 1;
	count = 0;
	while (++i < vlen + vstart)
	{
		a = 2;
		linecount = 0;
		while (file[i][a])
		{
			while (ft_isdigit(file[i][a]))
				a++;
			if (a == 2 || (file[i][a] != ' ' && file[i][a] != '\0'))
				error("Wrong file format");
			a = file[i][a] ? a + 1 : a;
			linecount++;
		}
		if (linecount != 3 && linecount != 4)
			error("Wrong file format");
		count += linecount == 4 ? 6 : 3;
	}
	return (count);
}

int			count_line_index(char **file, int line)
{
	int a;
	int	linecount;

	linecount = 0;
	a = 2;
	while (file[line][a])
	{
		while (ft_isdigit(file[line][a]))
			a++;
		a++;
		linecount++;
	}
	return (linecount);
}

void		get_index(char **file, int *numb, int i, int linecount)
{
	int a;
	int	e;

	e = 0;
	a = 2;
	while (file[i][a])
	{
		numb[e] = atoi(file[i] + a);
		while (ft_isdigit(file[i][a]))
			a++;
		e++;
		a++;
	}
}
