/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 17:29:10 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/05 18:02:20 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	get_rotation_matrix(matrix result, float x, float y, float z)
{
	matrix mt1;
	matrix mt2;
	matrix mt3;

	//create_rx_matrix(result, x);
	create_rx_matrix(mt1, x);
	create_ry_matrix(mt2, y);
	multiply_matrix(mt3, mt1, mt2);
	create_rz_matrix(mt1, z);
	multiply_matrix(result, mt3, mt1);
}
void	draw_mesh(t_mesh mesh)
{
	matrix mtx;
	matrix mt1;
	matrix mt2;
	t_camconfig cfg;

	cfg.near = 0.1;
	cfg.far = 100.f;
	cfg.fov = 90.f;
	cfg.ratio = 800.f/600.f;
	GLuint vtx[mesh.triangle_count * 9];
	ft_memcpy(vtx, mesh.vtx, sizeof(GLfloat) * (mesh.triangle_count * 9));
	//scale & position & rotation	
	create_scale_matrix(mt1, mesh.scale);
	get_rotation_matrix(mt2, mesh.angle.x, mesh.angle.y, mesh.angle.z);
	multiply_matrix(mtx, mt1, mt2);
	create_translation_matrix(mesh.world_position, mt1);
	multiply_matrix(mt2, mt1, mtx);
	create_projection_matrix(mt1, cfg);
	multiply_matrix(mtx, mt1, mt2);
	transform_model((float*)vtx, mtx, mesh.triangle_count);
	printf("babadouk babadouk\n");
	print_model((float*)vtx, mesh.triangle_count);
	//colors
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * mesh.triangle_count * 9, mesh.colors, GL_STATIC_DRAW);
	glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,(void*)0);
	//position
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * mesh.triangle_count * 9, vtx, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	//draw
	glDrawArrays(GL_TRIANGLES, 0, 3 * mesh.triangle_count);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}
