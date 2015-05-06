/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 14:38:33 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/06 16:03:48 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_rx_matrix(matrix mtx, float angle)
{
	angle = toradian(angle);
	mtx[0][0] = 1; mtx[0][1] = 0; mtx[0][2] = 0; mtx[0][3] = 0;
	mtx[1][0] = 0; mtx[1][1] = cos(angle); mtx[1][2] = sin(angle); mtx[1][3] = 0;
	mtx[2][0] = 0; mtx[2][1] = sin(angle) * -1; mtx[2][2] = cos(angle); mtx[2][3] = 0;
	mtx[3][0] = 0; mtx[3][1] = 0; mtx[3][2] = 0; mtx[3][3] = 1;
}

void create_ry_matrix(matrix mtx, float angle)
{
	angle = toradian(angle);
	mtx[0][0] = cos(angle); mtx[0][1] = 0; mtx[0][2] = sin(angle) * -1; mtx[0][3] = 0;
	mtx[1][0] = 0; mtx[1][1] = 1; mtx[1][2] = 0; mtx[1][3] = 0;
	mtx[2][0] = sin(angle); mtx[2][1] = 0; mtx[2][2] = cos(angle); mtx[2][3] = 0;
	mtx[3][0] = 0; mtx[3][1] = 0; mtx[3][2] = 0; mtx[3][3] = 1;
}

void create_rz_matrix(matrix mtx, float angle)
{
	angle = toradian(angle);
	mtx[0][0] = cos(angle); mtx[0][1] = sin(angle); mtx[0][2] = 0; mtx[0][3] = 0;
	mtx[1][0] = sin(angle) * -1; mtx[1][1] = cos(angle); mtx[1][2] = 0; mtx[1][3] = 0;
	mtx[2][0] = 0; mtx[2][1] = 0; mtx[2][2] = 1; mtx[2][3] = 0;
	mtx[3][0] = 0; mtx[3][1] = 0; mtx[3][2] = 0; mtx[3][3] = 1;
}
