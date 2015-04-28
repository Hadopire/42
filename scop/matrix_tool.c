/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 19:42:47 by ncharret          #+#    #+#             */
/*   Updated: 2015/04/28 20:59:59 by ncharret         ###   ########.fr       */
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

void	transform_triangle(GLfloat *vtx, matrix mtx)
{
	int		i;
	float	x;
	float	y;
	float	z;

	i = 0;
	while (i < 9)
	{
		x = vtx[i];
		y = vtx[i + 1];
		z = vtx[i + 2];
		vtx[i] = mtx[0][0] * x + mtx[0][1] * y + mtx[0][2] * z;
		vtx[i + 1] = mtx[1][0] * x + mtx[1][1] * y + mtx[1][2] * z;
		vtx[i + 2] = mtx[2][0] * x + mtx[2][1] * y + mtx[2][2] * z;
		i += 3;
	}
}
