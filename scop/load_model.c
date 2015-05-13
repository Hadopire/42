/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 15:44:18 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/13 17:53:07 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "get_next_line.h"
#include <time.h>
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

	printf("split1\n");
	split = ft_strsplit(*file, '\n');
	printf("split2\n");
	printf("%s", split[0]);
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
		numb[e] = atoi(file[i] + a);
		while (ft_isdigit(file[i][a]))
			a++;
		e++;
		a++;
	}
}

void	get_vtx(char *line, t_mesh *mesh, int *vtxindex)
{
	int	i;
	int	nb_coord;

	nb_coord = 0;
	i = 0;
	while (line[i])
	{
		mesh->vtx[*vtxindex] = atof(line + i);
		*vtxindex += 1;
		if (line[i] == '-' || line[i] == '+')
			i++;
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] == '.')
			i++;
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] != ' ' && line[i] != '\0')
			error("Error : Wrong file format");
		while (line[i] == ' ')
			i++;
		nb_coord++;
	}
	if (nb_coord != 3)
		error("Error : Wrong file format");
}

void	fill_vertex(t_mesh *mesh, char **file, t_objindex index)
{
	int 	i;
	int		linecount;
	int		a;
	int		numb[4];
	float	vtx[3];

	i = 0;
	a = 0;
	while (i < index.vlen)
	{
		linecount = count_line_index(file, i + index.vstart);
		get_index(file, (int*)numb, i + index.vstart, linecount);
		get_vtx(file[numb[0] + index.cstart - 1] + 2, mesh, &a);
		get_vtx(file[numb[1] + index.cstart - 1] + 2, mesh, &a);
		get_vtx(file[numb[2] + index.cstart - 1] + 2, mesh, &a);
		if (linecount == 4)
		{
			get_vtx(file[numb[0] + index.cstart - 1] + 2, mesh, &a);
			get_vtx(file[numb[2] + index.cstart - 1] + 2, mesh, &a);
			get_vtx(file[numb[3] + index.cstart - 1] + 2, mesh, &a);
		}
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
	mesh.vertex_count = count_obj_vertex(index.vstart, index.vlen, file) * 3;
	if (!(mesh.vtx = malloc(sizeof(GLfloat) * mesh.vertex_count)))
		error("Error : malloc error");
	if (!(mesh.colors = malloc(sizeof(GLfloat) * mesh.vertex_count)))
		error("Error : malloc error");
	printf("Number of vertex : %d\n", mesh.vertex_count / 3);
	fill_vertex(&mesh, file, index);
	return (mesh);
}

void	fill_colors(t_mesh *mesh)
{
	int		i;
	GLfloat	color;

	i = 0;
	srand(time(NULL));
	while (i < mesh->vertex_count)
	{
		if (mesh->vtx[i - 9] != mesh->vtx[i] || mesh->vtx[i - 8] != mesh->vtx[i + 1]
		|| mesh->vtx[i - 7] != mesh->vtx[i + 2] || mesh->vtx[i - 3] != mesh->vtx[i + 3]
		|| mesh->vtx[i - 2] != mesh->vtx[i + 4] || mesh->vtx[i - 1] != mesh->vtx[i + 5])
			color = (float)(rand() % 50) / 100 + 0.2;
		mesh->colors[i] = color;
		mesh->colors[i + 1] = color;
		mesh->colors[i + 2] = color;
		mesh->colors[i + 3] = color;
		mesh->colors[i + 4] = color;
		mesh->colors[i + 5] = color;
		mesh->colors[i + 6] = color;
		mesh->colors[i + 7] = color;
		mesh->colors[i + 8] = color;
		i += 9;
	}
}

t_mesh	load_model(char *path)
{
	char	*filestr;
	char	**file;
	t_mesh	mesh;

	printf("lalal\n");
	filestr = read_obj(path);
	printf("lala\n");
	file = split_obj(&filestr);
	printf("lala\n");
	mesh = parse_obj(file);
	fill_colors(&mesh);
	return (mesh);
}
