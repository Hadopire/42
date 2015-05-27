/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 18:31:44 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/27 16:58:57 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	key_rotate(const Uint8 *state, t_mesh *mesh)
{
	matrix	mtx;

	if (state[SDL_SCANCODE_UP])
	{
		create_rx_matrix(mtx, 2);
		transform_model(mesh->vtx, mtx, mesh->vertex_count);
		transform_model(mesh->normals, mtx, mesh->vertex_count);
	}
	if (state[SDL_SCANCODE_DOWN])
	{
		create_rx_matrix(mtx, -2);
		transform_model(mesh->vtx, mtx, mesh->vertex_count);
		transform_model(mesh->normals, mtx, mesh->vertex_count);
	}
	if (state[SDL_SCANCODE_RIGHT])
	{
		create_ry_matrix(mtx, 2);
		transform_model(mesh->vtx, mtx, mesh->vertex_count);
		transform_model(mesh->normals, mtx, mesh->vertex_count);
	}
	if (state[SDL_SCANCODE_LEFT])
	{
		create_ry_matrix(mtx, -2);
		transform_model(mesh->vtx, mtx, mesh->vertex_count);
		transform_model(mesh->normals, mtx, mesh->vertex_count);
	}
}

void	key_input(t_mesh *mesh)
{
	const Uint8	*state;

	state = SDL_GetKeyboardState(NULL);
	key_rotate(state, mesh);
	if (state[SDL_SCANCODE_KP_MINUS])
		mesh->scale = mesh->scale/ 1.2  < 0.1 ? mesh->scale : mesh->scale / 1.2;
	if (state[SDL_SCANCODE_KP_PLUS])
		mesh->scale *=1.2;
	if (state[SDL_SCANCODE_D])
		mesh->world_position.x += 0.08;
	if (state[SDL_SCANCODE_A])
		mesh->world_position.x -= 0.08;
	if (state[SDL_SCANCODE_W])
		mesh->world_position.y += 0.08;
	if (state[SDL_SCANCODE_S])
		mesh->world_position.y -= 0.08;
}
