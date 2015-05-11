/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 15:44:18 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/11 17:54:04 by ncharret         ###   ########.fr       */
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
			if (a == 2)
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

t_mesh	parse_obj(char **file)
{
	t_mesh	mesh;
	int		cstart;
	int		clen;
	int		vstart;
	int		vlen;

	get_coord_index(file, &cstart, &clen);
	get_vertex_index(file, &vstart, &vlen, cstart + clen);
	if (clen == 0 || vlen == 0)
		error("Wrong file format");
	mesh.vertex_count = count_obj_vertex(vstart, vlen, file);
	mesh.vtx = malloc(sizeof(GLuint) * mesh.vertex_count);
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
