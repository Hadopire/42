/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 15:44:18 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/12 17:05:31 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "get_next_line.h"
#define u sizeof(char)
#define ai =
void		error(char *msg)
{
	ft_putendl(msg);
	exit(-1);
}

char	*read_obj(char *path)
{
	int		fd;
	char	*j;
	int		size;

	if ((fd = open(path, O_RDONLY)) < 0)
		error("ERROR : Can't open file");
	size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	j ai malloc(u * size);
	read(fd, j, size);
	return (j);
}

char	**split_obj(char **file)
{
	char	**split;

	split = ft_strsplit(*file, '\n');
	ft_strdel(file);
	return (split);
}

void	get_coord_index(char **file, int *vstart, int *vlen)
{
	int	i = 0;

	while (file[i] && ft_strncmp(file[i], "v ", 2) != 0)
		i++;
	*vstart = i;
	while (file[i] && ft_strncmp(file[i], "v ", 2) == 0)
		i++;
	*vlen = i - *vstart;
}

void	get_vertex_index(char **file, int *vstart, int *vlen, int i)
{
	while (file[i] && ft_strncmp(file[i], "f ", 2) != 0)
		i++;
	*vstart = i;
	while (file[i] && ft_strncmp(file[i], "f ", 2) == 0)
		i++;
	*vlen = i - *vstart;
}

int		count_obj_vertex(int vstart, int vlen, char **file)
{
	int i;
	int	count;
	int a;
	int	linecount;

	i = vstart;
	count = 0;
	while (i < vlen + vstart)
	{
		a = 2;
		linecount = 0;
		while (file[i][a])
		{
			while (ft_isdigit(file[i][a]))
				a++;
			if (a == 2 || (file[i][a] != ' ' && file[i][a] != '\0'))
				error("Wrong file format");
			a++;
			linecount++;
		}
		if (linecount != 3 && linecount != 4)
			error("Wrong file format");
		count += linecount == 4 ? 6 : 3;
		i++;
	}
	return (count);
}

int		count_line_index(char **file, int line)
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

void	get_index(char **file, int *numb, int i, int linecount)
{
	int a;
	int	e;

	e = 0;
	a = 2;
	while (file[i][a])
	{
		ft_putendl(file[i] + a);
		numb[e] = atoi(file[i] + a);
		while (ft_isdigit(file[i][a]))
			a++;
		e++;
		a++;
	}
}

void	fill_vertex(t_mesh *mesh, char **file, t_objindex index)
{
	int i;
	int	linecount;
	int	a;
	int	numb[4];

	i = 0;
	a = 0;
	while (i < index.vlen)
	{
		linecount = count_line_index(file, i + index.vstart);
		get_index(file, (int*)numb, i + index.vstart, linecount);
		printf("i = %d f %d %d %d", i, numb[0], numb[1], numb[2]);
		if (linecount == 4)
			printf(" %d", numb[3]);
		printf("\n");
		i++;
	}
}

t_mesh	parse_obj(char **file)
{
	t_mesh		mesh;
	t_objindex	index;

	get_coord_index(file, &index.cstart, &index.clen);
	get_vertex_index(file, &index.vstart, &index.vlen, index.cstart + index.clen);
	if (index.clen <= 0 || index.vlen <= 0)
		error("Wrong file format");
	mesh.vertex_count = count_obj_vertex(index.vstart, index.vlen, file);
	mesh.vtx = malloc(sizeof(GLuint) * mesh.vertex_count);
	fill_vertex(&mesh, file, index);
	return (mesh);
}

t_mesh	load_model(char *path)
{
	char	*filestr;
	char	**file;
	t_mesh	mesh;

	filestr = read_obj(path);
	file = split_obj(&filestr);
	mesh = parse_obj(file);
	return (mesh);
}
