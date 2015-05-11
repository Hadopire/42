/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 16:27:38 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/11 16:16:25 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

double		toradian(double angle)
{
	return (((M_PI * angle) / 180));
}

void		init_keys(t_keys *keys)
{
	keys->d = 0;
	keys->a = 0;
	keys->up = 0;
	keys->down = 0;
	keys->left = 0;
	keys->right = 0;
}

int main(int ac, char **av)
{
	if (ac > 1)
		load_model(av[1]);
	// Notre fenêtre

	SDL_Window	*win;
	SDL_Event	events;
	SDL_GLContext openglcontext;	
	int			terminate = 0;

	//init SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Erreur d'initialisation de la sdl\n");
		SDL_Quit();

		return (-1);
	}

	// OPENGL VERSION
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	// Double buffer On
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	// Création de la fenêtre
	win = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	if (win == 0)
	{
		printf("Erreur lors de la creation de la fenetre\n");
		SDL_Quit();
		return (-1);
	}

	// Attacher fenetre a opengl
	openglcontext = SDL_GL_CreateContext(win);
	if (openglcontext == 0)
	{
		printf("Erreur lors de la creation du contexte opengl\n");
		SDL_DestroyWindow(win);
		SDL_Quit();

		return (-1);
	}
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	//mesh
	t_mesh	pyramide;
	//vertex
	GLfloat g_vertex_buffer_data[] = {
		-1.0f,-1.0f,-1.0f, // triangle 1 : begin
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f, // triangle 1 : end
	};
	pyramide.world_position = init_vector(1, 0, 0);
	pyramide.angle = init_vector(0, 0, 0);
	pyramide.scale = 0.5;
	pyramide.vtx = g_vertex_buffer_data;
	pyramide.vertex_count = sizeof(g_vertex_buffer_data) / sizeof(GLfloat);
	printf("SIZE : %d\n", pyramide.vertex_count);
	glGenBuffers(1, &pyramide.vertexbuffer);
	//colors
	GLfloat g_color_buffer_data[] = {
	0.583f,  0.771f,  0.014f,
    0.609f,  0.115f,  0.436f,
    0.327f,  0.483f,  0.844f,
	};
	pyramide.colors = g_color_buffer_data;
	glGenBuffers(1, &pyramide.colorbuffer);
	//load shaders
	GLuint programID = loadshader( "vertex_shader.vertexshader", "FragmentShader.fragmentshader" );
	//TEST MATRIX
	matrix mtx;
	//FIN TEST
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// // Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);
	GLuint ModelMatrices[2];
	ModelMatrices[0] = glGetUniformLocation(programID, "SCALE");
	ModelMatrices[1] = glGetUniformLocation(programID, "TRANS");
	GLuint ProjectionMatrix;
	ProjectionMatrix = glGetUniformLocation(programID, "PROJECTION");
	GLuint ViewMatrix;
	ViewMatrix = glGetUniformLocation(programID, "VIEW");
	t_keys keys;
	init_keys(&keys);
	while (!terminate)
	{	
		glUseProgram(programID);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		draw_mesh(pyramide, ModelMatrices, ProjectionMatrix, ViewMatrix);	
		//refresh
		SDL_GL_SwapWindow(win);
		SDL_PollEvent(&events);
		if (events.window.event == SDL_WINDOWEVENT_CLOSE)
			terminate = 1;
		if (events.type == SDL_KEYDOWN)
		{
			if (events.key.keysym.sym == 27)
				terminate = 1;
		}
		const Uint8 *state = SDL_GetKeyboardState(NULL);
		if (state[SDL_SCANCODE_UP])
		{
			create_rx_matrix(mtx, 1);
			transform_model(pyramide.vtx, mtx, pyramide.vertex_count);
		}
		if (state[SDL_SCANCODE_DOWN])
		{
			create_rx_matrix(mtx, -1);
			transform_model(pyramide.vtx, mtx, pyramide.vertex_count);
		}
		if (state[SDL_SCANCODE_RIGHT])
		{
			create_ry_matrix(mtx, 1);
			transform_model(pyramide.vtx, mtx, pyramide.vertex_count);
		}
		if (state[SDL_SCANCODE_LEFT])
		{
			create_ry_matrix(mtx, -1);
			transform_model(pyramide.vtx, mtx, pyramide.vertex_count);
		}
		if (state[SDL_SCANCODE_D])
			pyramide.world_position.x += 0.02;
		if (state[SDL_SCANCODE_A])
			pyramide.world_position.x -= 0.02;
		if (state[SDL_SCANCODE_W])
			pyramide.world_position.y += 0.02;
		if (state[SDL_SCANCODE_S])
			pyramide.world_position.y -= 0.02;
	}

	// On quitte la SDL
	SDL_GL_DeleteContext(openglcontext);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return (0);
}
