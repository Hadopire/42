/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 19:42:47 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/07 17:33:24 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	print_matrix(matrix mtx)
{
	printf("M | vtcX | vtcY | vtcZ | vtxO\n-----------------------------\n");
	printf("x | %.02f | % .02f | %.02f | %.02f\n",
			mtx[0][0], mtx[0][1], mtx[0][2], mtx[0][3]);
	printf("y | %.02f | % .02f | %.02f | %.02f\n",
			mtx[1][0], mtx[1][1], mtx[1][2], mtx[1][3]);
	printf("z | %.02f | % .02f | %.02f | %.02f\n",
			mtx[2][0], mtx[2][1], mtx[2][2], mtx[2][3]);
	printf("w | %.02f | % .02f | %.02f | %.02f\n",
			mtx[3][0], mtx[3][1], mtx[3][2], mtx[3][3]);
}

void	transform_vector(t_vector *vec, matrix mtx)
{
	float x;
	float y;
	float z;

	x = vec->x;
	y = vec->y;
	z = vec->z;
	vec->x = mtx[0][0] * x + mtx[0][1] * y + mtx[0][2] * z + mtx[0][3];
	vec->y = mtx[1][0] * x + mtx[1][1] * y + mtx[1][2] * z + mtx[1][3];
	vec->z = mtx[2][0] * x + mtx[2][1] * y + mtx[2][2] * z + mtx[2][3];
}

void	transform_vertex(GLfloat *vtx, matrix mtx, int index)
{
	int		i;
	float	x;
	float	y;
	float	z;

	i = index;
	x = vtx[i];
	y = vtx[i + 1];
	z = vtx[i + 2];
	vtx[i] = mtx[0][0] * x + mtx[0][1] * y + mtx[0][2] * z + mtx[0][3];
	vtx[i + 1] = mtx[1][0] * x + mtx[1][1] * y + mtx[1][2] * z + mtx[1][3];
	vtx[i + 2] = mtx[2][0] * x + mtx[2][1] * y + mtx[2][2] * z + mtx[2][3];
}

void	transform_model(float *vtx, matrix mtx, int triangle_count)
{
	int i;

	i = 0;
	while (i < triangle_count)
	{
		transform_vertex(vtx, mtx, i);
		i+=3;
	}
}

void	multiply_matrix(matrix result, matrix mt1, matrix mt2)
{
	int i;
	int j;
	float sum;
	int	k;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			sum = 0;
			while (++k < 4)
				sum += mt1[i][k] * mt2[k][j];
			result[i][j] = sum;
		}
	}
}
