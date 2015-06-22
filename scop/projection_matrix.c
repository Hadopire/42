/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 14:08:41 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/14 20:35:18 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void create_projection_matrix(matrix mtx, t_camconfig cfg)
{
	float focal_length;

	focal_length = 1.f / tanf(toradian(cfg.fov) / 2.f);
	mtx[0][0] = focal_length / (float)cfg.ratio;
	mtx[0][1] = 0.0;
	mtx[0][2] = 0.0;
	mtx[0][3] = 0.0;
	mtx[1][0] = 0.0;
	mtx[1][1] = focal_length;
	mtx[1][2] = 0.0;
	mtx[1][3] = 0.0;
	mtx[2][0] = 0.0;
	mtx[2][1] = 0.0;
	mtx[2][2] = ((cfg.far + cfg.near) / (cfg.near - cfg.far));
	mtx[3][2] = ((2.f * cfg.far * cfg.near) / (cfg.near - cfg.far));
	mtx[3][0] = 0.0;
	mtx[3][1] = 0.0;
	mtx[2][3] = -1.f;
	mtx[3][3] = 0.0;
}
