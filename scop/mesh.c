/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 17:29:10 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/06 16:11:10 by ncharret         ###   ########.fr       */
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
void	draw_mesh(t_mesh mesh, GLuint *ModelMatrices, GLuint ProjectionMatrix)
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
	create_translation_matrix(mesh.world_position, mtx);
	glUniformMatrix4fv(ModelMatrices[0], 1, GL_FALSE, &mt1[0][0]);
	glUniformMatrix4fv(ModelMatrices[1], 1, GL_FALSE, &mt2[0][0]);
	glUniformMatrix4fv(ModelMatrices[2], 1, GL_FALSE, &mtx[0][0]);
	create_projection_matrix(mtx, cfg);
	glUniformMatrix4fv(ProjectionMatrix, 1, GL_FALSE, &mtx[0][0]);
	printf("--------PROJ MATRIX----------\n");
	print_matrix(mtx);
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
