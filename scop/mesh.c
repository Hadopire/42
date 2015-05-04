/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 17:29:10 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/04 18:04:49 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	draw_mesh(t_mesh mesh)
{
	//colors
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * mesh.triangle_count * 9, mesh.colors, GL_STATIC_DRAW);
	glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,(void*)0);
	//position
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * mesh.triangle_count * 9, mesh.vtx, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	//draw
	glDrawArrays(GL_TRIANGLES, 0, 3 * mesh.triangle_count);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}
