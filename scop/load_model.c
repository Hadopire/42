/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 15:44:18 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/14 20:46:12 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "get_next_line.h"
#include <time.h>

void		get_vtx(char *line, t_mesh *mesh, int *vtxindex)
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

void		fill_vertex(t_mesh *mesh, char **file, t_objindex index)
{
	int		i;
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

t_mesh		parse_obj(char **file)
{
	t_mesh		mesh;
	t_objindex	idx;

	get_coord_index(file, &idx.cstart, &idx.clen);
	get_vertex_index(file, &idx.vstart, &idx.vlen, idx.cstart + idx.clen);
	if (idx.clen <= 0 || idx.vlen <= 0)
		error("Wrong file format");
	mesh.vertex_count = count_obj_vertex(idx.vstart, idx.vlen, file) * 3;
	if (!(mesh.vtx = malloc(sizeof(GLfloat) * mesh.vertex_count)))
		error("Error : malloc error");
	if (!(mesh.colors = malloc(sizeof(GLfloat) * mesh.vertex_count)))
		error("Error : malloc error");
	printf("Number of vertex : %d\n", mesh.vertex_count / 3);
	fill_vertex(&mesh, file, idx);
	return (mesh);
}

void		fill_colors(t_mesh *mesh)
{
	int		i;
	GLfloat	color;

	i = 0;
	srand(time(NULL));
	while (i < mesh->vertex_count)
	{
		if (i <= 9 || (mesh->vtx[i - 9] != mesh->vtx[i] ||
			mesh->vtx[i - 8] != mesh->vtx[i + 1] || mesh->vtx[i - 7] !=
			mesh->vtx[i + 2] || mesh->vtx[i - 3] != mesh->vtx[i + 3]
			|| mesh->vtx[i - 2] != mesh->vtx[i + 4] || mesh->vtx[i - 1]
			!= mesh->vtx[i + 5]))
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

t_mesh		load_model(char *path)
{
	char	*filestr;
	char	**file;
	t_mesh	mesh;

	filestr = read_obj(path);
	file = split_obj(&filestr);
	mesh = parse_obj(file);
	fill_colors(&mesh);
	mesh.world_position = init_vector(0, 0, 0);
	mesh.angle = init_vector(0, 0, 0);
	mesh.scale = 1;
	glGenBuffers(1, &mesh.vertexbuffer);
	glGenBuffers(1, &mesh.colorbuffer);
	int i = 0;
	while (i < mesh.vertex_count)
	{
		printf("x : %g y : %g z : %g\n", mesh.vtx[i], mesh.vtx[i + 1], mesh.vtx[i + 2]);
		i+=3;
	}
	return (mesh);
}
