/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 15:44:18 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/27 15:44:38 by ncharret         ###   ########.fr       */
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
			error("Error : Wrong file format (.obj needed)");
		while (line[i] == ' ')
			i++;
		nb_coord++;
	}
	if (nb_coord != 3)
		error("Error : Wrong file format (.obj needed)");
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
		error("Error : wrong file format (.obj needed)");
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

void		generate_uv(t_mesh *mesh)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	mesh->uv = (GLfloat*)malloc(sizeof(GLfloat) * (mesh->vertex_count * (2.f / 3.f) + 1));
	while (i < mesh->vertex_count)
	{
		mesh->uv[a] = mesh->vtx[i] + mesh->vtx[i + 2];
		mesh->uv[a + 1] = mesh->vtx[i] + mesh->vtx[i + 1];
		i += 3;
		a += 2;
	}
}

float		compute_average(GLfloat *vtx, int size, int i)
{
	int		a;
	float	average;

	a = 0;
	average = 0;
	while (a < size)
	{
		average += vtx[a + i];
		a += 3;
	}
	return (average / (float)size);
}

void		center_mesh(t_mesh *mesh)
{
	matrix	mtx;
	float	averagex;
	float	averagey;
	float	averagez;

	averagex = compute_average(mesh->vtx, mesh->vertex_count / 3, 0);
	averagey = compute_average(mesh->vtx, mesh->vertex_count / 3, 1);
	averagez = compute_average(mesh->vtx, mesh->vertex_count / 3, 2);
	create_translation_matrix(init_vector(-averagex, -averagey, -averagez), mtx);
	transform_model(mesh->vtx, mtx, mesh->vertex_count);
}

static void	fill_normals(t_mesh *mesh)
{
	int			i;
	t_vector	v1;
	t_vector	v2;
	t_vector	v3;

	mesh->normals = malloc(sizeof(GLfloat) * mesh->vertex_count);
	i = 0;
	while (i < mesh->vertex_count)
	{
		v1 = init_vector(mesh->vtx[i], mesh->vtx[i + 1], mesh->vtx[i + 2]);
		v2 = init_vector(mesh->vtx[i + 3], mesh->vtx[i + 4], mesh->vtx[i + 5]);
		v3 = init_vector(mesh->vtx[i + 6], mesh->vtx[i + 7], mesh->vtx[i + 8]);
		v1 = norm_vector(cross_product(sub_vector(v1, v2), sub_vector(v1, v3)));
		mesh->normals[i] = v1.x;
		mesh->normals[i + 1] = v1.y;
		mesh->normals[i + 2] = v1.z;
		mesh->normals[i + 3] = v1.x;
		mesh->normals[i + 4] = v1.y;
		mesh->normals[i + 5] = v1.z;
		mesh->normals[i + 6] = v1.x;
		mesh->normals[i + 7] = v1.y;
		mesh->normals[i + 8] = v1.z;
		i += 9;
	//	printf("X : %g, Y : %g, Z : %g\n", v1.x, v1.y, v1.z);
	}
}

t_mesh		load_model(char *path, char *imgpath)
{
	char	*filestr;
	char	**file;
	t_mesh	mesh;

	filestr = read_obj(path);
	file = split_obj(&filestr);
	mesh = parse_obj(file);
	fill_colors(&mesh);
	fill_normals(&mesh);
	center_mesh(&mesh);
	mesh.world_position = init_vector(0, 0, 0);
	mesh.angle = init_vector(0, 0, 0);
	mesh.scale = 1;
	glGenBuffers(1, &mesh.vertexbuffer);
	glGenBuffers(1, &mesh.colorbuffer);
	glGenBuffers(1, &mesh.uvbuffer);
	glGenBuffers(1, &mesh.nmbuffer);
	if (imgpath)
		mesh.texture = load_bmp(imgpath);
	else
		mesh.texture.data = NULL;
	if (mesh.texture.data)
		generate_uv(&mesh);
	return (mesh);
}
