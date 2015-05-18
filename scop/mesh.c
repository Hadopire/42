/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 17:29:10 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/18 15:55:02 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	bind_matrices(t_mvp mvp, t_mesh mesh)
{
	t_camconfig	cfg;
	matrix		mtx;
	matrix		mt2;
	matrix		mt1;

	cfg.near = 0.1;
	cfg.far = 100.f;
	cfg.fov = 60.f;
	cfg.ratio = 1366.f / 768.f;
	create_scale_matrix(mt1, mesh.scale);
	create_translation_matrix(mesh.world_position, mtx);
	glUniformMatrix4fv(mvp.modelmtx[0], 1, GL_FALSE, &mt1[0][0]);
	glUniformMatrix4fv(mvp.modelmtx[1], 1, GL_FALSE, &mtx[0][0]);
	create_projection_matrix(mt1, cfg);
	glUniformMatrix4fv(mvp.projmtx, 1, GL_FALSE, &mt1[0][0]);
	create_lookat_matrix(mtx, init_vector(0, 0, 10),
			init_vector(0, 0, 0), init_vector(0, 1, 0));
	glUniformMatrix4fv(mvp.viewmtx, 1, GL_FALSE, &mtx[0][0]);
	glEnableVertexAttribArray(1);
}

void	bindbuffers(t_mesh mesh, int programid_index)
{
	if (programid_index == 0)
	{
		glBindBuffer(GL_ARRAY_BUFFER, mesh.colorbuffer);
		glBufferData(GL_ARRAY_BUFFER, mesh.vertex_count * sizeof(GLfloat),
				mesh.colors, GL_STATIC_DRAW);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	}
	else
	{
		glBindBuffer(GL_ARRAY_BUFFER, mesh.uvbuffer);
		glBufferData(GL_ARRAY_BUFFER, (mesh.vertex_count * (2.f / 3.f) + 1) * sizeof(GLfloat),
				mesh.uv, GL_STATIC_DRAW);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
	}

}

void	draw_mesh(t_mesh mesh, t_mvp mvp, int programid_index)
{
	bind_matrices(mvp, mesh);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(0);
	bindbuffers(mesh, programid_index);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, mesh.vertex_count * sizeof(GLfloat),
			mesh.vtx, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glDrawArrays(GL_TRIANGLES, 0, mesh.vertex_count);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}
