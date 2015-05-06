/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookat_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:22:44 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/06 16:44:47 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void create_lookat_matrix(matrix mtx, t_vector eye, t_vector target, t_vector up)
{
	t_vector zaxis;
	t_vector xaxis;
	t_vector yaxis;
		
	zaxis = norm_vector(sub_vector(eye, target));
	xaxis = norm_vector(cross_product(up, zaxis));
	yaxis = cross_product(xaxis, zaxis);
	mtx[0][0] = xaxis.x;
	mtx[0][1] = xaxis.y;
	mtx[0][2] = xaxis.z;
	mtx[0][3] = -dot_product(xaxis, eye);
	mtx[1][0] = yaxis.x;
	mtx[1][1] = yaxis.y;
	mtx[1][2] = yaxis.z;
	mtx[1][3] = -dot_product(yaxis, eye);
	mtx[2][0] = zaxis.x;
	mtx[2][1] = zaxis.y;
	mtx[2][2] = zaxis.z;
	mtx[2][3] = -dot_product(zaxis, eye);
	mtx[3][0] = 0;
	mtx[3][1] = 0;
	mtx[3][2] = 0;
	mtx[3][3] = 1;	
}
